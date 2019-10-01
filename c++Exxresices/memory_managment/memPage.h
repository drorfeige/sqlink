#ifndef MEMORY_PAGE_H
#define MEMORY_PAGE_H

#include "memPage.h"

class memPage_t: public memManager_t{
	public:
		~memPage_t(){delete m_page};
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
		const size_t m_capacity;
		static size_t m_defCap;	
		char* m_page;	
}

static size_t memPage_t::defCap=6;

virtual memPage_t::size_t read(void* buffer, size_t bytesToRead){
	size_t begin=getPos();
	size_t end=getActSize();
	if(begin<end){
		size_t actToRead=end-begin;
		if(bytesToRead<actToRead){
			actToRead=bytesToRead;
		}
		memcpy(m_page[begin],buffer,actToRead);
		setPos(begin+actToRead);
		return actToRead;		
	}
	return 0;
}

virtual memPage::size_t read(void* buffer, size_t bytesToRead, size_t pos){
	size_t end=getActSize();
	if(pos<end){
		size_t actToRead=end-pos;
		if(bytesToRead<actToRead){
			actToRead=bytesToRead;
		}
		memcpy(m_page[begin],buffer,actToRead);
		setPos(pos+actToRead);
		return actToRead;		
	}
	return 0;
}

virtual memPage::size_t write(const void* buffer, size_t bytesToWrite){
	size_t begin=getPos();
	size_t end=getCap();
	if(begin<end){
		size_t actToWrite=end-begin;
		if(bytesToWrite<actToWrite){
			actToRead=bytesToRead;
		}
		memcpy(buffer,m_page[begin],actToWrite);
		setPos(begin+actToWrite);
		return actToWrite;		
	}
	return 0;
}
virtual memPage::size_t write(const void* buffer, size_t bytesToWrite, size_t pos){
	size_t begin=getPos();
	if(begin<pos){
		return 0;
	}
	begin=pos; 
	size_t end=getCap();
	if(begin<end){
		size_t actToWrite=end-begin;
		if(bytesToWrite<actToWrite){
			actToRead=bytesToRead;
		}
		memcpy(buffer,m_page[begin],actToWrite);
		setPos(begin+actToWrite);
		return actToWrite;		
	}
	return 0;
}

#endif
