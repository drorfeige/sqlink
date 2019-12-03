#define _POSIX_C_SOURCE 200000L
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


#define MAX_FILE_SIZE 65536
#define BUFFER_SIZE 4096
#define INT_BUFFER_SIZE 128


char* itoaB10(unsigned int val,char* recBuff){
	char* ret=recBuff;
	unsigned int i=0;
	unsigned int j=0;
	char tmp;
	while(val!=0){
		recBuff[i++]=val%10+'0';
		val=val/10;
	}
	while(j<i/2){
		tmp=recBuff[j];
		recBuff[j]=recBuff[i-j-1];
		recBuff[i-j-1]=tmp;
	}
	recBuff[i]='\0';
	return ret;
}

int main(){
	int myPipe[2];
	char buffer[BUFFER_SIZE];
	char* buffInd;
	unsigned int intBuff[INT_BUFFER_SIZE];
	int fd;
	pid_t c_pid;
	long size;
	int i=0;
	size_t ci;
	ssize_t readCount;
	ssize_t writeCount;
	if(pipe(myPipe)){
		printf("error piping\n");
		return 1;
	}
	c_pid=fork();
	if(c_pid==0){
		close(myPipe[0]);
		dup2(myPipe[1],1);
		close(myPipe[1]);
		if(execlp("./uc","./uc",NULL)==-1){
			printf("failure creating uncontrolled process\n");
			return 32;
		}
	}
	else if(c_pid>0){
		if((fd=open("garbage_collection.txt", O_WRONLY | O_CREAT,S_IRWXU))==-1){ /*  O_WRONLY |  */
			printf("error opening file\n");
			return 17;
		}
		close(myPipe[1]);
		while(1){
			readCount=read(myPipe[0],intBuff,INT_BUFFER_SIZE);
			i=0;
			ci=0;
			buffInd=buffer;
			while(readCount>0){
				itoaB10(intBuff[i],buffInd);
				while(*buffInd!='\0'){
					buffInd+=1;
				}
				ci=buffInd-buffer;
				buffInd+=1;
				readCount-=sizeof(int);
				i++;
			}
			size=lseek(fd, 0, SEEK_CUR);
			writeCount=write(fd,buffer,(MAX_FILE_SIZE-size>ci?ci:MAX_FILE_SIZE-size));
			if(lseek(fd, 0, SEEK_CUR)>=MAX_FILE_SIZE){
				lseek(fd, 0 ,SEEK_SET);
				writeCount=write(fd,buffer+writeCount,ci-writeCount);
			}			
		}
	}
	return 0;
}






















