#ifndef TD_H
#define TD_H

typedef struct{
	char m_seconds;
	char m_minute;
	char m_hour;
}cTime_t;

typedef cTime_t* timePtr;

typedef struct{
	char m_day;
	char m_month;
	int m_year;
}cDate_t;

typedef cDate_t* datePtr;

/**************date functions**********************/
datePtr newDate(char day, char month, int year);
datePtr newCurrentDate();
int updateDate(datePtr time,char day, char month, char year);
void printDate(datePtr day,int mode, int text);
/* varible mode is 0 for european and 1 for american
variable text is 0 for month in digits and 1 for month in text*/
datePtr addDate(datePtr date1, int adDays );
char getDay(datePtr time);
char getMon(datePtr time);
char* monthToText(datePtr month);
int getYear(datePtr time);
/**************time functions******************/
timePtr newTime(char seconds, char minutes, char hours);
timePtr newCurrentTime();
int updateTime(timePtr time,char seconds, char minutes, char hours);
timePtr addTime(timePtr time1, timePtr time2);
void printTime(timePtr time, int mode);
/* variable mode is 0 for only digits and 1 for AM PM*/
char getSec(timePtr time);
char getMin(timePtr time);
char getHour(timePtr time);


#endif









