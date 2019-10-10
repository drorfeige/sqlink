#ifndef MEETING_H
#define MEETING_H

#include <string>

using namespace std;

class meeting_t{
	public:
		virtual ~meeting_t(){}
		meeting_t(const float& begin, const float& end, const string& subject);
		meeting_t(const meeting_t& oldM);
		const string& getSubject() const{return m_subject;}
		const float& getBegin() const{return m_begin;}
		const float& getEnd() const{return m_end;}
		void setSubject(const string& newS);
	private:
		meeting_t& operator=(const meeting_t& oldM);
		const float m_begin;
		const float m_end;
		string m_subject;
		
};


#endif










