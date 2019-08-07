#include <stdio.h>

void getArr(int* arr, int size);
void sortAscendingArr(int* arr, int size);
void printArr(int* arr, int size);
void swap(int* x, int* y);

int main(){
	int size=6;
	int arr[6]={0};
	getArr(arr,size);
	printArr(arr,size);
	sortAscendingArr(arr,size);
	printf("the sorted array is\n");
	printArr(arr,size);

	return 0;
}

void getArr(int* arr, int size){
	int i=0;
	printf("choose 6 intergers:\n");
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

void sortAscendingArr(int* arr, int size){
	int i=0, swpN=1;
	while(swpN){
		swpN=0;
		for (i=0;i<size-1; i++){
			if(arr[i]>arr[i+1]){
				swpN++;
				swap(arr+i,arr+i+1);
			}
		}
	}
}

void swap(int* x, int* y){
	int temp;
	temp =*x;
	*x=*y;
	*y=temp;

}

