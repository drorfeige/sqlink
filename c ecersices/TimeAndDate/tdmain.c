#include <stdio.h>
#include <stdlib.h>
#include "td.h"



int main(int argc, char* argv[]){
	char recieve;
	int rec;
	char* Month;
	timePtr timeP,timeP1,timeP2;
	datePtr dateP,dateP1,dateP2;
/******************time part******************/
	timeP=newTime(34, 55, 15);
	if(timeP){
		 printTime(timeP, 1);
		 recieve=getSec(timeP);
		 printf("%d\n",recieve);
		 recieve=getMin(timeP);
		 printf("%d\n",recieve);
		 recieve=getHour(timeP);
		 printf("%d\n",recieve);
		/* free(timeP);*/
	}
	if(updateTime(timeP,0, 37, 23)){
		 printTime(timeP, 1);
		 recieve=getSec(timeP);
		 printf("%d\n",recieve);
		 recieve=getMin(timeP);
		 printf("%d\n",recieve);
		 recieve=getHour(timeP);
		 printf("%d\n",recieve);
		 /*free(timeP);*/
	}
	timeP1=newCurrentTime();
	if(timeP1){
		printTime(timeP1, 1);
		/*free(timeP1);*/
	}
	if((timeP2=addTime( timeP1, timeP))!=NULL){
		printTime(timeP2,0);
		free(timeP2);
	}
	if(timeP){
		free(timeP);
	}
	if(timeP1){
		free(timeP1);
	}
/**************date part*****************/
	dateP=newDate(15, 8, 2019);
	if(dateP){
		printDate(dateP,0,0);
	}
	dateP1=newCurrentDate();
	if(dateP1){
		recieve=getDay(dateP1);
		printf("%d\n",recieve);
		recieve=getMon(dateP1);
		printf("%d\n",recieve);
		Month=monthToText( dateP1);
		printf("%s\n",Month);
		rec=getYear(dateP1);
		printf("%d\n",rec);
		printDate(dateP1,1,1);	
	}
	if((addDate(dateP1,23))!=NULL){
		printDate(dateP1,0,1);
	}
	if(dateP){
		free(dateP);
	}
	if(dateP1){
		free(dateP1);
	}
	return 0;
}


