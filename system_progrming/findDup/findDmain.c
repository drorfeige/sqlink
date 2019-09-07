#include <stdio.h>
#include "files.h"
#include "hash.h"
#include <stdlib.h>
#include <string.h>

void killVal(void* val);
unsigned long hashFunction(void* key);
int mystrcmp(void* str1, void* str2);


int main(int argc,char** argv){
	hash hp;
	hp=hashtableCreate(2048,mystrcmp,hashFunction);
	if(hp==0){
		printf("failed to create hash table\n");
	}
	if(argc==2){
		if((isDir(argv[1])==0)){
			printf("%s is not a directory",argv[1]);
		}
		scanDir(argv[1],hp);		
	}
	else if(argc==1){
		scanDir(".",hp);		
	}
	else{
		printf("wrong number of arguments\n");
	}
	hashtableDestroy(hp, killVal, killVal);			
	return 0;        
}

void killVal(void* val){
	free(val);
}

int mystrcmp(void* str1, void* str2){
	char* St1;
	char* St2;
	St1=(char*)str1;
	St2=(char*)str2;
	return strcmp(St1,St2);

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









