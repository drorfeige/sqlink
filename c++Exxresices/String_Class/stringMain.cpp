#include <stdio.h>
#include "String.h"

int menu(){
	int choice;
	cout<< "choose option:\n\n0.exit\n1.setString\n2.getString\n3.getLength\n4.printString\n5.compare strings\n6.copy constructor\n7.copy from constant string\n8.string from equal operator\n9.convert to uppercase\n10.prepend\n11.append\n12.is string contained\n13.is string bigger\n14.shift in operator\n15.shift out operator\n16.subscript read\n17.subscript write\n18.get number of Strings\n19.get first appearance\n20.get last apearance\n21.create substring\n22.get case sensitive flag\n23.set case sensitive flag\n24.get capacity\n25.set capacity\n26.get object capacity\n";
	cin>>choice;
	return choice;
}

void recieveStr(char* rStr){
	cout<<"enter string:";
	cin>>rStr;
}

char recieveCh(){
	char c;
	cout << "enter char\n";
	cin >> c;
	return c;
}
unsigned int recieveUint(){
	unsigned int ui;
	cin >> ui;
	return ui;
}
int main(int argc,char** argv){
	int action;
	char ch='\0';
	char* recieve=new char[32];
	cout << "number of strings is:"<< String::nOfString() << "\n";
	String str1("string from constant char");
	do{
		action=menu();
		switch (action){
			case 1:
				recieveStr(recieve);
				//printf("%s\n",recieve);
				str1.setString(recieve);
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
				printf("%d\n",str1.myStrcmp(recieve));
				break;
			case 6:
				{
					String str6(str1);
					str6.print();
				}
				break;
			case 7:
				{
					String str7(str1.getString());
					str7.print();
				}
				break;
			case 8:
				{
					String str8=str1;
					str8.print();
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
					String str10(recieve);
					str1.prepend(str10);
					str1.print();
				}
				break;
			case 11:
				{
					recieveStr(recieve);
					String str11(recieve);
					str1+=str11;
					str1.print();
				}
				break;
			case 12:
				{
					recieveStr(recieve);
					String str12(recieve);
					cout << str1.contains(str12);
				}
				break;
			case 13:
				{
					recieveStr(recieve);
					String str13(recieve);
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
			case 18:
				{
					cout << String::nOfString();
				}
				break;
			case 19:
				{
					ch=recieveCh();
					cout << str1.fisrtIndex(ch);
				}
				break;
			case 20:
				{
					ch=recieveCh();
					cout << str1.lastIndex(ch);
				}
				break;
			case 21:
				{
					unsigned int st=0;
					unsigned int length=0;
					cout << "enter start index\n";
					st=recieveUint();
					cout << "enter length:\n";
					length=recieveUint();
					str1(st,length).print();
				}
				break;
			case 22:
				{
					cout << String::getCaseSens();
				}
				break;
			case 23:
				{
					bool flag=(bool)recieveUint();
					String::setCaseSens(flag);
				}
				break;
			case 24:
				{
					cout << String::getCap();
				}
				break;
			case 25:
				{
					size_t sz=(size_t)recieveUint();					
					String::setCap(sz);
				}
				break;
			case 26:
				{
					cout << str1.getPrivateCap();
				}
			default:
				break;
		}
		cout << "\n";

	}while(action>0);
	delete[] recieve; 	
	return 0;
}



















