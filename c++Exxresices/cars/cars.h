#ifndef CARS_H
#define CARS_H

#include<string>

using namespace std;

typedef enum{AUTOMATIC,STANDARD}GEAR; 

class car_t{
	public:
		car_t();
		car_t(unsigned int cap);	
		car_t(const car_t& cr);
		inline const string& getName() const{return m_name;}
		inline GEAR getGear() const{return m_gear;}
		inline bool operator<(const car_t& car2) const{return m_cc<car2.getCap();}
		car_t& operator=(const car_t& car2);
		inline bool compareCars(const car_t& car2){return m_name==car2.m_name;}
		inline unsigned int getCap() const{return m_cc;}
		inline unsigned int getId()const{return m_id;}
	protected:
		~car_t(){}
		inline void setName(string name){m_name=name;}
		inline void setGear(GEAR gear){m_gear=gear;}	
	private:
		unsigned int m_cc;
		string m_name;
		static unsigned int m_did;
		const unsigned int m_id;
		GEAR m_gear;
};
unsigned int car_t::m_did=0;

car_t::car_t(): m_id(m_did){
	m_cc=1500;
	m_did++;
}

car_t::car_t(unsigned int cap): m_id(m_did){
	m_cc=cap;
	m_did++;
}

car_t::car_t(const car_t& cr): m_id(m_did){
	m_cc=cr.m_cc;
	m_did++;
}

car_t& car_t::operator=(const car_t& car2){
	m_cc=car2.getCap();
	return *this;
}
#endif









