#include <stdio.h>
#include <stdlib.h>
#include "da.h"

int main(){
	DA_t* array;
	intPtr num;
	if(array=createDA(2)){
		do{
			printf("enter integer:\n");
			num=(intPtr)malloc(sizeof(int));
			scanf("%d",num);
			if(!insert(array,num)){
				printf("failed to allocate memory \n");
			}
		}while(*num>=0);
	}
	printDA(array);
	destroyDA(array);
	return 0;
}
