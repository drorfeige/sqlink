#ifndef PRIVATE_H
#define PRIVATE_H

#include "cars.h"

using namespace std;


class private_t:public car_t{

	public:
		~private_t();
		private_t();
		private_t(unsigned int cap);
		private_t(const private_t& car2);
		inline void accelerate(){kmph+=10;}
		inline bool reduceSpeed();
		inline unsigned int getSpeed() const{return kmph;}
	private:
		unsigned int kmph;	
};

inline bool private_t::reduceSpeed(){
	if(kmph>0){
		kmph-=10;
		return true;
	}
	return false;
}
private_t::~private_t(){
}

private_t::private_t(){
	setName("private");
	setGear(AUTOMATIC);
	kmph=0;
}

private_t::private_t(unsigned int cap): car_t(cap){
	setName("private");
	setGear(AUTOMATIC);
	kmph=0;
}
private_t::private_t(const private_t& car2): car_t(car2){
	setName("private");
	setGear(AUTOMATIC);
	kmph=0;
}

#endif



























