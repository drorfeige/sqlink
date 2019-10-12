#ifndef CALENDER_H
#define CALENDER_H

#include "meeting.h"
#include <map>

class calender_t{
	public:
		virtual ~calender_t(){cleanAD();}
		calender_t(){}
		calender_t(const calender_t& oldC);
		calender_t& operator=(const calender_t& oldC);
		bool insertApp(meeting_t* newM);
		meeting_t* removeApp(float start);
		const meeting_t* findApp(float start) const;
		void cleanAD();
	private:
		typedef typename map<float,meeting_t*>::iterator iter_t;
		typedef typename map<float,meeting_t*>::const_iterator c_iter_t;
		map<float,meeting_t*> m_mm;
};


#endif







