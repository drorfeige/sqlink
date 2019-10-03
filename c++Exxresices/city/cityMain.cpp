#include "city.h"
#include <iostream>

int main(){
	City_t<int,long,float> c1;
	Street_t<long,float> s1;
	Building_t<float> b1;
	b1.setBuidingID(5.43);
	float f1=b1.getBuildingID();
	/*cout << b1.getBuildingID() << "\n";
	cout << s1.getSize() << "\n";
	s1.AddBuilding2Street(b1);
	cout << s1.getSize() << "\n";
	s1.setStreetID(543789);
	c1.AddStreet(s1);
	long l1=s1.getStreetID();
	Street_t<long,float> s2;
	s2=c1.getStreet(l1);
	cout << s2.getStreetID() << "\n";*/
	return 0;
}
