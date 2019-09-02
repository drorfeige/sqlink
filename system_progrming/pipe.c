#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>


int main(){
	pid_t cpid=0;
	pid_t pid=0;
	size_t count=10;
	ssize_t numOfBytesRead;
	char hi[4]="Hi";
	char bye[4]="Bye";
	char recieveBuff[16];
	int pipeArr[2];
	pipe(pipeArr);
	pid=getpid();
	cpid=fork();
	if(cpid==0){
		write(pipeArr[1],hi,count);
		waitpid(pid,NULL,0);
		numOfBytesRead=read(pipeArr[0], recieveBuff,count);
		recieveBuff[numOfBytesRead]='\0';
		printf("%s\n",recieveBuff);
	}
	else{
		numOfBytesRead=read(pipeArr[0], recieveBuff,count);
		recieveBuff[numOfBytesRead]='\0';
		printf("%s\n",recieveBuff);
		write(pipeArr[1],bye,count);
	}
	return 0;
}
	





