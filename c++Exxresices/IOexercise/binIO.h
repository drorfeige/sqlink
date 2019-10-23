#ifndef BINIO_H
#define BINIO_H

#include "virtlIO.h"

class binIO_t: public virtlIO_t{
	public:
		typedef enum{READ,WRITE}state;
		~binIO_t(){}
		binIO_t(){m_buf=0;}
		binIO_t(const char* name, const char* mode): virtlIO_t(name,mode){m_buf=0;}
		virtual binIO_t& operator <<(int var){return write(&var,sizeof(int),1);} 
		virtual binIO_t& operator <<(unsigned int var){return write(&var,sizeof(unsigned int),1);}
		virtual binIO_t& operator <<(unsigned short var){return write(&var,sizeof(unsigned short),1);}
		virtual binIO_t& operator <<(short var){return write(&var,sizeof(short),1);}
		virtual binIO_t& operator <<(long var){return write(&var,sizeof(long),1);}
		virtual binIO_t& operator <<(unsigned long var){return write(&var,sizeof(unsigned long),1);}
		virtual binIO_t& operator <<(char var){return write(&var,sizeof(char),1);}
		virtual binIO_t& operator <<(unsigned char var){return write(&var,sizeof(unsigned char),1);}
		virtual binIO_t& operator <<(float var){return write(&var,sizeof(float),1);}
		virtual binIO_t& operator <<(double var){return write(&var,sizeof(double),1);}
		virtual binIO_t& operator>>(int& var){return read(&var,sizeof(int),1);}
		virtual binIO_t& operator>>(unsigned int& var){return read(&var,sizeof(unsigned int),1);}
		virtual binIO_t& operator>>(short& var){return read(&var,sizeof(short),1);}
		virtual binIO_t& operator>>(unsigned short& var){return read(&var,sizeof(unsigned short),1);}
		virtual binIO_t& operator>>(long& var){return read(&var,sizeof(long),1);}
		virtual binIO_t& operator>>(unsigned long& var){return read(&var,sizeof(unsigned long),1);}
		virtual binIO_t& operator>>(char& var){return read(&var,sizeof(char),1);}
		virtual binIO_t& operator>>(unsigned char& var){return read(&var,sizeof(unsigned char),1);}
		virtual binIO_t& operator>>(double& var){return read(&var,sizeof(double),1);}
		virtual binIO_t& operator>>(float& var){return read(&var,sizeof(float),1);}
		virtual binIO_t& operator>>(void* buf){m_buf=buf;flag=READ;return *this;}
		virtual binIO_t& operator<<(const void* buf){m_buf=(void*)buf;flag=WRITE;return *this;}
		virtual binIO_t& operator,(size_t len){
			if(flag==READ){
				read(m_buf, 1, len);
			}
			else{
				write(m_buf, 1, len);
			}
			return *this;
		}
	private:
		binIO_t(const binIO_t& newV);
		binIO_t& operator=(const binIO_t& newV);
		void* m_buf;
		state flag;
		binIO_t& read(void* ptr,const size_t size, size_t count){
			if(m_file==0){	
				setStatus(readErr_e);	
				throw -1;
			}
			if(strcmp(m_mode,"rb") && strcmp(m_mode,"rb+") && strcmp(m_mode,"wb+")){
				setStatus(readErr_e);
				throw -1;
			}
			fread(ptr, size, count,m_file);
			return *this;
		}
		binIO_t& write(const void* ptr,const size_t size, size_t count){
			if(m_file==0){	
				setStatus(writeErr_e);	
				throw -1;
			}
			if(strcmp(m_mode,"wb") && strcmp(m_mode,"wb+") && strcmp(m_mode,"rb+")){
				setStatus(writeErr_e);
				throw -1;
			}
			if(fwrite (ptr, size, count,m_file)==0){
				throw -2;
			}
			return *this;
		}
};


#endif














