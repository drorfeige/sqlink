#include <stdio.h>


void getArr(int* arr, int size);
int sortEvenArr(int* arr, int size);
void printArr(int* arr, int size);
void swap(int* x, int* y);

int main(){
	int size=6;
	int arr[6]={0};
	int even=0;
	getArr(arr,size);
	printArr(arr,size);
	even=sortEvenArr(arr,size);
	printf("the number of even numbers is %d\n",even);
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
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int sortEvenArr(int* arr, int size){
	int i=0;
	int swpN=1;
	while(swpN){
		swpN=0;
		for (i=0;i<size-1;i++){
			if (arr[i]%2!=0 && arr[i+1]%2==0){
				swpN++;
				swap(arr+i,arr+i+1);
			}
		}
	}
	i=0;
	while(i<size){
		if (arr[i]%2){
			 return i;
		}
		i++;
	}
	return size;
}

void swap(int* x, int* y){
	int temp;
	temp =*x;
	*x=*y;
	*y=temp;
}


