#ifndef MEMORY_PAGE_H
#define MEMORY_PAGE_H

#include "memPage.h"

class memPage_t: public memManager_t{
	public:
		~memPage_t(){};
		memPage_t(): m_capacity(m_defCap);
		memPage_t(size_t capacity): m_capacity(capacity);
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
}

static size_t memPage_t::defCap=6;

virtual memPage_t::size_t read(void* buffer, size_t bytesToRead){
	
}

#endif
