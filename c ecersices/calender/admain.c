#include <stdio.h>
#include <stdlib.h>
#include "ad.h"

int menu();

int main(){
	int func=0;
	int ins=0;
	float time=0;
	calender* calen;
	meetingPtr pmeet;
	if(calen=(calender*)malloc(sizeof(calender))){
		if(calen=createAD(1)){
			do{
				func=menu();
				switch (func){
					case 1:	
						pmeet=createMeet();
						/*printf("%p\n",(void*)pmeet);*/
						if (pmeet!=NULL){
							ins=insertApp(calen, pmeet);
							if(!ins){
							 	printf("error! failed to add meeting\n");
								free(pmeet);				
							}
						}
						else{
							printf("error! failed to add meeting.\n");
						}
						break;
					case 2: 
						printf("enter the of the meeting you would like to remove:\n");
						scanf("%f",&time);
						removeApp(calen, time);
						break;
					case 3:
						printf("enter time of meeting to find:\n");
						scanf("%f",&time);
						pmeet=findApp( calen, time);				
						break;
					case 4:
						printAD(calen);
						break;
					default:
						break;
				}
			}while(func);
		}
	}
	else{
		printf("failed\n");
	}
	destroyAD(calen);
	return 0;
}

int menu(){
	int action=0;
	printf("enter 0 to exit\nenter 1 to add a meeting\nenter 2 to remove a meeting\nenter 3 to find a meeting\nenter 4 to print daily appointments\n");
	scanf("%d",&action);
	return action;
}
