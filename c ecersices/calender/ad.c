#include <stdio.h>
#include <stdlib.h>
#include "ad.h"

calender* createAD(int Capacity){
	calender* newCal;
	if(newCal=(calender*)malloc(sizeof(calender))){
		newCal->currcap=0;
		newCal->capacity=Capacity;
		newCal->day=(meetingPtr*)malloc(Capacity*sizeof(meetingPtr));
		if(newCal->day==NULL){
			free(newCal);
			return 0;
		}
		return newCal;
	}
	return NULL;
}

meeting* createMeet(){
	meetingPtr newMeet;
	unsigned int room=0;
	float time=0;
	newMeet=(meetingPtr)malloc(sizeof(meeting));
	if(newMeet){
		do{
			printf("enter start time for meeting\n");
			scanf("%f",&time);
		}while(time>=24 || time<0);
		newMeet->start=time;
		do{
			printf("enter stop time for meeting\n");
			scanf("%f",&time);
		}while(time<=newMeet->start || time>24);
		newMeet->stop=time;
		printf("enter room number for meeting\n");
		scanf("%u",&room);
		newMeet->room=room;
		return newMeet;
	}
	return NULL;
}

int insertApp(calender* cal,meetingPtr meetPtr){
	meetingPtr* temp;
	int i=0,j=0, insert=0;
	/*validate the pointers*/
	if(cal==NULL || meetPtr==NULL){
		return 0;
	}
	if(cal->day==NULL){
		return 0;
	}
	/*case of empty array*/
	if(cal->currcap==0){
		cal->day[0]=meetPtr;
		cal->currcap++;
		return 1;
	}
	/* search if there is a valid time for the meeting */
	if(meetPtr->stop <= cal->day[0]->start){/*case of meeting in the begining*/
		insert=0;
	}
	else if(meetPtr->start >= cal->day[cal->currcap-1]->stop){/*case of meeting being at the end*/
		insert=cal->currcap;
	}
	/*case of meeting being in the middle*/
	else{
		for(i=0;i<cal->currcap;i++){
			if(meetPtr->start > cal->day[i]->stop){
				 if(cal->day[i+1]->start > meetPtr->start){
					 if((cal->day[i+1]->start) > (meetPtr->stop)){
						insert=i+1;
						break;
					}
					else if(cal->day[i+1]->start < meetPtr->stop){
						return 0;
					}	
				}
			}					
		}
		if(i==cal->currcap){
			return 0;
		}
	}
	/* allocate new memory*/
	if ((cal->currcap)==(cal->capacity)){
		temp=cal->day;
		cal->day=realloc(cal->day,(cal->capacity)*2*sizeof(meetingPtr));
		if (cal->day){
			cal->capacity*=2;
		}
		else{
			cal->day=temp;
			return 0;
		}	
	}
	/*insert meeting */
	shiftMRight( cal,insert);
	cal->day[insert]=meetPtr;
	cal->currcap++;					
	return 1;
}

void removeApp(calender* cal, float begin){	
	int i=0,j=0;
	if (!cal){
		return;
	}
	if(!cal->day){
		return;
	}
	for(i=0;i<cal->currcap;i++){
		if(begin==cal->day[i]->start){
			free(cal->day[i]);
			for(j=i;j<cal->currcap-1;j++){
				cal->day[j]=cal->day[j+1];
			}
			cal->currcap--;	
			break;				
		}
	}		
}

meeting* findApp(calender* cal,float begin){
	int i=0;
	if(!cal){
		return NULL;
	}
	if(!cal->day){
		return 0;
	}
	for(i=0;i<cal->capacity && begin<=cal->day[i]->start;i++){
		if (begin==cal->day[i]->start){
			return cal->day[i];
		}
	}
	return NULL;
}

void destroyAD(calender* cal){
	int i=0;
	if(cal){
		if(cal->day){
			for(i=0;i<cal->currcap;i++){
					free(cal->day[i]);
			}
			free(cal->day);
		}
		free(cal);
	}
}

void printAD(calender* cal){
		int i=0;
	if (cal){
		if(cal->day){
			for(i=0;i<cal->currcap;i++){
				printf("%.2f %.2f %u\n",cal->day[i]->start,cal->day[i]->stop,cal->day[i]->room);
			}
		}
	}
}

void shiftMRight(calender* calPtr,int ind){
	int i=0;
	if(calPtr){
		if(calPtr->day){
			for(i=calPtr->currcap;i>ind;i--){
				calPtr->day[i]=calPtr->day[i-1];
			}
		}
	}					
}

void saveInFile(calender* calPtr,char* fileN){
	int i=0;
	FILE* filePt;
	if(calPtr==NULL){
		return;
	}
	if(calPtr->day==NULL){
		return;
	}
	if(((filePt=fopen(fileN,"w"))==NULL)){
		return;
	}
	for(i=0;i<calPtr->currcap;i++){
		fprintf(filePt,"%f %f %d\n",calPtr->day[i]->start,calPtr->day[i]->stop,calPtr->day[i]->room);
	}
	fclose(filePt);
}

int loadFromFile(calender* calPtr,char* fileN){
	meetingPtr newMeet;
	int ins;
	unsigned int room=0;
	float startTime=0;
	float stopTime=0;
	FILE* filePt;
	/*can we open file*/
	if((filePt=fopen(fileN,"r"))==NULL){
		return 0;
	}
	/*while there is something to read*/
	while(!feof(filePt)){
		fscanf(filePt,"%f%f%u",&startTime,&stopTime,&room);
		if(!feof(filePt)){
			newMeet=(meetingPtr)malloc(sizeof(meeting));
			/*if we succesfully allocated memory for new meeting*/
			if(newMeet!=NULL){
				newMeet->start=startTime;
				newMeet->stop=stopTime;
				newMeet->room=room;
				ins=insertApp(calPtr,newMeet);
				if(!ins){
					free(newMeet);
					fclose(filePt);
					return 0;
				}
			}
			else{
				fclose(filePt);
				return 0;
			}
		}
	}
	fclose(filePt);	
	return 1;
}






