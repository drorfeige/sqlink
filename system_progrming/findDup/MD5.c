#include "MD5.h"
#include <openssl/md5.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>







int MD5Create(char* path, char* hashKey){
	MD5_CTX c;
	char buf[512];
	ssize_t bytes;
	int fd;
	fd= open(path, O_RDONLY);
	if(fd < 0){
		return 0;
	}
	MD5_Init(&c);
	bytes=read(fd, buf, 512);
	while(bytes > 0)
	{
		MD5_Update(&c, buf, bytes);
	        bytes=read(fd, buf, 512);
	}
	MD5_Final((unsigned char*)hashKey, &c);
	return 1;
}



