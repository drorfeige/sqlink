#include "darray_int.h"
#include <stdlib.h>
#include <stdio.h>

struct darray{ 
	int m_initial_capacity;
	int m_capacity;
	int m_index;
	int* m_Arr;

};



AdtStatus darrayCreate(darray** dArr, size_t initial_capacity){
	darray* da;
	da=(darray*)malloc(sizeof(darray));
	if(da){
		if((da->m_Arr=(int*)malloc(initial_capacity*sizeof(int)))!=NULL){
			da->m_capacity=initial_capacity;
			da->m_initial_capacity=initial_capacity;
			da->m_index=0;
			*dArr=da;
		}
		else{
			free(da);
			return AllocationError;
		}
	}
	else{
		return AllocationError;
	}
	return OK;
}

AdtStatus darrayDestroy(darray *dArr){
	if(dArr!=NULL){
		if(dArr->m_Arr!=NULL){
			free(dArr->m_Arr);
		}
		free(dArr);
		return OK;
	}
	return AllocationError;
}

AdtStatus   darrayAdd(darray *dArr,  int  _item){
	int* temp;
	/**********************check pointers are not void*********************/
	if(dArr==NULL){
		return NULL_POINTER;
	}
	if(dArr->m_Arr==NULL){
		return NULL_POINTER;
	}
	/**************check if we need to realloc*************************/
	if ((dArr->m_index)==(dArr->m_capacity)){
		temp=dArr->m_Arr;
		dArr->m_Arr=realloc(dArr->m_Arr,(dArr->m_capacity)*2*sizeof(int));
		if (dArr->m_Arr!=NULL){
			dArr->m_capacity*=2;
		}
		else{
			dArr->m_Arr=temp;
			return AllocationError;
		}
	}
	dArr->m_Arr[dArr->m_index++]=_item;
	return OK;
}

AdtStatus   darrayGet(darray *dArr, size_t _index, int *_item){
	/*check for errors*/
	if(dArr==NULL || _item==NULL){
		return NULL_POINTER;
	}
	if(dArr->m_Arr==NULL){
		return NULL_POINTER;
	}
	if(_index>dArr->m_index){
		return INVALID_INDEX;
	}
	/*get*/
	*_item=dArr->m_Arr[_index];
	return OK;
}

AdtStatus   darraySet(darray *dArr, size_t _index, int  _item){
		/*check for errors*/
	if(dArr==NULL){
		return NULL_POINTER;
	}
	if(dArr->m_Arr==NULL){
		return NULL_POINTER;
	}
	if(_index>dArr->m_index){
		return INVALID_INDEX;
	}
	/*set*/
	dArr->m_Arr[_index]=_item;
	return OK;
}

AdtStatus   darrayItemsNum(darray *dArr, int*  _numOfItems){
		/*check for errors*/
	if(dArr==NULL || _numOfItems==NULL){
		return NULL_POINTER;
	}
	if(dArr->m_Arr==NULL){
		return NULL_POINTER;
	}
	/*return index*/
	*_numOfItems=dArr->m_index;
	return OK;
}

AdtStatus   darrayDelete(darray *dArr,  int* _item){
	int* temp;	
	/*check for errors*/	
	if(dArr==NULL || _item==NULL){
		return NULL_POINTER;
	}
	if(dArr->m_Arr==NULL){
		return NULL_POINTER;
	}
	/*check if we need to realloc*/
	if(dArr->m_index<dArr->m_capacity*3/8 && dArr->m_capacity>=dArr->m_initial_capacity ){
		temp=dArr->m_Arr;
		dArr->m_Arr=realloc(dArr->m_Arr,dArr->m_capacity/2*sizeof(int));
		if (dArr->m_Arr!=NULL){
			dArr->m_capacity/=2;
		}
		else{
			dArr->m_Arr=temp;
			return AllocationError;
		}
	}
	*_item=dArr->m_Arr[dArr->m_index-1];
	dArr->m_index--;
	return OK;
}


static void swap(int* x, int* y){
	int temp;
	temp =*x;
	*x=*y;
	*y=temp;

}
AdtStatus darraySort(darray *dArr){
	int i=0, swpN=1;
	if(dArr==NULL){
		return NULL_POINTER;
	}
	if(dArr->m_Arr==NULL){
		return NULL_POINTER;
	}
	while(swpN){
		swpN=0;
		for (i=0;i<dArr->m_index-1; i++){
			if(dArr->m_Arr[i]>dArr->m_Arr[i+1]){
				swpN++;
				swap(dArr->m_Arr+i,dArr->m_Arr+i+1);
			}
		}
	}
	return OK;
}



