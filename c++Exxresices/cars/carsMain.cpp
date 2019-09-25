#include "cars.h"
#include "bus.h"
#include "private.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv){
	bus_t bus1;
	cout << bus1.getGear() << "\n";
	cout << bus1.getName() << "\n";
	cout << bus1.getCap() << "\n";
	cout << bus1.getId() << "\n";
	bus_t bus2(1800);
	cout << bus2.getGear() << "\n";
	cout << bus2.getName() << "\n";
	cout << bus2.getCap() << "\n";
	cout << bus2.getId() << "\n";
	bus_t bus3(bus2);
	cout << bus3.getGear() << "\n";
	cout << bus3.getName() << "\n";
	cout << bus3.getCap() << "\n";
	cout << bus3.getId() << "\n";
	bus2=bus1;
	cout << bus2.getGear() << "\n";
	cout << bus2.getName() << "\n";
	cout << bus2.getCap() << "\n";
	cout << bus2.getId() << "\n";
	cout << "--------\n";
	cout << (bus2<bus1) << "\n";
	cout << (bus2<bus3) << "\n";
	cout << bus1.compareCars(bus2) << "\n";
	private_t private1;
	cout << bus1.compareCars(private1) << "\n";
	cout << "--------\n";
	cout << bus1.getNOS() << "\n";
	cout << bus1.getLN() << "\n";
	bus1.setNOS(55);
	bus1.setLN(26);
	cout << bus1.getNOS() << "\n";
	cout << bus1.getLN() << "\n";
	return 0;
}
