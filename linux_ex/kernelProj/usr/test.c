#include "../msgq.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>



int main(int argc, char** argv){
	int fileD;
	char* filename;
	if(argc==2){
		filename=argv[1];
	} else {
		filename="/dev/msgq0";
	}
	fileD=open(filename,O_RDWR);
	if(fileD==-1){
		fprintf(stderr, "wrong file name\n");
		return 1;
	}
	if(ioctl(fileD,FIFO_DEBUG)==-1) {
		fprintf(stderr,"error debugging fifo\n");
		return 1;
	}
	if(close(fileD)==-1) {
		fprintf(stderr,"error closing file\n");
		return 1;
	}
	return 0;
}




















