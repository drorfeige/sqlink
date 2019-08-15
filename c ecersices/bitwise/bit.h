#ifndef BIT_H
#define BIT_H
  		

typedef struct{
 	int m_nf;
	char* m_features; 
}bitMap; 

typedef int (*bitFunc)(bitMap* , int);

int bitOn(bitMap* features,int index);
int bitOff(bitMap* features,int index);
int bitCheck(bitMap* features,int index);

bitMap* createBM(int nf);
void printBM(bitMap* features);
	
int destroy(bitMap* bt);

#endif


/*program with n features
turn off and on a specific feature
and check if a specific feature is on*/






