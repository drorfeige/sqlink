#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#define MAX_NAME	128
#define MAX 	4096 
#define PORT 	8080 
#define SA struct 	sockaddr 



const char* reply="HTTP/1.1 200 OK\n" \
"Date: Mon, 27 Jul 2009 12:28:53 GMT\n" \
"Server: Apache/2.2.14 (Win32)\n" \
"Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT\n" \
"Content-Type: text/html\n" \
"Connection: Closed\n" \
"\n"; 

// Function designed for chat between client and server. 
void func(int myConnFd) 
{
	int connFd=myConnFd;
	char fs_name[MAX_NAME] =""; //"/home/sqrt/sqlink/web_server/foobar.html";
	char sdbuf[MAX]; // Send buffer
	int ret; 
	int writeC=0;
    	char buff[MAX];  
        ret=read(connFd, buff, sizeof(buff));
	buff[ret]=0;
        printf("From client:");
	printf("%s\t",buff);
	bzero(sdbuf, MAX);
	int i;
	for(i=5;buff[i]!=' ';i++)
	{
		if(i>=MAX_NAME-5)
		{
			fprintf(stderr, "ERROR: File name too long\n");
			exit(1);	
		}
		fs_name[i-5]=buff[i];	
	}
	fs_name[i-5]='\0';
	FILE *fs = fopen(fs_name, "r");
	if(fs == NULL)
	{
		fprintf(stderr, "ERROR: File %s not found on server. (errno = %d)\n", fs_name, errno);
		exit(1);
	}
	while(writeC<sizeof(reply))
	{ 
        	writeC+=write(connFd, reply, strlen(reply));
	}
	int fs_block_sz;
	while((fs_block_sz = fread(sdbuf, sizeof(char), MAX, fs))>0)
	{
		writeC=0;
		while(writeC<fs_block_sz)
		{ 
        		writeC+=write(connFd, sdbuf, fs_block_sz-writeC);
		}
		bzero(sdbuf, MAX);
	}
	close(connFd); 
} 

void* serveInThread(void* data){
	func(*(int*)data);
	return NULL;
}  
// Driver function 
int main() 
{ 
	int sockfd, connfd;
	unsigned int len; 
	struct sockaddr_in servaddr, cli; 
	pthread_t* tid;  
    // socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
        	printf("socket creation failed...\n"); 
        	exit(0); 
    	} 
    	else
        	printf("Socket successfully created..\n"); 
    	bzero(&servaddr, sizeof(servaddr)); 
  
    // assign IP, PORT 
    	servaddr.sin_family = AF_INET; 
    	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    	servaddr.sin_port = htons(PORT); 
  
    // Binding newly created socket to given IP and verification 
    	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        	printf("socket bind failed...\n"); 
        	exit(0); 
    	} 
    	else
        	printf("Socket successfully binded..\n"); 
  
    // Now server is ready to listen and verification 
    	if ((listen(sockfd, 1024)) != 0) { 
        	printf("Listen failed...\n"); 
        	exit(0); 
    	} 
    	else
        	printf("Server listening..\n"); 
    	len = sizeof(cli); 
  
    // Accept the data packet from client and verification
	while(1){ 
    		connfd= accept(sockfd, (SA*)&cli, &len); 
    		if (connfd < 0) { 
        		printf("server acccept failed...\n"); 
        		exit(0); 
    		} 
    		else
        		printf("server acccept the client...\n"); 

		tid=(pthread_t*)malloc(sizeof(pthread_t));
		if(!tid)
		{
			printf("memory allocation error\n");
			exit(1);
		}
		pthread_create( tid, NULL, serveInThread, (void*)&connfd);
		pthread_detach( *tid); 
	} 
    // After chatting close the socket 
    	close(sockfd); 
} 

