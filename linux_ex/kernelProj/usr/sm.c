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
	my_msg_t my_m;
	int length;
	if(argc!=3){
		fprintf(stderr, "wrong number of arguments\n");
		return  1; 
	}
	fileD=open(argv[1],O_RDWR);
	if(fileD==-1){
		fprintf(stderr, "wrong file name\n");
		return 1;
	}
	my_m.m_data=argv[2];
	length=strlen(argv[2]);
	my_m.m_size=length>MAX_MESSAGE?MAX_MESSAGE:length;
	if(ioctl(fileD,SEND_MESSAGE,&my_m)==-1) {
		fprintf(stderr,"error putting message in q\n");
		return 1;
	}
	if(close(fileD)==-1) {
		fprintf(stderr,"error closing file\n");
		return 1;
	}
	return 0;
}




















