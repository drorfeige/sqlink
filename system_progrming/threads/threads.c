#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

/*create 2 threads from the same function. the function Thread calls a function called increment. main calls increment with the adress of count.create 100 threads in a loop*/

/*create an x amount of threads. for each thread i want to give an id*/

#define MAX 100
int count=0;
int flag=0;
sem_t mutex;

void increment(int* c){
	int Count=*c;
	Count++;
	*c=Count;
}

void* threadInc(){
	increment(&count);
	flag=0;
}

void* printID(void* id){
	printf("%d \n",*(int*)id);
	sem_post(&mutex);
	/*flag=0;*/
}	


int main(){
	pthread_t tid[MAX]; 
	int i=0;
	int j=0;
	sem_init(&mutex, 0, 1);
	for(i=0;i<MAX;i++){
		/*flag=1;*/
		sem_wait(&mutex);	
		pthread_create(&tid[i], NULL, printID, &i);
		/*while(flag){
		}*/
	}
	for(j=0;j<MAX;j++){
		pthread_join(tid[j], NULL);
	}
	sem_destroy(&mutex);
	return 0;
}













