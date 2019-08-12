#include <stdio.h>
#include <stdlib.h>
#include "da.h"

DA_t* createDA(int Capacity){
	DA_t* newSt;
	newSt=(DA_t*)malloc(sizeof(DA_t));
	if(newSt){
		newSt->index=0;
		if(newSt->arr=(intPtr*)malloc(Capacity*sizeof(intPtr))){
			newSt->capacity=Capacity;
		}
		else{
			newSt->capacity=0;
		}
	}
	return newSt;
}
int insert(DA_t* array,intPtr Num){
	intPtr* temp;
	if(array==NULL || Num==NULL){
		return 0;
	}
	if ((array->index)==(array->capacity)){
		if(array->arr==NULL){
			if(array->arr=(intPtr*)malloc(2*sizeof(intPtr))){
				array->capacity=2;
			}
			else{
				return 0;
			}
		}
		else{
			temp=array->arr;
			array->arr=realloc(array->arr,(array->capacity)*2*sizeof(intPtr));
			if (array->arr){
				array->capacity*=2;
			}
			else{
				array->arr=temp;
				return 0;
			}
		}	
	}
	array->arr[array->index++]=Num;
	return 1;
}
void printDA(DA_t* array){
	int i=0;
	if (array){
		if(array->arr){
			for(i=0;i<array->index;i++){
				printf("%d ",*(array->arr[i]));
			}
			printf("\n");
		}
	}
	}
void destroyDA(DA_t* array){
	int i=0;
	if(array){
		if(array->arr){
			for(i=0;i<array->index;i++){
					free(array->arr[i]);
			}
			free(array->arr);
		}
		free(array);
	}
}	





