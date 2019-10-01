#ifndef MEM_MANAGER_H
#define MEM_MANAGER_H

class memManager_t{
	public:
		memManager_t(){m_actualSize=0;m_currPosition=0;}
		virtual size_t read(void* buffer, size_t bytesToRead){return 0;}
		virtual size_t read(void* buffer, size_t bytesToRead, size_t pos){return 0;}
		virtual size_t write(const void* buffer, size_t bytesToWrite){return 0;}
		virtual size_t write(const void* buffer, size_t bytesToWrite, size_t pos){return 0;}
		inline bool isEmpty() const{return m_actualSize==0;}
		inline size_t getActSize() const{return m_actualSize;}
		inline size_t getPos() const{return m_currPosition;}
		inline bool setPos(size_t newPos);	
	protected:
		virtual ~memManager_t(){};
		inline void setActSize(size_t newSize){m_actualSize=newSize;}
	private:
		size_t m_actualSize;
		size_t m_currPosition;
}

inline bool memManager::setPos(size_t newPos){
	if(newPos<m_actualSize){
		m_currPosition=newPos;
		return TRUE;			
	}
	return FALSE;	
}

#endif 







