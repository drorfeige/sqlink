#ifndef STREET_H
#define STREET_H

#include "building.h"
#include <stdlib.h>
#include <vector>

using namespace std;

template <class SID, class BID>
class Street_t{
	public:
		~Street_t(){}
		Street_t(){}
		Street_t(const Street_t& oldS);
		Street_t& operator=(const Street_t& oldS);
		inline void setStreetID(const SID& newS);
		inline SID& getStreetID() const;
		void AddBuilding2Street(const Building_t<BID>& newB);
		Building_t<BID>& getBuilding(BID& bid) const;
		inline size_t getSize() const;
	private:
		SID m_SID;
		vector<Building_t<BID> >sv;
};


template <class SID, class BID>
Street_t<SID,BID>::Street_t(const Street_t<SID,BID>& oldS){
	m_SID=oldS.m_SID;
	size_t i=0;
	for(i=0;i<oldS.getSize();i++){
		sv.push_back(oldS.getBuilding(i));
	}
}

template <class SID, class BID>
Street_t<SID,BID>& Street_t<SID,BID>::operator=(const Street_t<SID,BID>& oldS){
	m_SID=oldS.m_SID;
	size_t i=0;
	for(i=0;i<oldS.getSize();i++){
		sv.push_back(oldS.getBuilding(i));
	}
	return *this;
}


template <class SID, class BID>
inline void Street_t<SID,BID>::setStreetID(const SID& newS){
	m_SID=newS;
}

template <class SID, class BID>
inline SID& Street_t<SID,BID>::getStreetID() const{
	return &m_SID;
}

template <class SID, class BID>
void Street_t<SID,BID>::AddBuilding2Street(const Building_t<BID>& newB){
	sv.push_back(newB);
}

template <class SID, class BID>
Building_t<BID>& Street_t<SID,BID>::getBuilding(BID& bid) const{
	size_t i;
	for(i=0;i<getSize();i++){
		if(sv[i].getBuildingID()==bid){
			return &sv[i];
		}
	}
	throw i;
}

template <class SID, class BID>
inline size_t Street_t<SID,BID>::getSize() const{
	return sv.size();
}

#endif









