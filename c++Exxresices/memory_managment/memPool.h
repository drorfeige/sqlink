#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include "memMan.h"
#include "memPage"
#include <vector>

using namespace std;

class memPool_t: public memManager_t{
	public:
		~memPool_t();
		memPool_t(){memPage_t* pg new Page_t;v.push_back(pg);}
		virtual size_t read(void* buffer, size_t bytesToRead);
		virtual size_t read(void* buffer, size_t bytesToRead, size_t pos);
		virtual size_t write(const void* buffer, size_t bytesToWrite);
		virtual size_t write(const void* buffer, size_t bytesToWrite, size_t pos);
		//set page size
		// get page size
	private:
		vector<memPage_t*>v;
		
}

memPool_t::~memPool_t(){
	size_t i=0;
	for(i=0;i<v.size();i++){
		delete v[i];
	}
}

#endif 



/* 
v.size()
v[i]
*/
