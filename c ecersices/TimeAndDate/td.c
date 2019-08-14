#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "td.h"

/**********************time functions*******************************/
static char numOfDays(datePtr day);

timePtr newTime(char seconds, char minutes, char hours){
	timePtr tPtr;
	tPtr=(timePtr)malloc(sizeof(cTime_t));
	if(tPtr==NULL){
		return NULL;
	}
	tPtr->m_hour=hours;
	tPtr->m_minute=minutes;
	tPtr->m_seconds=seconds;	
	return tPtr;
}

timePtr newCurrentTime(){
	timePtr tPtr;
	time_t t = time(NULL);
	struct tm* tm = localtime(&t);
	tPtr=(timePtr)malloc(sizeof(cTime_t));
	if(tPtr==NULL){
		return NULL;
	}
	tPtr->m_hour=tm->tm_hour;
	tPtr->m_minute=tm->tm_min;
	tPtr->m_seconds=tm->tm_min;
	return tPtr;
}

timePtr addTime(timePtr time1, timePtr time2){
	timePtr tPtr;
	char carry=0;;
	if(time1==NULL){
		return NULL;
	}
	if(time2==NULL){
		return NULL;
	}
	tPtr=(timePtr)malloc(sizeof(cTime_t));
	if(tPtr==NULL){
		return NULL;
	}
	tPtr->m_seconds=(time1->m_seconds + time2->m_seconds)%60;
	carry=(time1->m_seconds + time2->m_seconds)/60;
	tPtr->m_minute=(time1->m_minute + time2->m_minute+carry)%60;
	carry=(time1->m_minute + time2->m_minute+carry)/60;
	tPtr->m_hour=(time1->m_hour + time2->m_hour + carry)%24;
	return tPtr;
}

int updateTime(timePtr time,char seconds, char minutes, char hours){
		if(time==NULL){
		return 0;
	}
	time->m_hour=hours;
	time->m_minute=minutes;
	time->m_seconds=seconds;
	return 1;
}

char getHour(timePtr time){
	if(time==NULL){
		return 0;
	}
	return time->m_hour;
}

char getMin(timePtr time){
	if(time==NULL){
		return 0;
	}
	return time->m_minute;
}

char getSec(timePtr time){
	if(time==NULL){
		return 0;
	}
	return time->m_seconds;
}

void printTime(timePtr time, int mode){
	char APM[3]="";
	if(time==NULL){
		return;
	}
	if(mode){
		if(time->m_hour/12){
			strcpy(APM,"PM");
		}
		else{
			strcpy(APM,"AM");
		}
		printf("%d:%d:%d %s\n",time->m_hour%12,time->m_minute,time->m_seconds,APM);
		return;
	}
	printf("%d:%d:%d\n",time->m_hour,time->m_minute,time->m_seconds);
}

/***********************Date Functions************************/

datePtr newDate(char day, char month, int year){
	datePtr dPtr;
	dPtr=(datePtr)malloc(sizeof(cDate_t));
	if(dPtr==NULL){
		return NULL;
	}
	dPtr->m_day=day;
	dPtr->m_month=month;
	dPtr->m_year=year;
	return dPtr;
}

datePtr newCurrentDate(){
	datePtr dPtr;
	time_t time_date;
	struct tm* current_time;
	dPtr=(datePtr)malloc(sizeof(cDate_t));
	if(dPtr==NULL){
		return NULL;
	}
	time_date=time(0);
	current_time = localtime(&time_date);
	dPtr->m_day=current_time->tm_mday;
	dPtr->m_month=current_time->tm_mon+1;
	dPtr->m_year=current_time->tm_year+1900;
	
}

char getDay(datePtr time){
	if(time==NULL){
	return 0;
	}
	return time->m_day;
}

char getMon(datePtr time){
	if(time==NULL){
	return 0;
	}
	return time->m_month;
}

int getYear(datePtr time){
	if(time==NULL){
	return 0;
	}
	return time->m_year;
}

int updateDate(datePtr time,char day, char month, char year){
	if(time==NULL){
		return 0;
	}
	time->m_day=day;
	time->m_month=month;
	time->m_year=year;
	return 1;
}

char* monthToText(datePtr month){
	static char Month[16]="";
	if(month==NULL){
		return 0;
	}
	switch (month->m_month){
		case 1:
			strcpy(Month,"January");
			break;
		case 2:
			strcpy(Month,"February");
			break; 
		case 3:
			strcpy(Month,"March");
			break;
		case 4:
			strcpy(Month,"April");
			break;
		case 5:
			strcpy(Month,"May");
			break;
		case 6:
			strcpy(Month,"June");
			break;
		case 7:
			strcpy(Month,"July");
			break;
		case 8:
			strcpy(Month,"August");
			break;
		case 9:
			strcpy(Month,"September");
			break;
		case 10:
			strcpy(Month,"October");
			break;
		case 11:
			strcpy(Month,"November");
			break;
		case 12:
			strcpy(Month,"December");
			break;
		default:
			break;
	}
	return Month;
}

void printDate(datePtr day,int mode, int text){
	char* Month;
	if(day==NULL){
		return;
	}
        if(mode){
		if(text){
			Month=monthToText(day);
			printf("%.3s/%d/%d\n",Month,day->m_day,day->m_year);			
		}
		else{
			printf("%d/%d/%d\n",day->m_month,day->m_day,day->m_year);
		}
	}
	else{
		if(text){
			Month=monthToText(day);
			printf("%d/%.3s/%d\n",day->m_day,Month,day->m_year);			
		}
		else{
			printf("%d/%d/%d\n",day->m_day,day->m_month,day->m_year);
		}
	}

}

datePtr addDate(datePtr date1, int adDays ){
	char carry, carryM, daysInMon;
	if(date1==NULL){
		return NULL;
	}
	daysInMon=numOfDays( date1);
	carry=(date1->m_day+adDays)/daysInMon;
	date1->m_day=(date1->m_day+adDays)%daysInMon;
	carryM=(date1->m_month+carry)/12;
	date1->m_month=(date1->m_month+carry)%12;
	if(carryM){
		date1->m_year++;
	}
	return date1;	
}

static char numOfDays(datePtr day){
	if(day==NULL){
		return 0;
	}
	if(day->m_month==1 || day->m_month==3 || day->m_month==5 ||day->m_month==7 || day->m_month==8 || day->m_month==10 || day->m_month==12){
		return 31;
	}
	else if(day->m_month==4 || day->m_month==6 || day->m_month==9 ||day->m_month==11){
		return 30;
	}
	if ((day->m_year%4)==0){
		return 29;
	}
	return 28;
}





