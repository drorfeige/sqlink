#include <stdio.h>
#include "hash.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>


unsigned long hashFunction(void* key);
int mystrcmp(void* str1, void* str2);
int printVal(void* val,void* dummyVar);
void killVal(void* val);
void killkey(void* key);
hash testTableOverloadCreate();
int printValAndKey(void* val,void* key);
void printStatus(int status);
int updateTest(hash hashP);
int findTest(hash ht);
int deleteTest(hash ht);
int addElements(hash ht);


int main(){
	hash testH=NULL;
	hashStatus status;
	testH=testTableOverloadCreate();
	/*status=hashtableForEach(testH, printValAndKey);
	printStatus(status);
	status=updateTest(testH);
	status=hashtableForEach(testH, printValAndKey);
	printStatus(status);*/
	status=findTest(testH);
	status=deleteTest(testH);
	status=addElements(testH);
	status=hashtableForEach(testH, printValAndKey);
	printStatus(status);
	hashtableDestroy(testH,killVal, killkey);
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


int printValAndKey(void* val,void* key){
	if(val!=NULL && key!=NULL){	
		printf("key%c has value of%d\n",*(char*)key,*(int*)val);
		return 1;
	}
	return 0;
}


hash testTableOverloadCreate(){
	int i=0;
	hash ht;
	hashFunc Hf;
	compareFunc cp;
	int* val;
	char* key;
	hashStatus status;
	time_t t;
	cp=mystrcmp;
	Hf=hashFunction;
	ht=hashtableCreate(4,cp, Hf);
	srand((unsigned) time(&t));
	if(ht==NULL){
		printf("failed to create table\n");
	}
	status=hashtableForEach(ht, printValAndKey);
	for(i=0;i<255;i++){
		key=(char*)malloc(4*sizeof(char));
		val=(int*)malloc(sizeof(int));
		if(key!=NULL && val!=NULL){
			*val=i;
			key[0]=(rand()%('Z'-'A')+'A');
			key[1]='\0';
			status=hashtableInsert(ht,(void*)val, (void*)key);
			if(status==ALLOCATION_FAILED){
				printf("malloc issues\n");
				break;
			}
			if(status==ALREADY_IN_TABLE){
				free(key);
				free(val);
			}
		}	
	}
	return ht; 
}

void printStatus(int status){
	switch(status){
		case 0:
			printf("OK\n");
			return;
		case 1:
			printf("ALLOCATION_FAILED\n");
			return;
		case 2:
			printf("NOT_IN_TABLE\n");
			return;
		case 3:
			printf("ALREADY_IN_TABLE\n");
			return;
		case 4:
			printf("NO_TABLE\n");
			return;
		default:
			return; 
	}                
}

int updateTest(hash hashP){
	hashStatus status;		
	int* val=NULL;
	val=malloc(sizeof(int));
	if(val!=NULL){
		status=hashtableUpdate(hashP,(void*) val, (void*) "A");
		printStatus(status);
	}
		val=malloc(sizeof(int));
	if(val!=NULL){
		status=hashtableUpdate(hashP,(void*) val, (void*) "K");
		printStatus(status);
	}
		val=malloc(sizeof(int));
	if(val!=NULL){
		status=hashtableUpdate(hashP,(void*) val, (void*) "&");
		printStatus(status);
	}
	return 1;
}

int findTest(hash ht){
	char key[4];
	char i=0;
	void* pInt=NULL;
	hashStatus status;
	key[1]='\0';
	for(i=0;i<'Z'-'A'+1;i++){
		key[0]=i+'A';
		status=hashtableFind(ht, (void*) key,  &pInt);
		if(status==OK){
			printf("%d\n",*(int*)pInt);
		}		
	}
	status=hashtableFind(ht, (void*) "&",  &pInt);
	printStatus(status);
	return 1;
}

int deleteTest(hash ht){
	char key[4];
	hashStatus status;
	char i=0;	
	time_t t;
	key[1]='\0';
	srand((unsigned) time(&t));
	status=hashtableDelete(ht, (void*) "ert",killVal,killkey);
	printStatus(status);
	for(i=0;i<10;i++){
		key[0]=((rand()+31)%('Z'-'A')+'A');
		printf("%c\n",key[0]);
		hashtableDelete(ht, (void*) key,killVal,killkey);
		status=findTest(ht);
		/*hashtableForEach(ht, printValAndKey);*/
		printf("**************************************\n");
	}
	return 1;

}

int addElements(hash ht){
	int i=0;
	int* val;
	char* key;
	hashStatus status;
	time_t t;
	srand((unsigned) time(&t));
		for(i=0;i<255;i++){
		key=(char*)malloc(4*sizeof(char));
		val=(int*)malloc(sizeof(int));
		if(key!=NULL && val!=NULL){
			*val=i;
			key[0]=(rand()%('z'-'a')+'a');
			key[1]='\0';
			status=hashtableInsert(ht,(void*)val, (void*)key);
			if(status==ALLOCATION_FAILED){
				printf("malloc issues\n");
				break;
			}
			if(status==ALREADY_IN_TABLE){
				free(key);
				free(val);
			}
		}	
	}
	return 1;	
}



	/*hash ht;
	hashFunc Hf;
	compareFunc cp;
	hashStatus status;
	void* pInt;
	int val=100;
	int val2=9212;
	char key[32]="hello world";
	char key2[32]="do not enter table";
	cp=mystrcmp;
	Hf=hashFunction;
	ht=hashtableCreate(1,cp, Hf);
	status=hashtableInsert(ht,(void*) &val, (void*) key);	
	printf("%d\n",status);
	status=hashtableInsert(ht,(void*) &val, (void*) key);	
	printf("%d\n",status);
	status=hashtableInsert(ht,(void*) &val2, (void*) key2);	
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
	hashtableDestroy(ht,NULL, NULL);*/
























