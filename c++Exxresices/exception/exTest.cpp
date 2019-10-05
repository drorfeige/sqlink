#include "exception_t.h"
#include <string>
#include <iostream>

using namespace std;

void throwTest(){
	TException_t<float> tOb(__FILE__,__LINE__,"a float was thrown as a test",5.43);
	throw tOb;

}

int main(){
	try{
		throwTest();
	}catch(TException_t<float> cOb){
		cout<< cOb.getSource()<<"\n";
		cout<< cOb.getLine()<< "\n";
		cout<< cOb.getDescript()<< "\n";
		cout<< cOb.getObject()<< "\n";
	}
	return 0;
}


























