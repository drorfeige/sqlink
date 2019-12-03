#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(){
	int i;
	int* ptr=NULL;
	srand(time(NULL));
	i=rand()%30;
	printf("%d\n",i);
	if(i>5){
		*ptr=i;	
	}
	return 0;
}








