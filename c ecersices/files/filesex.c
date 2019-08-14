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
	int i=0,j=0;
	char c;
	char w[32]="";
	wPtr=(wordsInFile*)malloc(sizeof(wordsInFile));
	if(wPtr==NULL){
		return NULL;
	}
	wPtr->wordArr=(Word**)malloc(8*sizeof(Word*));
	if(wPtr->wordArr==NULL){
		free(wPtr);
		return 0;
	}
	wPtr->m_capacity=8;
	wPtr->index=0;
	if((fp=fopen(filename,"r"))==NULL){
		free(wPtr->wordArr);
		free(wPtr);
		return NULL;	
	}
	while(!feof(fp)){
		c = fgetc(fp);
		if(c == ' ' || c == '\n'){
			w[i]='\0';
			i=0;
			if(insertWord( wPtr, w)==0){
				for(j=0;j<wPtr->index;j++){
					if(wPtr->wordArr[wPtr->index]){
						if(wPtr->wordArr[wPtr->index]->m_word){
							free(wPtr->wordArr[wPtr->index]->m_word);
					}
					free(wPtr->wordArr[wPtr->index]);
					}
				}
				free(wPtr->wordArr);
				free(wPtr);
				return NULL;
			}
		}	
		else{
		w[i++]=c;
		}
	}
	return wPtr;
}

void printWords(wordsInFile* wordPtr){
	int i=0;
	if (wordPtr==NULL){
		return;
	}
	if(wordPtr->wordArr==NULL){
		return;
	}
	for(i=0;i<wordPtr->index;i++){
		printf("%s %d\n",wordPtr->wordArr[i]->m_word,wordPtr->wordArr[i]->num);
	}
}

int insertWord(wordsInFile* wordPtr,char* newWord){
		Word** temp;
		Word* wtemp;
	int i=0,j=0, insert=0;
	/*validate the pointers*/
	if(wordPtr==NULL){
		return 0;
	}
	if(wordPtr->wordArr==NULL){
		return 0;
	}
	/*case of empty array*/
	if(wordPtr->index==0){
		if((wordPtr->wordArr[0]=(Word*)malloc(sizeof(Word)))==NULL){
			return 0;
		}
		if((wordPtr->wordArr[0]->m_word=(char*)malloc(32*sizeof(char)))==NULL){
			free(wordPtr->wordArr[0]);
			return 0;
		}
		wordPtr->wordArr[0]->num=1;
		strcpy(wordPtr->wordArr[0]->m_word,newWord);
		wordPtr->index++;
		return 1;
	}
	/* search if there is a valid time for the word */
	if(strcmp(newWord,wordPtr->wordArr[0]->m_word)>0){/*case of meeting in the begining*/
		insert=0;
	}
	else if(strcmp(newWord,wordPtr->wordArr[wordPtr->index-1]->m_word)<0){/*case of meeting being at the end*/
		insert=wordPtr->index;
	}
	/*case of word being in the middle*/
	else{
		for(i=0;i<wordPtr->index;i++){
			if(strcmp(newWord,wordPtr->wordArr[i]->m_word)==0){
				wordPtr->wordArr[i]->num++;
				return 1;
			}
			if(strcmp(newWord,wordPtr->wordArr[i]->m_word)>0 && strcmp(newWord,wordPtr->wordArr[i]->m_word)<0){
				insert=i+1;
				break;	
			}					
		}
	}
	/* allocate new memory*/
	if ((wordPtr->index)==(wordPtr->m_capacity)){
		temp=wordPtr->wordArr;
		wordPtr->wordArr=realloc(wordPtr->wordArr,(wordPtr->m_capacity)*2*sizeof(Word*));
		if (wordPtr->wordArr){
			wordPtr->m_capacity*=2;
		}
		else{
			wordPtr->wordArr=temp;
			return 0;
		}	
	}
	/*insert word */		
	if((wtemp=(Word*)malloc(sizeof(Word)))==NULL){
		return 0;
	}
	if((wtemp->m_word=(char*)malloc(32*sizeof(char)))==NULL){
		free(wtemp);
		return 0;
	}
	for( i=wordPtr->index;i>insert;i--){
		wordPtr->wordArr[i]=wordPtr->wordArr[i-1];
	}
	strcpy(wtemp->m_word,newWord);
	wtemp->num=1;
	wordPtr->wordArr[insert]=wtemp;
	wordPtr->index++;					
	return 1;

}










