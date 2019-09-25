#ifndef BUS_H
#define BUS_H
#include "cars.h"

using namespace std;

class bus_t:public car_t{
	public:
		~bus_t();
		bus_t();
		bus_t(unsigned int cap);
		bus_t(const bus_t& car2);
		inline unsigned int getNOS() const{return m_numOfSeats;}
		inline unsigned int getLN() const{return m_lineNum;}
		inline void setNOS(unsigned int nos){m_numOfSeats=nos;}
		inline void setLN(unsigned int ln){m_lineNum=ln;}
	private:
		unsigned int m_numOfSeats;
		unsigned int m_lineNum;
};

bus_t::~bus_t(){}

bus_t::bus_t(){
	setName("bus");
	setGear(STANDARD);
	m_numOfSeats=0;
	m_lineNum=0;
}

bus_t::bus_t(unsigned int cap): car_t(cap){
	setName("bus");
	setGear(STANDARD);
	m_numOfSeats=0;
	m_lineNum=0;
}

bus_t::bus_t(const bus_t& car2): car_t(car2){
	setName("bus");
	setGear(STANDARD);
	m_numOfSeats=0;
	m_lineNum=0;
}

#endif 




























