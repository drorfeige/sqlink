#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <time.h>


int main(){
	int eStatus=1;
	while(eStatus){
		if(fork()==0){
			printf("entered fork\n");
			nanosleep(300000000);
			if(execlp("./bd","./bd",NULL)==-1){
				printf("failed at execlp\n");
			}
			return 0;
		}
		wait(&eStatus);
	}	
	return 0;
}
















