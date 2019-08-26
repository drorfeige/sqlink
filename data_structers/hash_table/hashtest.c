#include <stdio.h>
#include "hash.h"
#include <string.h>
#include <stdlib.h>


unsigned long hashFunction(void* key);
int mystrcmp(void* str1, void* str2);
int printVal(void* val,void* dummyVar);
void killVal(void* val);
void killkey(void* key);

int main(){
	hash ht;
	hashFunc Hf;
	compareFunc cp;
	hashStatus status;
	void* pInt;
	int val=5;
	int val2=9;
	char key[32]="hello world";
	char key2[32]="do not enter table";
	cp=mystrcmp;
	Hf=hashFunction;
	ht=hashtableCreate(2048,cp, Hf);
	status=hashtableInsert(ht,(void*) &val, (void*) key);	
	printf("%d\n",status);
	status=hashtableInsert(ht,(void*) &val, (void*) key);	
	printf("%d\n",status);	
	status=hashtableFind(ht, (void*) key2,  &pInt);
	if(status==OK){
		printf("%d\n",*(int*)pInt);
	}
	status=hashtableFind(ht, (void*) key,  &pInt);
	if(status==OK){
		printf("%d\n",*(int*)pInt);
	}
	status=hashtableInsert(ht,(void*) &val2, (void*) key2);
	hashtableDestroy(ht,NULL, NULL);
	return 0;
}



unsigned long hashFunction(void* key){
	char* str;        
	int c;
	unsigned long retVal = 5381;
	str=(char*)key;
        while ((c = *str++)){
            retVal = ((retVal << 5) + retVal) + c; /* retVal * 33 + c */
	}
        return retVal;
}

int mystrcmp(void* str1, void* str2){
	char* St1;
	char* St2;
	St1=(char*)str1;
	St2=(char*)str2;
	return strcmp(St1,St2);

}

void killVal(void* val){
	free(val);
}

void killkey(void* key){
	free(key);
}


int printVal(void* val,void* dummyVar){
	if(val!=NULL){	
		printf("%d\n",*(int*)val);
		return 1;
	}
	return 0;
}
/*tests:
write print function




*/
































