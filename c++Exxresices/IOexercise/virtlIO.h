#ifndef VIRTLIO_H
#define VIRTLIO_H

#include <stdio.h>

typedef enum{ok_e , cant_open_file_e , bad_access_e , writeErr_e , readErr_e }IOstatus;

class virtlIO_t{
	public:
		virtlIO_t(){}
		virtlIO_t(const char* name, const char* mode);
		const IOstatus& getStatus()const{return m_status;}
		void setStatus(const IOstatus& newSt);
		size_t getPos()const;
		bool setPos(size_t pos);
		void close();
		bool open();
		virtual virtlIO_t& operator <<(int var)=0; 
		virtual virtlIO_t& operator <<(unsigned int var)=0;
		virtual virtlIO_t& operator <<(unsigned short var)=0;
		virtual virtlIO_t& operator <<(short var)=0;
		virtual virtlIO_t& operator <<(long var)=0;
		virtual virtlIO_t& operator <<(unsigned long var)=0;
		virtual virtlIO_t& operator <<(char var)=0;
		virtual virtlIO_t& operator <<(unsigned char var)=0;
		virtual virtlIO_t& operator <<(float var)=0;
		virtual virtlIO_t& operator <<(double var)=0;
		virtual const virtlIO_t& operator>>(int& var)=0;
		virtual const virtlIO_t& operator>>(unsigned int& var)=0;
		virtual const virtlIO_t& operator>>(short& var)=0;
		virtual const virtlIO_t& operator>>(unsigned short& var)=0;
		virtual const virtlIO_t& operator>>(long& var)=0;
		virtual const virtlIO_t& operator>>(unsigned long& var)=0;
		virtual const virtlIO_t& operator>>(char& var)=0;
		virtual const virtlIO_t& operator>>(unsigned char& var)=0;
		virtual const virtlIO_t& operator>>(double& var)=0;
		virtual const virtlIO_t& operator>>(float& var)=0;
	
	protected:
		virtual ~virtlIO_t();
		FILE* m_file;
		char m_mode[4];
	private:
		virtlIO_t(const virtlIO_t& newV);
		virtlIO_t& operator=(const virtlIO_t& newV);
		IOstatus m_status;
		size_t m_length;
		
};

#endif















