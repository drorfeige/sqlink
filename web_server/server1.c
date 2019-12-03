#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <errno.h>
#define MAX_NAME	128
#define MAX 	4096
#define PORT 	8080
#define MAX_EVENTS 20
#define SA struct 	sockaddr


const char* response="HTTP/1.1 200 OK\n"
"Content-Type: text/html\n"
"Connection: Closed\n"
"\n"
"<html><body>Hello</body></html>";

#define MAX_FDS 10
const char* buffers_to_send_ptr[MAX_FDS];
int buffers_to_send_size[MAX_FDS];


void check_error(int val) {
	if(val==-1) {
		perror(NULL);
		exit(1);
	}
}

// Function designed for chat between client and server.
int func_in(int myConnFd)
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
	for(i=5;buff[i]!=' ' || i>MAX;i++)
	{
		if(i>=MAX_NAME-5)
		{
			strcpy(fs_name,"error.html");
			i=strlen(fs_name);
			break;	
		}
		fs_name[i-5]=buff[i];	
	}
	fs_name[i-5]='\0';
	FILE *fs = fopen(fs_name, "r");
	if(fs == NULL)
	{
		fs = fopen("error.html","r");
		if(fs==NULL)
		{
			fprintf(stderr, "ERROR: File %s not found on server. (errno = %d)\n", fs_name, errno);
			printf("failed opening requested file\n");
			exit(1);
		}
	}
	while(writeC<sizeof(response))
	{
        	writeC+=write(connFd, response, strlen(response));
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
	//close(connFd);
	return 0; // return value for future use
}

// Driver function
int main()
{
	int connfd,n;
	unsigned int len;
	struct sockaddr_in servaddr, cli;

	// socket create and verification
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	check_error(sockfd);
	printf("Socket successfully created..\n");

	int optval=1;
	check_error(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)));

    	bzero(&servaddr, sizeof(servaddr));
    	servaddr.sin_family = AF_INET;
    	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    	servaddr.sin_port = htons(PORT);

	// Binding newly created socket to given IP and verification
    	check_error(bind(sockfd, (SA*)&servaddr, sizeof(servaddr)));
	printf("Socket successfully binded..\n");

	// Now server is ready to listen and verification
	check_error(listen(sockfd, 1024));
	printf("Server listening..\n");
	len = sizeof(cli);

	int clientsPoll=epoll_create1(0);
	check_error(clientsPoll);

	struct epoll_event ev, events[MAX_EVENTS];
	int nfds;
	ev.events = EPOLLIN;
	ev.data.fd = sockfd;

	check_error(epoll_ctl(clientsPoll, EPOLL_CTL_ADD, sockfd, &ev));

	// Accept the data packet from client and verification
	while(1) {
		nfds = epoll_wait(clientsPoll, events, MAX_EVENTS, -1);
		check_error(nfds);
		for (n = 0; n < nfds; ++n)
		{
			if (events[n].data.fd == sockfd)
			{
    				connfd=accept(sockfd, (SA*)&cli, &len);
				check_error(connfd);
				printf("server acccept the client...\n");
				struct epoll_event ev;
				ev.events = EPOLLIN;
				ev.data.fd = connfd;
				check_error(epoll_ctl(clientsPoll, EPOLL_CTL_ADD, connfd,&ev));
			}
			else
			{
				/* this is a connection */
				if(events[n].events & EPOLLIN) {
					int fd=events[n].data.fd;
					/* handle in data */
					char buf[4096];
					ssize_t bytes_read=read(fd, buf, 4096);
					check_error(bytes_read);
					printf("read %ld bytes\n", bytes_read);
					struct epoll_event ev;
					ev.events = EPOLLOUT;
					ev.data.fd = fd;
					check_error(epoll_ctl(clientsPoll, EPOLL_CTL_MOD, fd, &ev));
					buffers_to_send_ptr[fd]=response;
					buffers_to_send_size[fd]=strlen(response);

				}
				if(events[n].events & EPOLLOUT) {
					/* handle out data */
					int fd=events[n].data.fd;
					ssize_t bytes_written=write(fd, buffers_to_send_ptr[fd], buffers_to_send_size[fd]);
					check_error(bytes_written);
					printf("written another %ld bytes\n", bytes_written);
					buffers_to_send_ptr[fd]+=bytes_written;
					buffers_to_send_size[fd]-=bytes_written;
					if(buffers_to_send_size[fd]==0) {
						struct epoll_event ev;
						ev.events = EPOLLOUT;
						ev.data.fd = fd;
						check_error(epoll_ctl(clientsPoll, EPOLL_CTL_DEL, fd, &ev));
						check_error(close(fd));
					}
				}
			}
		}
	}
	// After chatting close the socket
    	check_error(close(sockfd));
	return EXIT_SUCCESS;
}

