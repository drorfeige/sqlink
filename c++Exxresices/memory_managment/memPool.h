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
		size_t internalWrite(const void* buffer, size_t bytesToWrite, size_t begin);
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
	size_t begin=getPos();
	return read( buffer, bytesToRead, begin);
}

size_t memPool_t::read(void* buffer, size_t bytesToRead, size_t pos){
	size_t end=getActSize();
	if(pos>=end || bytesToRead==0){
		return 0;
	}
	// if there is then how many bytes are there to read
	size_t actToRead=(bytesToRead<(end-pos))?bytesToRead:end-pos;
	// find start page
	bool isGood=1;
	while(isGood){
		try{	
			isGood=0;
			setPos(pos+actToRead);
		}catch(size_t max){
			isGood=1;
			actToRead=max-pos;
		}
	}
	size_t position;
	size_t pi=pageNum(pos,&position);
	// read page by page in a loop
	size_t remain=actToRead;
	size_t offset=0;
	offset=offset+v[pi]->read(buffer,remain,position);
	remain=actToRead-offset;
	pi++;
	while(remain>0){
		offset=offset+v[pi]->read((char*)buffer+offset,remain,0);
		remain=actToRead-offset;
		pi++;
	}
	return actToRead;
}

size_t memPool_t::write(const void* buffer, size_t bytesToWrite){
	size_t begin=getPos();
	return internalWrite(buffer, bytesToWrite, begin);
}

size_t memPool_t::write(const void* buffer, size_t bytesToWrite, size_t pos){
	size_t begin=getPos();
	if(begin<pos){
		return 0;
	}
	begin=pos;
	return internalWrite(buffer, bytesToWrite, begin);
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

size_t memPool_t::internalWrite(const void* buffer, size_t bytesToWrite, size_t begin){
	size_t position;
	size_t pi=pageNum(begin,&position);
	// read page by page in a loop
	size_t remain=bytesToWrite;
	size_t offset=0;
	offset+=v[pi]->write(buffer,remain,position);
	remain=bytesToWrite-offset;
	pi++;	
	while(remain>0){
		if(pi==v.size()){
			memPage_t* pg=new memPage_t();
			v.push_back(pg);
		}
		offset+=v[pi]->write((char*)buffer+offset,remain);
		remain=bytesToWrite-offset;
		pi++;
	}
	if(begin+bytesToWrite>getActSize()){
		setActSize(begin+bytesToWrite);
	}
	try{
		setPos(begin+bytesToWrite);
	}catch(size_t){
	}
	return bytesToWrite;		
}


#endif 



/* 
v.size()
v[i]
*/
