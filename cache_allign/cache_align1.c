#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <glib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define REAL_SIZE	20
#define MESSAGE_SIZE	20
#define NUM_OF_CPUS	4
#define CACHE_LINE	64

volatile unsigned long dispatchCounter=0;
volatile unsigned long workerCounter[2]={0};

unsigned int sum[2]={0};

GAsyncQueue* queue;

void* thread_print(void* data){
	unsigned long numOfMsgs[6]={0};
	while(1){	
		sleep(5);
		numOfMsgs[3]=dispatchCounter;
		printf("dispatch thread read %lu messages/s\n",(numOfMsgs[3]-numOfMsgs[0])*REAL_SIZE/5);
		numOfMsgs[0]=numOfMsgs[3];
		numOfMsgs[4]=workerCounter[0];
		printf("worker thread1 read %lu messages/s\n",(numOfMsgs[4]-numOfMsgs[1])*REAL_SIZE/5);
		numOfMsgs[1]=numOfMsgs[4];
		numOfMsgs[5]=workerCounter[1];
		printf("worker thread2 read %lu messages/s\n\n",(numOfMsgs[5]-numOfMsgs[2])*REAL_SIZE/5);
		numOfMsgs[2]=numOfMsgs[5];
	}
	return NULL;
}

void* thread_dispatch(void* data){
	const int do_malloc=1;
	const int number_of_messages=100000;
	char* messages;
	char* current_message;
	int increment;
	if(do_malloc) {
		messages=malloc(number_of_messages*MESSAGE_SIZE);
		if(messages==NULL) {
			perror("myapp\n");
			exit(1);
		}
		increment=MESSAGE_SIZE;
	} else {
		int ret=posix_memalign((void**)&messages, CACHE_LINE, number_of_messages*CACHE_LINE);
		if(ret){
			perror("myapp\n");
			exit(1);
		}
		increment=CACHE_LINE;
	}
	current_message=messages;
	int msg_num=0;
	ssize_t read_ret_val, my_data;
        int fd = open("/dev/urandom", O_RDONLY);
	g_async_queue_ref(queue);
	while(1) {
		char* ptr=current_message;
		my_data=0;
		do {
	        	read_ret_val=read(fd, ptr, MESSAGE_SIZE-my_data);
			my_data+=read_ret_val;
			ptr+=read_ret_val;
		}while(my_data<MESSAGE_SIZE);
		g_async_queue_push(queue, current_message);
		__sync_fetch_and_add( &dispatchCounter, 1);

		// handle the cyclic buffer
		msg_num++;
		msg_num%=number_of_messages;
		if(msg_num!=0) {
			current_message+=increment;
		} else {
			current_message=messages;
		}
	}
	g_async_queue_unref(queue);
        close(fd);
	return NULL;
}

void* thread_worker(void* data){
	void* rcvMsg;
	size_t i;
	int j=*(int*)data;
	//unsigned int sum=0;
	unsigned char c=0;
	g_async_queue_ref (queue);
	while(1) {
		rcvMsg=g_async_queue_pop(queue);
		for(i=0;i<REAL_SIZE;i++){
			(*((unsigned char*)rcvMsg+i))++;
		}
		for(i=0;i<REAL_SIZE;i++){
			(*((unsigned char*)rcvMsg+i))-=2;
		}
		for(i=0;i<REAL_SIZE;i++){
			c=*((unsigned char*)rcvMsg+i);
			sum[j]+=(unsigned int)c;
		}
		sum[j]=0;
		free(rcvMsg);
		__sync_fetch_and_add(&workerCounter[j], 1);
	}
	g_async_queue_unref(queue);
	return NULL;
}



int main(int argc, char** argv){
	int i;
	int myWT1=0;
	int myWT2=1;
	pthread_t dispatch_thread,process1,process2,print_thread;
	pthread_attr_t attrs[NUM_OF_CPUS];
	cpu_set_t cpuset[NUM_OF_CPUS];
	queue=g_async_queue_new();
	for(i=0;i<NUM_OF_CPUS;i++){
		CPU_ZERO(cpuset+i);
		CPU_SET(i, cpuset+i);
		pthread_attr_init(attrs + i);
		pthread_attr_setaffinity_np(attrs + i, sizeof(cpu_set_t), cpuset + i);
	}
	pthread_create(&dispatch_thread, attrs+1, thread_dispatch,NULL);
	pthread_create(&process1, attrs+2, thread_worker, &myWT1); 
	pthread_create(&process2, attrs+3, thread_worker, &myWT2);
	pthread_create(&print_thread, attrs, thread_print, NULL);
	pthread_join(dispatch_thread, NULL); 
	pthread_join(process1, NULL); 
	pthread_join(process2, NULL);
	pthread_join(print_thread, NULL); 
	g_async_queue_unref(queue);	
	return 0;
}
























