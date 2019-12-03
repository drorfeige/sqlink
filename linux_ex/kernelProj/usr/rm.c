#include "../msgq.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdlib.h>

int main(int argc, char** argv){
	int fileD;
	char* recieve; 
	int err;
	if(argc!=2){
		printf("wrong number of arguments\n");
		return  1; 
	}
	if((fileD=open(argv[1],O_RDWR))==-1){
		printf("wrong file name\n");
		return 1;
	}
	recieve=(char*)malloc(MAX_MESSAGE);
	if(!(recieve)){
		printf("error allocating memory\n");
		return 1;
	}
	if(((err=ioctl(fileD,RECIEVE_MESSAGE,&recieve))==-1)){
		free(recieve);
		printf("error putting message in q");
		return -1;
	}
	printf("%.*s",err,recieve);
	free(recieve);
	return 0;
}













