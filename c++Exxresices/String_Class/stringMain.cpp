#include <stdio.h>
#include "String.h"

int menu(){
	int choice;
	cout<< "choose option:\n\n0.exit\n1.setString\n2.getString\n3.getLength\n4.printString\n5.compare strings\n6.copy constructor\n7.copy from constant string\n8.string from equal operator\n9.convert to uppercase\n10.prepend\n11.append\n12.is string contained\n13.is string bigger\n14.shift in operator\n15.shift out operator\n16.subscript read\n17.subscript write\n";
	cin>>choice;
	return choice;
}

void recieveStr(char* rStr){
	cout<<"enter string:";
	cin>>rStr;
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
			case 9:
				{
					str1.toUpper();
					str1.print();
				}
				break;
			case 10:
				{
					recieveStr(recieve);
					String str10((const char*)recieve);
					str1.prepend(str10);
					str1.print();
				}
				break;
			case 11:
				{
					recieveStr(recieve);
					String str11((const char*)recieve);
					str1+=str11;
					str1.print();
				}
				break;
			case 12:
				{
					recieveStr(recieve);
					String str12((const char*)recieve);
					cout << str1.contains(str12);
				}
				break;
			case 13:
				{
					recieveStr(recieve);
					String str13((const char*)recieve);
					cout << (str13>str1);
				}
				break;
			case 14:
				{
					cin >> str1;
				}
				break;
			case 15:
				{
					cout << str1;
				}
				break;
			case 16:
				{
					cout << str1[3];
				}
				break;
			case 17:
				{
					str1[3]='z';
					cout << str1;
				}
				break;
			default:
				break;
		}
		cout << "\n";

	}while(action>0);
	delete[] recieve; 	
	return 0;
}



















