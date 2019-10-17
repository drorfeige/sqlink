#include "calender.h"
#include "meeting.h"
#include <algorithm>
#include <map>

using namespace std;

calender_t::calender_t(const calender_t& oldC){
	c_iter_t it;
	for(it=oldC.m_mm.begin();it!=oldC.m_mm.end();it++){
	meeting_t nm(*(it->second));
	insertApp(&nm);
	}
}

calender_t& calender_t::operator=(const calender_t& oldC){
	if(this!=&oldC){
		cleanAD();
		c_iter_t it;
		for(it=oldC.m_mm.begin();it!=oldC.m_mm.end();it++){
			meeting_t nm(*(it->second));
			insertApp(&nm);
		}
	}
	return *this;
}

void calender_t::cleanAD(){
	iter_t it;
	while(!m_mm.empty()){
		it=m_mm.begin();
		delete it->second;
		m_mm.erase(it);
	}
}

const meeting_t* calender_t::findApp(float start) const{
	c_iter_t it=m_mm.find(start);
	if(it==m_mm.end()){
		return 0;
	}
	return it->second;		
}

meeting_t* calender_t::removeApp(float start){
	iter_t it=m_mm.find(start);
	if(it==m_mm.end()){
		return 0;
	}
	meeting_t* temp=it->second;
	m_mm.erase(start);
	return temp;
}

bool calender_t::insertApp(meeting_t* newM){
	iter_t it;
	// validate pointer
	if(newM==0){
		return 0;
	}
	/*case of empty array*/
	if((m_mm.empty()!=0)){
		m_mm[newM->getBegin()]=newM;
		return 1;
	}
	/* search if there is a valid time for the meeting */
	if(newM->getEnd() <= m_mm.begin()->second->getBegin()){/*case of meeting in the begining*/
		m_mm[newM->getBegin()]=newM;
		return 1;
	}
	if(newM->getBegin() >= m_mm.rbegin()->second->getBegin()){/*case of meeting being at the end*/
		m_mm[newM->getBegin()]=newM;
		return 1;
	}
	/*case of meeting being in the middle*/
	else{
		iter_t it;
		for(it=m_mm.begin();it!=m_mm.end();it++){
			if(newM->getBegin() > it->second->getEnd()){
				it++;
				if(it!=m_mm.end()){
					if(it->second->getBegin() >= newM->getEnd()){
						m_mm[newM->getBegin()]=newM;
						return 1;
					}
					else{
						return 0;
					}
				}
			}					
		}
	}
	return 0;
}






