#include <stdio.h>
#include "String.h"

int menu(){
	int choice;
	printf("choose option:\n\n0.exit\n1.setString\n2.getString\n3.getLength\n4.printString\n5.compare strings\n6.copy constructor\n7.copy from constant string\n8.string from equal operator\n");
	scanf("%d",&choice);
	return choice;
}

void recieveStr(char* rStr){
	printf("enter string:");
	scanf("%s",rStr);
}

int main(int argc,char** argv){
	int action;
	char* recieve=new char[32];
	//String str2;
	//String str3;
	String str1("string from constant char");
	//String str4;
	do{
		action=menu();
		switch (action){
			case 1:
				recieveStr(recieve);
				//printf("%s\n",recieve);
				str1.setString((const char*)recieve);
				//str1.setString("string is set");
				break;
			case 2:
				recieve=(char*)str1.getString();
				printf("%s\n",recieve);
				break;
			case 3:
				printf("the string length is %d\n",(int)str1.getLength());
				break;
			case 4:
				str1.print();
				break;
			case 5:
				printf("%d\n",str1.myStrcmp((const char*) recieve));
				break;
			case 6:
				{
					String str2(str1);
					str2.print();
				}
				break;
			case 7:
				{
					String str3(str1.getString());
					str3.print();
				}
				break;
			case 8:
				{
					String str4=str1;
					str4.print();
				}
				break;
			default:
				break;
		}

	}while(action>0);
	delete[] recieve; 	
	return 0;
}



















