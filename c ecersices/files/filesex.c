#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filesex.h"

void printNLines(char* filename, unsigned int N){
		long int* offsetArr;
		long int temp=0;
		int i=0,j=0,count=0;
		FILE* fp;
		char toPrint[512]="";
		offsetArr=(long int*)malloc(N*sizeof(long int));
		/*was malloc succesfull*/
		if(offsetArr==NULL){
			return;
		}
		/*can we read from file*/
		if((fp=fopen(filename,"r"))==NULL){
			return;
		}
		while(!feof(fp)){
			temp=ftell(fp);
			fgets(toPrint,512,fp);
			if(!feof(fp)){
			count++;
			offsetArr[(i++)%N]=temp;
			}
		}
		if(count<N){
			i=0;
		}
		else{
			count=N;
		}
		for(j=0;j<count;j++){
			if(!fseek(fp,offsetArr[(i++)%N],0)){
				fgets(toPrint,512,fp);
				printf("%s",toPrint);
			}
		}	
}

void countChars(char* filename){
	char i=0;
	FILE* fp;
	int temp=0;
	int chArr[64]={0};/*we only need 52 for the letters but 52 is not a power of 2*/
	if((fp=fopen(filename,"r"))!=NULL){
		while(!feof(fp)){
			temp=fgetc(fp);
			if(temp>='A' && temp<='Z'){
				chArr[temp-'A']++;
			}	
			else if(temp>='a' && temp<='z'){
				chArr[temp-'a'+26]++;
			}
		}
	}
	for(i=0;i<26;i++){
		if(chArr[i]!=0){
		printf("%c  %d\n",i+'A',chArr[i]);
		}
		if(chArr[i+26]!=0){
		printf("%c  %d\n",i+'a',chArr[i+26]);
		}
	}
}

wordsInFile* extractWords(char* filename){
	wordsInFile* wPtr;
	FILE* fp;
	int i=0;
	char c;
	char w[32]="";
	wPtr=(wordsInFile*)malloc(8*sizeof(wordsInFile));
	if(wPtr==NULL){
		return NULL;
	}
	if((fp=fopen(filename,"r"))!=NULL){
		return NULL;	
	}
	while(!feof){
		c = fgetc(fp);
		if(c == ' ' || c == '\n')
		{
		w[i]='\0';
		i=0;
		/*add word to word array*/	
		}
		else
		{
		w[i]=c;
		}
	}
}

void printWords(wordsInFile* wordPtr){
	if (wordPtr==NULL){
		return;
	}
	if(wordPtr->wordArr==NULL){
		return;
	}
}












