#include <stdio.h>
#include "free.h"

unsigned int arr[1048576];
void* InitTest();
void allocTest1();

int main(){
	InitTest();
	allocTest1();
	return 0;
}

void* InitTest(){
	void* arrPtr;
	arrPtr=memInit((void*)((char*)arr+1),(unsigned int) sizeof(arr));
	if(arrPtr==0){
		printf("failed to create array\n");
		return 0;
	}
	if(((long)arrPtr)%4){
		printf("wrong header\n");
		return 0;
	}
	printf("memInit passed two initial tests\n");
	return arrPtr;
}

void allocTest1(){
	void* arrPtr;
	unsigned int* ptr1;
	arrPtr=InitTest();
	if(arrPtr==0){
		printf("failed to create array\n");
		return;
	}
	ptr1=(unsigned int*)memAlloc(arrPtr, 2046);
	if(ptr1==0){
		printf("failed to allocate memory\n");
		return;
	}
	ptr1[1000]=27;
}


















