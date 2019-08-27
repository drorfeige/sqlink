#include <stdlib.h>
#include "hash.h"




typedef struct Hash{
	int m_size;
	void** m_table;
	compareFunc m_comp;
	hashFunc m_hf;
}Hash;

typedef struct node{
	struct node* m_next;
	void* m_val;
	void* m_key;

}node;

static hashStatus FindKey(node* nd,void* key,compareFunc comp, node** former, node** current);
static void freeList(node* nd, destroyFunc des, destroyFunc des2 );

hash hashtableCreate(int size,compareFunc comp,hashFunc hf){
	hash newTable;
	void** table;
	newTable=malloc(sizeof(Hash));
	if(newTable==NULL){
		return NULL;
	}
	table=calloc(size,sizeof(void*));
	if(table==NULL){
		free(newTable);
		return NULL;
	}
	newTable->m_size=size;
	newTable->m_comp=comp;
	newTable->m_hf=hf;
	newTable->m_table=table;
	return newTable;
}


hashStatus hashtableInsert(hash hashP,void* val, void* key){
	unsigned long hashKey=0;
	int index;
	node* new=NULL;	
	if(hashP==NULL){
		return NO_TABLE;
	}
	hashKey=hashP->m_hf(key);
	index=hashKey%hashP->m_size;
	if((FindKey(hashP->m_table[index],key, hashP->m_comp,NULL ,&new))==OK){
		return ALREADY_IN_TABLE;
	}
	new=(node*)malloc(sizeof(node));
	if(new==NULL){
		return ALLOCATION_FAILED;
	}
	new->m_val=val;
	new->m_key=key;
	new->m_next=hashP->m_table[index];
	hashP->m_table[index]=new;
	return OK;
}

hashStatus hashtableUpdate(hash hashP,void* val, void* key){
	unsigned long hashKey=0;
	int index;
	node* new=NULL;	
	if(hashP==NULL){
		return NO_TABLE;
	}
	hashKey=hashP->m_hf(key);
	index=hashKey%hashP->m_size;
	if((FindKey(hashP->m_table[index],key, hashP->m_comp,NULL ,&new))==OK){
		new->m_val=val;
		return OK;
	}
	return NOT_IN_TABLE;
}
hashStatus FindKey(node* nd,void* key,compareFunc comp, node** former, node** current){	
	node* Former=NULL;
	hashStatus find=NOT_IN_TABLE;		
	while(nd!=NULL){
		if(!(comp(key,nd->m_key))){
			find=OK;
			if(current!=NULL){
				*current=nd;
			}
			if(former!=NULL){
				*former=Former;
			}
			break;
		}
		Former=nd;
		nd=nd->m_next;	
	}
	if(former!=NULL){
		*former=Former;
	}
	return find;
}

hashStatus  hashtableFind(hash hashP, void* key, void** item){
	unsigned long hashKey=0;
	int index;
	node* new=NULL;	
	if(hashP==NULL){
		return NO_TABLE;
	}
	hashKey=hashP->m_hf(key);
	index=hashKey%hashP->m_size;
	if((FindKey(hashP->m_table[index],key, hashP->m_comp,NULL ,&new))==OK){
		*item=(void*)(new->m_val);
		return OK;
	}
	return NOT_IN_TABLE;

}

void hashtableDestroy(hash hashP,destroyFunc des, destroyFunc des2){
	int i=0;
	void** arr;	
	if(hashP!=NULL){
		if(hashP->m_table!=NULL){
			arr=hashP->m_table;	
			for(i=0;i<hashP->m_size;i++){
				if(arr[i]!=NULL){
					freeList(arr[i],des,des2);
				}
			}	
		}
		free(hashP->m_table);
	}
	free(hashP);
}

void freeList(node* nd, destroyFunc des, destroyFunc des2 ){
	if(nd==NULL){
		return;
	}
	if(des!=NULL){
		des(nd->m_key);
	}
	if(des2!=NULL){
		des(nd->m_val);
	}
	freeList(nd->m_next,des,des2);
	free(nd);
}

hashStatus hashtableDelete(hash hashP, void* key,destroyFunc des,destroyFunc des2){
	unsigned long hashKey=0;
	int index;
	node* toDelete=NULL;
	node* Last=NULL;	
	if(hashP==NULL){
		return NO_TABLE;
	}
	hashKey=hashP->m_hf(key);
	index=hashKey%hashP->m_size;
	if((FindKey(hashP->m_table[index],key, hashP->m_comp, &Last ,&toDelete))==OK){
		if(Last!=NULL){
			Last->m_next=toDelete->m_next;
		}
		else{
			hashP->m_table[index]=toDelete->m_next;
		}
		if(des!=NULL){
			des(toDelete->m_val);
		}
		if(des2!=NULL){
			des2(toDelete->m_key);
		}
		free(toDelete);
		return OK;
	}
	return NOT_IN_TABLE;
}

hashStatus hashtableForEach(hash hashP, compareFunc someFunc){
	int i=0;
	void** arr=NULL;
	node* nd;	
	if(hashP==NULL || hashP->m_table==NULL){
		return NO_TABLE;
	}	
	arr=hashP->m_table;	
	for(i=0;i<hashP->m_size;i++){
		if(arr[i]!=NULL){
			nd=arr[i];
			while(nd!=NULL){
				if((someFunc(nd->m_val,nd->m_key))==0){
					return NOT_IN_TABLE;
				}
				nd=nd->m_next;
			}	
		}
	}
	return OK;
}












































