#include <stdio.h>
#include "String.h"

int menu(){
	int choice;
	printf("choose option:\n\n0.exit\n1.setString\n2.getString\n3.getLength\n4.printString\n5.compare strings\n6.copy constructor\n7.copy from constant string\n");
	scanf("%d",&choice);
	return choice;
}

int main(int argc,char** argv){
	int action;
	String str1=String("string from constant char");
	do{
		action=menu();
		switch (action){
			case 1:
				str1.setString("string is set");
				break;
			case 2:
				printf("%s\n",str1.getString());
				break;
			case 3:
				printf("the string length is %d\n",(int)str1.getLength());
				break;
			case 4:
				str1.print();
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			default:
				break;
		}

	}while(action>0);	
	return 0;
}



















