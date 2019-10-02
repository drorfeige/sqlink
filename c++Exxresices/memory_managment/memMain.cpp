#include "memPool.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

int memType(){
	cout << "0 to exit\n1 for page\n2 for pool\n";
	int i;
	cin >> i;
	return i;
}

void memTest(memManager_t& memory){
	char* rBuff=(char*)calloc(512,sizeof(char));
	char* wBuff=(char*)calloc(512,sizeof(char));
	string s="this is a test";
	strcpy(wBuff,s.c_str());
	cout << "wrote to memory " <<memory.write(wBuff,14)<< " bytes\n";
	cout << "actual size of memory is" << memory.getActSize() << " bytes\n";
	cout << "read from memory " <<memory.read(rBuff,20,0)<< " bytes\n";
	cout << rBuff << "\n";
	free(rBuff);
	free(wBuff);
}

int main(int argc, char** argv){
	int choice=3;
	while(choice){
		choice=memType();
		switch(choice){
			case 1:
				{ 
					memPage_t pa;
					memTest(pa);
					break;
				}
			case 2: 
				{
					memPool_t po;
					memTest(po);
					break;
				}
			default:
				break;
		}
	}

	return 0;
}

/* 
	char* rBuff=(char*)calloc(512,sizeof(char));
	char* wBuff=(char*)calloc(512,sizeof(char));
	memPage_t p1;
	memPage_t p2(512);
	//cout << "capacity test\n";
	//cout << p1.getCap()<< "\n";
	//cout << p2.getCap()<< "\n";
	memPage_t::setDefCap(1024);
	memPage_t p3;
	//cout << p3.getCap()<< "\n";
	//cout << "write test\n";
	string s="this is a test";
	strcpy(wBuff,s.c_str());
	cout << p2.write(wBuff,14)<< "\n";
	cout << p1.write(wBuff,14)<< "\n";
	//cout << p2.getPos()<< "\n";
	//cout << p2.getActSize()<< "\n";
	cout << p1.read(rBuff,10) << "\n";
	cout << rBuff << "\n";
	p1.setPos(0);
	cout << p1.read(rBuff,10) << "\n";
	cout << rBuff << "\n";
	memset(rBuff,0,100);
	cout << p2.read(rBuff,10,7) << "\n";
	cout << rBuff << "\n";
	cout << "second part of test\n";
	s="this is test number 2";
	strcpy(wBuff,s.c_str());
	cout << p2.write(wBuff,19,14)<< "\n";
	cout << p2.read(rBuff,33,0) << "\n";
	cout << rBuff << "\n";
	cout << "third part of test\n";
	int i=60000;
	int* ip=&i;
	cout << p1.write(ip,2,4)<< "\n";
	memset(rBuff,0,100);
	cout << p1.read(rBuff,10,4) << "\n";
	cout << rBuff << "\n";
	free(rBuff);
	free(wBuff);
*/








