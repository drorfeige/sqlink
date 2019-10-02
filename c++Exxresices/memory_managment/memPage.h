#ifndef MEMORY_PAGE_H
#define MEMORY_PAGE_H

#include "memPage.h"
#include <stdlib.h>
#include <string.h>

class memPage_t: public memManager_t{
	public:
		~memPage_t(){delete m_page;}
		memPage_t(): m_capacity(m_defCap){m_page= new char[m_capacity];}
		memPage_t(size_t capacity): m_capacity(capacity){m_page= new char[m_capacity];}
		inline static void setDefCap(size_t capacity){m_defCap=capacity;}
		inline static size_t getDefCap(){return m_defCap;}	
		virtual size_t read(void* buffer, size_t bytesToRead);
		virtual size_t read(void* buffer, size_t bytesToRead, size_t pos);
		virtual size_t write(const void* buffer, size_t bytesToWrite);
		virtual size_t write(const void* buffer, size_t bytesToWrite, size_t pos);
		inline size_t getCap() const{return m_capacity;}	
	private:
		size_t internalWrite(const void* buffer, size_t bytesToWrite, size_t begin);
		const size_t m_capacity;
		static size_t m_defCap;	
		char* m_page;	
};

size_t memPage_t::m_defCap=6;

size_t memPage_t::read(void* buffer, size_t bytesToRead){
	size_t begin=getPos();
	return read(buffer, bytesToRead, begin);
}

size_t memPage_t::read(void* buffer, size_t bytesToRead, size_t pos){
	size_t end=getActSize();
	if(pos<end){
		size_t actToRead=end-pos;
		if(bytesToRead<actToRead){
			actToRead=bytesToRead;
		}
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
		memcpy(buffer,&m_page[pos],actToRead);
		return actToRead;		
	}
	return 0;
}

size_t memPage_t::write(const void* buffer, size_t bytesToWrite){
	size_t begin=getPos();
	return internalWrite(buffer, bytesToWrite, begin);
}
size_t memPage_t::write(const void* buffer, size_t bytesToWrite, size_t pos){
	size_t begin=getPos();
	if(begin<pos){
		return 0;
	}
	begin=pos; 
	return internalWrite(buffer, bytesToWrite, begin);
}

size_t memPage_t::internalWrite(const void* buffer, size_t bytesToWrite, size_t begin){
	size_t end=getCap();
	if(begin<end){
		size_t actToWrite=end-begin;
		if(bytesToWrite<actToWrite){
			actToWrite=bytesToWrite;
		}
		memcpy(&m_page[begin],buffer,actToWrite);
		if(begin+actToWrite>getActSize()){
			setActSize(begin+actToWrite);
		}
		try{
			setPos(begin+actToWrite);
		}catch(size_t){
		}
		return actToWrite;		
	}
	return 0;
}

#endif
