#ifndef CITY_H
#define CITY_H

#include "street.h"
#include <stdlib.h>
#include <vector>

using namespace std;

template <class CID,class SID, class BID>
class City_t{
	public:
		~City_t(){}
		City_t(){}
		City_t(const City_t& oldC);
		City_t& operator=(const City_t& oldC);
		inline void setCityID(const CID newC);
		inline CID getCityID() const;
		void AddStreet(const Street_t<SID,BID>& newS);
		Street_t<SID,BID>& getStreet(SID sid) const;
		inline size_t getSize() const;
	private:
		CID m_CID;
		vector<Street_t<SID,BID> >cv;
};

template <class CID,class SID, class BID>
City_t<CID, SID, BID>::City_t(const City_t& oldC){
	m_CID=oldC.m_CID;
	size_t i=0;
	for(i=0;i<oldC.getSize();i++){
		cv.push_back(oldC.getBuilding(i));
	}
}

template <class CID,class SID, class BID>
City_t< CID, SID, BID>& City_t<CID, SID, BID>::operator=(const City_t& oldC){
	m_CID=oldC.m_CID;
	size_t i=0;
	for(i=0;i<oldC.getSize();i++){
		cv.push_back(oldC.getBuilding(i));
	}	
	return *this;
}

template <class CID,class SID, class BID>
inline void City_t< CID, SID, BID>::setCityID(const CID newC){
	m_CID=newC;
}

template <class CID,class SID, class BID>
inline CID City_t< CID, SID, BID>::getCityID() const{
	return m_CID;
}

template <class CID,class SID, class BID>
void City_t<CID, SID, BID>::AddStreet(const Street_t<SID,BID>& newS){
	cv.push_back(newS);
}

template <class CID,class SID, class BID>
Street_t<SID,BID>& City_t<CID, SID, BID>::getStreet(SID sid) const{
	size_t i;
	for(i=0;i<getSize();i++){
		if(cv[i].getStreetID()==sid){
			return cv[i];
		}
	}
	throw i;
}

template <class CID,class SID, class BID>
inline size_t City_t<CID, SID, BID>::getSize() const{
	return cv.size();
}


#endif













