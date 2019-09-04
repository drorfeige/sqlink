#include "free.h"

#define FOUR_DOWN(x) (x&0xfffffffffffffffc)
#define FOUR_UP(x) ((x&0x0000000000000003)==0? x:1+(x|0x0000000000000003)) 
#define BLOCK_SIZE(x) (x&0x7fffffffffffffff)
#define IS_FREE(x) (x&0x8000000000000000)
#define SET_FREE(x) (x&0x7fffffffffffffff)
#define SET_ALLOCATED(x) (x|8000000000000000)

void* memInit(void* buffer,unsigned int size){
	unsigned int* begin;
	unsigned int* end;
	long temp=0;
	long temp2=0;	
	if(buffer==0 || size<2){
		return 0;
	}	
	begin=(unsigned int*)buffer;
	end=(unsigned int*)buffer+(size/4);
	begin=(unsigned int*)FOUR_UP((long)begin);
	end=(unsigned int*)FOUR_DOWN((long)end);
	temp2=(((long)end-(long)begin-1));
	temp=SET_FREE(temp2);
	*begin=temp;
	begin[temp]=0; 
	return (void*)begin;	
}

void* memAlloc(void* buffer,unsigned int size){
	long toAllocate=0;
	long blockSize=0;
	unsigned int* arr=(unsigned int*)buffer;
	if(buffer==0){
		return 0;
	}
	toAllocate=FOUR_UP(((long)size/4))+1;
	blockSize=BLOCK_SIZE(arr[0]);
	while(arr[0]!=0){
		if((IS_FREE(arr[0]))==0){
			while(IS_FREE(*(arr+blockSize))==0 && arr[0]!=0){
				blockSize+=BLOCK_SIZE(*(arr+blockSize));
				arr[0]=SET_FREE(blockSize);	
			}
			if(blockSize>=toAllocate){
				if(blockSize-toAllocate>=2){
					*(arr+toAllocate)=SET_FREE((blockSize-toAllocate));
				}
				else{
					toAllocate=blockSize;
				}
				arr[0]=SET_ALLOCATED(toAllocate);
				return (void*)(arr+1);
			}
		}
		arr=arr+blockSize;
		blockSize=BLOCK_SIZE(arr[0]);
	}
	return 0;	
}

void memFree(void* buffer){
	unsigned int* toFree=(unsigned int*)buffer;
	long blockSize=0;
	unsigned int* arr=(unsigned int*)buffer;
	if(buffer==0){
		return ;
	}
	blockSize=BLOCK_SIZE(arr[0]);
	while(IS_FREE(*(arr+blockSize))==0 && arr[0]!=0){
		blockSize+=BLOCK_SIZE(*(arr+blockSize));
		arr[0]=blockSize;			
	}
	toFree[0]=SET_FREE(blockSize);
}







