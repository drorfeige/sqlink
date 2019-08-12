#ifndef AD_H
#define  AD_H

typedef struct{
	float start;
	float stop;
	unsigned int room;
}meeting; 

typedef meeting* meetingPtr;

typedef struct{
	int capacity;
	int currcap;
	meetingPtr* day; 	
}calender;

calender* createAD(int Capacity);
meeting* createMeet();
int insertApp(calender* cal,meetingPtr meetPtr);
void removeApp(calender* cal,float begin);
meeting* findApp(calender* cal,float begin);
void destroyAD(calender* cal);
void printAD(calender* cal);

#endif

