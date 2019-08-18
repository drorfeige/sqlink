#include <stdio.h>
#include "bit.h"

static void char2Bin(unsigned char n, char* bin);

unsigned char invertBits(unsigned char x){
	unsigned char y;
	char toPrint[16]="";
	y=(~0)^x;
	char2Bin(x, toPrint);
	printf("x = %s",toPrint);
	printf(" (binary)\n");
	char2Bin(y, toPrint);
	printf("x inverted = %s",toPrint);
	printf(" (binary)\n");
	return y;
}


static void char2Bin(unsigned char n, char* bin){
		int res=0;
		int i=sizeof(char)*8;
		if(bin==NULL){
			return;
		}
		bin[i--]='\0';
		do{
			bin[i--]=(n%2)?'1':'0';
			n=n/2;
		}while(i>=0);
}

static void int2Bin(unsigned int n, char* bin){
		int res=0;
		int i=8*sizeof(int);
		bin[i--]='\0';
		if(bin==NULL){
			return;
		}
		do{
			bin[i--]=(n%2)?'1':'0';
			n=n/2;
		}while(i>=0);
}

int rotateLeft(unsigned int x, int N){
	int i=0;
	int mask=1;
	char toPrint[64]="";
	int2Bin(x, toPrint);
	printf("x = %s",toPrint);
	printf(" (binary)\n");
	mask<<=sizeof(int)*8-1;	
	for(i=0;i<N;i++){
		if((x&mask)!=0){
			x<<=1;
			x+=1;
		}
		else{
			x<<=1;
		}
	}
	int2Bin(x, toPrint);
	printf("x rotated by %d to the left = %s",N,toPrint);
	printf(" (binary)\n");
	return x;
}

int rotateRight(unsigned int x, int N){  /*need to finish this function*/
	int i=0;
	int mask=1;
	char toPrint[64]="";
	int2Bin(x, toPrint);
	printf("x = %s",toPrint);
	printf(" (binary)\n");
	mask<<=sizeof(int)*8-1;	
	for(i=0;i<N;i++){
		if((x&1)!=0){
			printf("%d\n",x&1);
			x>>=1;
			x+=mask;
		}
		else{
			x>>=1;
		}
	}
	int2Bin(x, toPrint);
	printf("x rotated by %d to the right = %s",N,toPrint);
	printf(" (binary)\n");
	return x;

}

int setbits3(unsigned char x,int p,int n,unsigned char y){
	int i=0;
	char toPrint[64]="";
	int temp=0,mask=1;;
	mask<<=sizeof(int)*8-1;
	/*print initial values*/
	int2Bin(x, toPrint);
	printf("x = %s",toPrint);
	printf(" (binary)\n");	
	int2Bin(y, toPrint);
	printf("y = %s",toPrint);
	printf(" (binary)\n");
	/*algorithm*/
	if(n<=0 || p>8 || n>p){
		return x;
	}
	for(i=0;i<p-n;i++){
		temp<<=1;
		if(x&1){
			temp+=mask;
		}
		x<<=1;
		y<<=1;
	}
	for(i;i<p;i++){
		temp<<=1;
		if(y&1){
			temp+=mask;
		}
		x<<=1;
		y<<=1;
	}
	for(i;i<=sizeof(int)*8;i++){
		temp<<=1;
		if(x&1){
			temp+=mask;
			}
		x<<=1;
		y<<=1;
	}
	/*print answer*/
	int2Bin(temp, toPrint);
	printf("x after setbits = %s",toPrint);
	printf(" (binary)\n");
	return x;		
}

int setbits4(unsigned int w,int i,int j,int value){
	unsigned int mask=0,index=0;	
	char toPrint[64]="";
	if(i<0 || i>31){
		return 0;
	}
	if(j<i || j>31){
		return 0;
	}
	int2Bin(w, toPrint);
	printf("x = %s",toPrint);
	printf(" (binary)\n");
	for(index=0;index<j-i+1;index++){
		mask<<=1;
		mask+=1;
	}
	for(index=0;index<i;index++){
		mask<<=1;
	}	
	if(value){
		w|=mask;	
	}
	else{
		mask=~mask;
		w&=mask;
	}
	int2Bin(w, toPrint);
	printf("x after setbits = %s",toPrint);
	printf(" (binary)\n");	
	return w;
}


