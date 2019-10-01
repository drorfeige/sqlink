#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include "memMan.h"
#include "memPage.h"
#include <vector>
#include <stdlib.h>

using namespace std;

class memPool_t: public memManager_t{
	public:
		~memPool_t();
		memPool_t(){memPage_t* pg=new memPage_t();v.push_back(pg);}
		virtual size_t read(void* buffer, size_t bytesToRead);
		virtual size_t read(void* buffer, size_t bytesToRead, size_t pos);
		virtual size_t write(const void* buffer, size_t bytesToWrite);
		virtual size_t write(const void* buffer, size_t bytesToWrite, size_t pos);
		//set page size
		// get page size
	private:
		size_t pageNum(size_t index, size_t* position) const;
		vector<memPage_t*>v;
		
};

memPool_t::~memPool_t(){
	size_t i=0;
	for(i=0;i<v.size();i++){
		delete v[i];
	}
}

size_t memPool_t::read(void* buffer, size_t bytesToRead){
	// check if there is something to read
	size_t begin=getPos();
	size_t end=getActSize();
	if(begin<=end || bytesToRead==0){
		return 0;
	}
	// if there is then how many bytes are there to read
	size_t actToRead=(bytesToRead<(end-begin))?bytesToRead:end-begin;
	// find start page
	size_t position;
	size_t pi=pageNum(actToRead,&position);
	// read page by page in a loop
	size_t remain=actToRead;
	remain-=v[pi]->read(buffer,remain,position);
	pi++;
	while(remain>0){
		remain-=v[pi]->read(buffer,remain);
		pi++;
	}
	return actToRead;
}
size_t memPool_t::read(void* buffer, size_t bytesToRead, size_t pos){
		size_t end=getActSize();
	if(pos<=end || bytesToRead==0){
		return 0;
	}
	// if there is then how many bytes are there to read
	size_t actToRead=(bytesToRead<(end-pos))?bytesToRead:end-pos;
	// find start page
	size_t position;
	size_t pi=pageNum(actToRead,&position);
	// read page by page in a loop
	size_t remain=actToRead;
	remain-=v[pi]->read(buffer,remain,position);
	pi++;
	while(remain>0){
		remain-=v[pi]->read(buffer,remain);
		pi++;
	}
	return actToRead;
}
size_t memPool_t::write(const void* buffer, size_t bytesToWrite){
	return 0;
}
size_t memPool_t::write(const void* buffer, size_t bytesToWrite, size_t pos){
	return 0;
}

size_t memPool_t::pageNum(size_t index, size_t* position) const{
	size_t i=0;
	size_t sz;
	while(1){
		sz=v[i]->getActSize();
		if(index>sz){
			index-=sz;
		}
		else{
			*position=index;
			break;
		}
		i++;
	}
	return i;
}

#endif 



/* 
v.size()
v[i]
*/
