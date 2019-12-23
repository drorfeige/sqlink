#include <stdio.h>	// for printf
#include <stdlib.h>	// for EXIT_SUCCESS
#include <time.h>	// for clock_gettime(2), clock_nanosleep(2)
#include <sched.h>	// for sched_setscheduler(2), struct sched_param
#include <sys/mman.h>	// for mlockall(2)
/*#include <err_utils.h>	// for CHECK_NOT_M1()
#include <timespec_utils.h>	// for timespec_add_nanos()*/

/* TODO:
 * - show that this app does not do any page faults. Do this by not having
 * it do an infinite loop and just looking at it's page faults. Or maybe
 * printing it's page faults while it is running?
 */

/*
 * we use 49 as the PREEMPT_RT linux kernel patch uses 50 as the priority of
 * kernel tasklets and interrupt handlers by default
 */
void printT(unsigned long long maxT){
	printf("the biggest latency is %llu\n", maxT);
}

int main(int argc, char** argv, char** envp) {
	if(argc!=3){
		printf("wrong number of arguments\n");
		return EXIT_FAILURE;
	}
	/* Declare ourself as a real time task */
	struct sched_param param;
	param.sched_priority=atoi(argv[1]);
	if(sched_setscheduler(0, SCHED_FIFO, &param)==-1){
		printf("failed to set scheduler\n");
		return EXIT_FAILURE;
	}
	/* Lock memory */
	if(mlockall(MCL_CURRENT|MCL_FUTURE)==-1){
		printf("error locking pages\n");
	}
	/* get the current time */
	int nInt=atoi(argv[2]);
	struct timespec newT;
	struct timespec interval;
	interval.tv_sec=0;
	interval.tv_nsec=nInt;
	clockid_t clk_id=CLOCK_BOOTTIME;
	unsigned long long max=0;
	while(1){
		struct timespec t;
		if(clock_gettime(clk_id, &t)==-1){
			printf("error getting time\n");
			return EXIT_FAILURE;
		}
		/* wait untill next shot */
		if(nanosleep(&interval, NULL)==-1){
			printf("error going to sleep\n");
			return EXIT_FAILURE;
		}
		if(clock_gettime(clk_id, &newT)==-1){
			printf("error getting time\n");
			return EXIT_FAILURE;
		}
		unsigned long long diffT=((newT.tv_sec-t.tv_sec)*1000*1000*1000)+newT.tv_nsec-t.tv_nsec;
		if(diffT>max){
			max=diffT;
			printT(max);
		}				
	}
	return EXIT_SUCCESS;
}



