#include "tcontainer.h"
#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main(){
	tContainer_t<int, list<int*> > c1;
	cout << "is container empty: "<< c1.isEmpty() << "\n";
	for (int i=0; i<7; ++i){
		int* forCont= new int;
		*forCont=i;
		c1.insertEl(forCont);
	}
	cout << "is container empty: " << c1.isEmpty() << "\n";
	cout << "the number of elements is : " << c1.numOfElements() << "\n";
	cout << *c1[4] << "\n";
	int* test;
	test=(int*)c1.getFirst();
	cout << "the first element is: " << *test << "\n";
	test=(int*)c1.getLast();
	cout << "the last element is: " << *test << "\n";
	test=(int*)c1.getByVal(5);
	cout << "is five? " << *test << "\n";
	cout << "could delete 5? " << c1.deleteByVal(5) << "\n";
	cout << "could delete 5? " << c1.deleteByVal(5) << "\n";
	c1.deleteAll();
	
	return 0;
}





