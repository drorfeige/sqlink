#include "calender.h"
#include <stdlib.h>
#include <string>


calender_t::calender_t(const calender_t& oldC){
	iter_t it;
	for(it=oldC.m_mm.begin();it!=oldC.m_mm.begin();it++){
	insertApp(it->second);
	}
}

calender_t::calender_t& operator=(const calender_t& oldC){
	if(this!=&oldC){
		cleanAD();
		for(it=olC.m_mm.begin();it!=oldC.m_mm.begin();it++){
			insertApp(it->second);
		}
	}
	return *this;
}

void calender_t::cleanAD(){
	iter_t it;
	while(!pCont.empty()){
		it=pCont.begin();
		delete *it;
		m_mm.erase(it);
	}
}

const meeting_t* calender_t::findApp(float start) const{
	iter_t it=m_mm.find(m_mm.begin(),m_mm.end(),start);
	if(it==m_mm.end()){
		return 0;
	}
	return it->second;		
}

meeting_t* calender_t::removeApp(float start){
	iter_t it=m_mm.find(m_mm.begin(),m_mm.end(),start);
	if(it==m_mm.end()){
		return 0;
	}
	meeting_t* temp=*it;
	return temp;
}

bool calender_t::insertApp(const meeting_t* newM){
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
	if(newM->getEnd() <= *(m_mm.begin())->getBegin()){/*case of meeting in the begining*/
		m_mm[newM->getBegin()]=newM;
		return 1;
	}
	if(newM->getBegin() >= *(m_mm.rbegin())->getBegin()){/*case of meeting being at the end*/
		m_mm[newM->getBegin()]=newM;
		return 1;
	}
	/*case of meeting being in the middle*/
	else{
		iter_t it;
		for(it=m_mm.begin();it!=m_mm.end();i++){
			if(meeting_t->getBegin() > *(it)->getEnd()){
				if((it+1)!=m_mm.end()){
					if((*(it+1)->getBegin()) >= meeting_t->getEnd()){
						break;
					}
					else{
						return 0;
					{
				}
			}					
		}
	}
	/*insert meeting */
	m_mm[newM->getBegin()]=newM;				
	return 1;
}


void calender_t::copyToFile(const char* fileName) const{
	if(fileName==0){
		return;
	}
	FILE* filePt;
	if(((filePt=fopen(fileName,"w"))==0)){
		return;
	}
	iter_t it;
	for(it=m_mm.begin();it!=m_mm.end();it++){
		fprintf(filePt,"%f %f %s\n",*it->getBegin(),*it->getBegin(),,*it->getSubject());
	}
	fclose(filePt);
}

bool calender_t::getFromFile(const char* fileName){
	string subject;
	float startTime=0;
	float stopTime=0;
	FILE* filePt;
	//validate filename
	if(fileName==0){
		return;
	}
	/*can we open file*/
	if((filePt=fopen(fileN,"r"))==NULL){
		return 0;
	}
	/*while there is something to read*/
	while(!feof(filePt)){
		fscanf(filePt,"%f%f%s",&startTime,&stopTime,&subject);
		if(!feof(filePt)){
			meeting_t newMeet= new meeting_t;
			/*if we succesfully allocated memory for new meeting*/
			newMeet->m_begin=startTime;
			newMeet->m_end=stopTime;
			newMeet->m_subject=subject;
			insertApp(newMeet);
		}
	}
	fclose(filePt);	
	return 1;
}




