#include "exception_t.h"
#include <string>
#include <iostream>

using namespace std;

void throwTest(){
	throw TException_t<float>(5.43,__FILE__,__LINE__,"a float was thrown as a test");

}

int main(){
	try{
		throwTest();
	}catch(TException_t<float> cOb){
		cout<< cOb.getObject()<< "\n";
		cout<< cOb.getSource()<<"\n";
		cout<< cOb.getLine()<< "\n";
		cout<< cOb.getDescript()<< "\n";
	}
	return 0;
}


























