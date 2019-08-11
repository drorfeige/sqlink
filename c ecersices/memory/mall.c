#include <stdio.h>
#include <stdlib.h>

int* insert(int* arr,int num, int* pindex, int* capacity);
void insertAltr(int** arr,int num,int* index, int* capacity);
void printarr(int* arr,int* index);

int main(){
	int capacity=4;
	int* pcap=&capacity;
	int index=0;
	int* pindex=&index;
	int num=0;
	int* arr= (int*)malloc(capacity*(sizeof(int)));
	int* temp;
	while (num>=0){
		printf("enter integer:\n");
		scanf("%d",&num);
		temp=arr;
		arr=insert(arr,num,pindex,pcap);
		if(arr){
			printarr(arr,pindex);
		}
		else{
			printf("failed to allocate memory \n");
			arr=temp;
		}

	}
	free(arr);
	free(temp);
	return 0;
}

int* insert(int* arr,int num,int* pindex, int* capacity){
	if(arr==NULL){
		return NULL;
	}
	if ((*pindex)<(*capacity)){
		arr[(*pindex)++]=num;
	}
	else{
		int* temp=arr;
		arr=realloc(arr,(*capacity)*2*sizeof(int));
		if (arr){
			*capacity=(*capacity)*2;
			arr[(*pindex)++]=num;
			return arr;
		}	
	}
	return arr;
}

void printarr(int* arr,int* index){
	int i=0;
	if(!arr){
		return;
	}
	while(i<*index){
		printf("%d ",arr[i++]);
	}
	printf("\n");
}
