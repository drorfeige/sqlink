#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArr(int* arr, int size);
void sortAscendingArr(int* arr, int size);
void random(int* lotto, int size);
void printLotto(int* lotto,int size);
void swap(int* x, int* y);

int main(){
	int lotto[6]={0};
	int size=6;
	random(lotto, size);
	sortAscendingArr(lotto, size);
	printArr(lotto,size); /*for debugging*/
	printLotto(lotto,size);
	return 0;
}

void printArr(int* arr, int size){
	int i=0;
	for (i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void random(int* lotto, int size){
	int i=0,j=0,copy=0;
	srand(time(NULL));
	for(i=0;i<size;i++){
		
		do{
			lotto[i]=rand()%49;
			lotto[i]=lotto[i]==0?49:lotto[i];
			for (j=0;j<i;j++){
				copy=lotto[i]==lotto[j]?1:0;
			}
		}while(copy);
	}
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

void printLotto(int* lotto, int size){
	int i=0,j=0;
	for(i=1;i<50;i++){
		if(lotto[j]==i){
			printf("+");
			j++;
		}
		else{
			printf("-");
		}
		if(i%10==0){
			printf("\n");
		}
	}
	printf("\n");
}
