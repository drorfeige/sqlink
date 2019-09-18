#define _POSIX_C_SOURCE 200000L
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


static void prI(int sig, siginfo_t* siginfo, void* context){
	static count=0;
	char buffer[16]="";
	if(count>=3){
		exit(0);
	}
	count++;
	sprintf(buffer, "%d", siginfo->si_uid);
	strcat(buffer,"\n");
	write(1,"\n",2);
	write(1,buffer,16);
}





int main(){
	struct sigaction notKill;
	/*memset (&notKill, '\0', sizeof(struct sigaction));*/
	notKill.sa_sigaction =&prI;
	notKill.sa_flags = SA_SIGINFO;
	if (sigaction(SIGINT, &notKill, NULL) < 0) {
		perror ("sigaction");
		return 1;
	}
	while (1){
		sleep (3600);
	}
	return 0;
}










