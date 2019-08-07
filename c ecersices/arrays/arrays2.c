#include <stdio.h>


void getArr(int* arr, int size);
void sortArr(int* arr, int size);
void printArr(int* arr, int size);

int main(){
	int size=6;
	int arr[6]={0};
	getArr(arr,size);
	printArr(arr,size);
	sortArr(arr,size);
	printf("the sorted array is\n");
	printArr(arr,size);

	return 0;
}

void getArr(int* arr, int size){
	int i=0;
	printf("choose 6 intergers of value 0 or 1:\n");
	for(i=0;i<size;i++){
		scanf("%d",arr+i);
	}
}

void printArr(int* arr, int size){
	int i=0;
	for (i=0;i<size;i++){
		printf("%d",arr[i]);
	}
	printf("\n");
}

void sortArr(int* arr, int size){
	int i=0, zerocount=0;
	for (i=0;i<size;i++){
		if (arr[i]==0){
			zerocount++;
		}
	}
	for (i=0;i<zerocount;i++){
		arr[i]=0;
	}
	for (i;i<size;i++){
		arr[i]=1;
	}
}




