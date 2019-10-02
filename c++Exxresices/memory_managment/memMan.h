#ifndef MEM_MANAGER_H
#define MEM_MANAGER_H

#include <stdlib.h>

class memManager_t{
	public:
		memManager_t(){m_actualSize=0;m_currPosition=0;}
		virtual size_t read(void* buffer, size_t bytesToRead)=0;
		virtual size_t read(void* buffer, size_t bytesToRead, size_t pos)=0;
		virtual size_t write(const void* buffer, size_t bytesToWrite)=0;
		virtual size_t write(const void* buffer, size_t bytesToWrite, size_t pos)=0;
		inline bool isEmpty() const{return m_actualSize==0;}
		inline size_t getActSize() const{return m_actualSize;}
		inline size_t getPos() const{return m_currPosition;}
		inline void setPos(size_t newPos);	
	protected:
		virtual ~memManager_t(){};
		inline void setActSize(size_t newSize){m_actualSize=newSize;}
	private:
		size_t m_actualSize;
		size_t m_currPosition;
};

inline void memManager_t::setPos(size_t newPos){
	if(newPos<=m_actualSize){
		m_currPosition=newPos;			
	}
	else{
		throw(m_actualSize);
	}	
}

#endif 







