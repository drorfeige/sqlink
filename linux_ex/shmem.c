#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>



void* create_shared_memory(size_t size) {
	// Our memory buffer will be readable and writable:
	int protection = PROT_READ | PROT_WRITE;

	// The buffer will be shared (meaning other processes can access it), but
	// anonymous (meaning third-party processes cannot obtain an address for it),
	// so only this process and its children will be able to use it:
	int visibility = MAP_SHARED | MAP_ANONYMOUS;

	// The remaining parameters to `mmap()` are not important for this use case,
	// but the manpage for `mmap` explains their purpose.
	return mmap(NULL, size, protection, visibility, -1, 0);
}

int main(){
	int pid; 
	unsigned long* shmem = (unsigned long*)create_shared_memory(sizeof(unsigned long));
	*shmem=0;
	pid = fork();
	if (pid == 0) {
		while(1){
			*shmem+=1;
			sleep(1);
		}
	} 
	else {
		while(1){
			sleep(1);
			printf("time is: %lu s\n", *shmem);
		}
	}
	return 0;
}






















