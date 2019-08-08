#include <stdio.h>

void getArr(int* arr, int size);
int mostArr(int* arr, int size);
void printArr(int* arr, int size);
void sortAscendingArr(int* arr, int size);
void swap(int* x, int* y);

int main(){
	int size=12;
	int arr[12]={0};
	int most=0;
	getArr(arr,size);
	printArr(arr,size);
	/*sortAscendingArr( arr, size);*/
	most=mostArr(arr, size);
	printf("the value that occured the most is %d\n",most);

	return 0;
}

void getArr(int* arr, int size){
	int i=0;
	printf("choose %d intergers:\n",size);
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
/*int mostArr(int* arr, int size){
	int i=0, maxVal=0;
	int currMax=1;
	int curr=1;
	maxVal=arr[0];
	for (i=1;i<size; i++){
		if(arr[i]==arr[i-1]){
			curr++;
			if(curr>currMax){
				currMax=curr;
				maxVal=arr[i];
			}
		}
		else{
			curr=1;
		}
	}
	return maxVal;
}*/
int mostArr(int* arr, int size){
	int i=0,j=0,max=0,most=0,currval,curr;
	for (i=0;i<size;i++){
		currval=arr[i];
		curr=1;
		for(j=i+1;j<size;j++){
			if (currval==arr[j]){
				curr++;
			}
		}
		if (curr>max){
			max=curr;
			most=currval;
		}
	}
	return most;
}

void swap(int* x, int* y){
	int temp;
	temp =*x;
	*x=*y;
	*y=temp;

}

