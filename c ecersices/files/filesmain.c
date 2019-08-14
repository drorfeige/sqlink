#include <stdio.h>
#include <stdlib.h>
#include "filesex.h"

int menu();

int main(){	
	int func=0,i=0;
	unsigned int lines=0;
	char fileName[32]="";
	wordsInFile* wPtr;
	do{
		func=menu();
		switch (func){
			case 1:
				printf("enter file name:\n");
				scanf("%s",fileName);
				printf("how many lines do you want to print from %s:\n",fileName);
				scanf("%u",&lines);
				printNLines(fileName,lines);					
				break;
			case 2: 
				printf("enter file name:\n");
				scanf("%s",fileName);
				countChars(fileName);		
				break;
			case 3:
				printf("enter file name:\n");
				scanf("%s",fileName);
				wPtr=extractWords(fileName);
				if(wPtr!=NULL){
					printWords(wPtr);
					if (wPtr->wordArr){
						for(i=0;i<wPtr->index;i++)
						if(wPtr->wordArr[wPtr->index]){
							if(wPtr->wordArr[wPtr->index]->m_word){
								free(wPtr->wordArr[wPtr->index]->m_word);
							}
							free(wPtr->wordArr[wPtr->index]);
						}
						free(wPtr->wordArr);
					}
					free(wPtr);
				}						
				break;
			default:
				break;
		}
	}while(func);
	return 0;
}

int menu(){
	int action=0;
	printf("enter 0 to exit\nenter 1 to print N lines:\nenter 2 to count letters in file:\nenter 3 to count words in file\n");
	scanf("%d",&action);
	return action;
}

