#include <stdio.h>
#include "bit.h"

int menu();
int getFeature();

int main(int argc, char* argv[]){
	int var=0;
	int func=0;
	int ans=0;
	bitMap* BM;
	bitFunc BFA[3]={bitOn,bitOff,bitCheck};
	printf("enter number of features:\n");
	scanf("%d",&var);
	if((BM=createBM(var))!=NULL){
		printBM(BM);
		do{
			func=menu();
			if(func>=0 && func <2){
				var=getFeature();
				if((ans=BFA[func](BM,var))!=0){
					printBM(BM);
				}
				else{
					printf("action failed\n");
				}
			}
		}while(func>=0);
		destroy(BM);
	}	

	return 0;
}



/*
create array of pointer functions
loop to turn off,on or check bit
printbitmap, use int to binary from homework
*/


int menu(){
	int action =0;
	printf("enter 0 to add feature\n");
	printf("enter 1 to remove feature\n");
	printf("enter 2 to check if a feature is available\n");
	printf("enter -1 to exit\n");
	scanf("%d",&action);
	return action;
}

int getFeature(){
	int f=0;
	printf("choose index\n");
	scanf("%d",&f);
	return f;
}















