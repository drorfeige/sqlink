#include "meeting.h"
#include <string>

using namespace std;

meeting_t::meeting_t(const float& begin, const float& end,const string& subject=""):m_begin(begin),m_end(end){
	if(begin<0 || begin>=24){
		throw 1;
	}	
	if(end>begin && end<=24){
		throw 2;
	}
	m_subject=subject;
}

meeting_t::meeting_t(const meeting_t& oldM):m_begin(oldM.m_begin),m_end(oldM.m_end){
	m_subject=oldM.m_subject;
}

void meeting_t::setSubject(const string& newS){
	m_subject=newS;
}

























