#include <stdio.h>
#include "da.h"


int main(){
	int num=0;
	int ins=0;
	DA* array;
	array=createDA(4);
	while(num>=0){
		printf("enter integer:\n");
		scanf("%d",&num);
		ins=insert(array,num);
		if(ins){
			printDA(array);
		}
		else{
			printf("failed to allocate memory \n");
		}
	}
	destroyDA(array);
	return 0;
}
