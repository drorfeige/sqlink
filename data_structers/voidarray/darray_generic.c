#include "darray_generic.h"
#include <stdlib.h>

struct darray{ 
	int m_initial_capacity;
	int m_capacity;
	int m_index;
	void** m_Arr;

};

AdtStatus darrayCreate(darray** dArr, size_t initial_capacity){
	darray* da;
	da=(darray*)malloc(sizeof(darray));
	if(da){
		if((da->m_Arr=(void**)malloc(initial_capacity*sizeof(void*)))!=NULL){
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

AdtStatus darrayDestroy(darray *dArr, elementDestroy destroyFunc, void *context){
	int i=0;		
	if(dArr!=NULL){
		if(dArr->m_Arr!=NULL){
			for(i=0;i<dArr->m_index;i++){
				destroyFunc(dArr->m_Arr[i],context);
			}
			free(dArr->m_Arr);
		}
		free(dArr);
		return OK;
	}
	return AllocationError;
}

AdtStatus   darrayAdd(darray *dArr,  void*  _item){
	void* temp;
	/**********************check pointers are not void*********************/
	if(dArr==NULL || _item==NULL){
		return NULL_POINTER;
	}
	if(dArr->m_Arr==NULL){
		return NULL_POINTER;
	}
	/**************check if we need to realloc*************************/
	if ((dArr->m_index)==(dArr->m_capacity)){
		temp=dArr->m_Arr;
		dArr->m_Arr=realloc(dArr->m_Arr,(dArr->m_capacity)*2*sizeof(void*));
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

AdtStatus   darrayGet(darray *dArr, size_t _index, void **_item){
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

AdtStatus   darraySet(darray *dArr, size_t _index, void  *_item){

		/*check for errors*/
	if(dArr==NULL || _item){
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

AdtStatus   darrayDelete(darray *dArr,  void **_item){
		void* temp;	
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
		dArr->m_Arr=realloc(dArr->m_Arr,dArr->m_capacity/2*sizeof(void*));
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
static void swap(void** x, void** y){
	void* temp;
	temp=*x;
	*x=*y;
	*y=temp;

}
static int partition (void** arr,int low, int high, elementCompare compareFunc){
	int i=0;
	int j=0;
	void* pivot;  
	pivot = arr[high];
	i = (low - 1); 
	for (j = low; j <= high- 1; j++){
		if (compareFunc(arr[j],pivot)<=0){
			i++;    
			swap(arr+i,arr+j);
	        }
	}
	swap(arr+i+1, arr+high);
	return i+1;
}
static void quickSort(void** arr, int low,int high, elementCompare compareFunc){
	int pi;
	if (low < high){
        pi = partition(arr, low, high,compareFunc);
        quickSort(arr, low, pi - 1,compareFunc); 
        quickSort(arr, pi + 1, high,compareFunc); 
    }
}

AdtStatus darraySort(darray *dArr, elementCompare compareFunc){
	
	if(compareFunc==NULL || dArr==NULL){
		return NULL_POINTER;
	}
	if(dArr->m_Arr==NULL){
		return NULL_POINTER;
	}
	quickSort( dArr->m_Arr, 0, dArr->m_index-1, compareFunc);
	return OK;
}









