#include "pack.h"
#include <stdio.h>



int bitPack(unsigned char* str){
  int i=0,res=0;
	unsigned char temp;
	if(str==0){
		return 0;
	}
	for(i=0;str[i]!='\0';i++){
		if(i%2==0){
			str[i/2]=(str[i]-'a')<<4;
		}
		else{
			temp=(str[i]-'a');
			str[i/2]=temp|str[i/2];
		}
		res++;
	}
	return res; 

}

int unionPack(unsigned char* str){
	union un myU;
	  int i=0,res=0;
	unsigned char temp;
	if(str==0){
		return 0;
	}
	for(i=0;str[i]!='\0';i++){
		if(i%2==0){
			myU.lr.m_r=str[i]-'a';
		}
		else{
			myU.lr.m_l=str[i]-'a';
			str[i/2]=myU.c;
		}
		res++;
	}
	str[i/2]=myU.c;
	return res; 
}


void printPack(unsigned char* str, int num){
	int i=0,fifteen=0x0F ;
	unsigned char temp;
	for (i=0;i<num; i++){
		if(i%2!=0){
			temp=str[i/2]&fifteen;
		}
		else{
			temp=str[i/2]>>4;
			temp=temp&fifteen;
		}
		temp=temp+'a';
		printf("%c",temp);
	}
	printf("\n");
}





