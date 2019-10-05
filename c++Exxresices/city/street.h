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
		inline const SID& getStreetID() const;
		void AddBuilding2Street(const Building_t<BID>& newB);
		const Building_t<BID>& getBuilding(const BID& bid) const;
		inline size_t getSize() const;
		const Building_t<BID>& operator[](size_t index) const;
	private:
		SID m_SID;
		vector<Building_t<BID> >sv;
		void createFrom(const Street_t& oldS);
};


template <class SID, class BID>
Street_t<SID,BID>::Street_t(const Street_t<SID,BID>& oldS){
	createFrom(oldS);
}

template <class SID, class BID>
Street_t<SID,BID>& Street_t<SID,BID>::operator=(const Street_t<SID,BID>& oldS){
	sv.clear();
	createFrom(oldS);
	return *this;
}


template <class SID, class BID>
inline void Street_t<SID,BID>::setStreetID(const SID& newS){
	m_SID=newS;
}

template <class SID, class BID>
inline const SID& Street_t<SID,BID>::getStreetID() const{
	return m_SID;
}

template <class SID, class BID>
void Street_t<SID,BID>::AddBuilding2Street(const Building_t<BID>& newB){
	sv.push_back(newB);
}

template <class SID, class BID>
const Building_t<BID>& Street_t<SID,BID>::getBuilding(const BID& bid) const{
	size_t i;
	for(i=0;i<getSize();i++){
		if(sv[i].getBuildingID()==bid){
			return sv[i];
		}
	}
	throw i;
}

template <class SID, class BID>
inline size_t Street_t<SID,BID>::getSize() const{
	return sv.size();
}

template <class SID, class BID>
const Building_t<BID>& Street_t<SID,BID>::operator[](size_t index) const{
	if(index>=sv.size()){
		throw sv.size();
	}
	return sv[index];
}

template <class SID, class BID>
void Street_t<SID,BID>::createFrom(const Street_t<SID,BID>& oldS){
	m_SID=oldS.getStreetID();
	size_t i=0;
	for(i=0;i<oldS.getSize();i++){
		sv.push_back(oldS[i]);
	}
}

#endif









