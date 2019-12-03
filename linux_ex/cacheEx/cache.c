#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*#define ARR_SIZE 8388608 */
#define ARR_SIZE 100000000

int main(int argc , char** argv){
	unsigned int* arr;
	long i,j;
	long window;
	long int sum=0;
	/* srand(time(NULL)); */
	if(argc!=2)
		return EXIT_FAILURE;
	window=atoi(argv[1]);
	if(window<0 || window>ARR_SIZE)
		return EXIT_FAILURE;
	arr=(unsigned int*)malloc(ARR_SIZE*sizeof(unsigned int));
	for(i=0;i<ARR_SIZE;i++){
		arr[i]=i;
	}
	if(window==0) {
		for(i=0;i<ARR_SIZE;i++){
			arr[i]++;
		}
		for(i=0;i<ARR_SIZE;i++){
			arr[i]=arr[i]/2;
		}
		for(i=0;i<ARR_SIZE;i++){
			arr[i]*=arr[i];
		}
	} else {
		for(i=0;i<ARR_SIZE;i+=window){
			int limit = i+window;
			if (limit>=ARR_SIZE) {
				limit=ARR_SIZE;
			}
			for(j=i; j<limit; j++){
				arr[j]++;
				arr[j]=arr[j]/2;
				arr[j]*=arr[j];
				/*arr[j]=((arr[j]+1)/2)*arr[j];*/	
			}
		}	
	}
	/* calculate and print sum */
	for(i=0;i<ARR_SIZE;i++) {
		sum+=arr[i];
	}
	printf("sum is %ld\n", sum);
	return EXIT_SUCCESS;
}




















