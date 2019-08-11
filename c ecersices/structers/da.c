#include <stdlib.h>
#include <stdio.h>
#include "da.h"



DA* createDA(int Capacity){
	DA* newSt;
	newSt=(DA*)malloc(sizeof(DA));
	if(newSt){
		newSt->capacity=Capacity;
		newSt->index=0;
		newSt->arr=(int*)malloc(Capacity*sizeof(int));
	}
	return newSt;
}
void destroyDA(DA* array){
	free(array->arr);
	free(array);
}
int insert(DA* array,int num){
	int* temp;
		if(array==NULL){
		return 0;
	}
	if ((array->index)==(array->capacity)){
		temp=array->arr;
		array->arr=realloc(array->arr,(array->capacity)*2*sizeof(int));
		if (array->arr){
			array->capacity=(array->capacity)*2;
		}
		else{
			array->arr=temp;
			return 0;
		}	
	}
	array->arr[array->index++]=num;
	return 1;
}
void printDA(DA* array){
	int i=0;
	if(array){
		if(array->arr){
				while(i<array->index){
					printf("%d ",array->arr[i++]);
				}
				printf("\n");
		}
	}
}


