#ifndef ASCIIIO_H
#define ASCIIIO_H

#include "virtlIO.h"

class asciiIO_t: public virtlIO_t{
	public:
		~asciiIO_t(){}
		asciiIO_t(){}
		asciiIO_t(const char* name, const char* mode): virtlIO_t(name,mode){}
		virtual asciiIO_t& operator <<(int var){return write(var,"%d");} 
		virtual asciiIO_t& operator <<(unsigned int var){return write(var,"%u");}
		virtual asciiIO_t& operator <<(unsigned short var){return write(var,"%hu");}
		virtual asciiIO_t& operator <<(short var){return write(var,"%hd");}
		virtual asciiIO_t& operator <<(long var){return write(var,"%ld");}
		virtual asciiIO_t& operator <<(unsigned long var){return write(var,"%lu");}
		virtual asciiIO_t& operator <<(char var){return write(var,"%c");}
		virtual asciiIO_t& operator <<(unsigned char var){return write(var,"%c");}
		virtual asciiIO_t& operator <<(float var){return write(var,"%f");}
		virtual asciiIO_t& operator <<(double var){return write(var,"%f");}
		virtual asciiIO_t& operator>>(int& var){return read(var,"%d");}
		virtual asciiIO_t& operator>>(unsigned int& var){return read(var,"%u");}
		virtual asciiIO_t& operator>>(short& var){return read(var,"%hd");}
		virtual asciiIO_t& operator>>(unsigned short& var){return read(var,"%hu");}
		virtual asciiIO_t& operator>>(long& var){return read(var,"%ld");}
		virtual asciiIO_t& operator>>(unsigned long& var){return read(var,"%lu");}
		virtual asciiIO_t& operator>>(char& var){return read(var,"%c");}
		virtual asciiIO_t& operator>>(unsigned char& var){return read(var,"%c");}
		virtual asciiIO_t& operator>>(double& var){return read(var,"%lf");}
		virtual asciiIO_t& operator>>(float& var){return read(var,"%f");}
	private:
		asciiIO_t(const asciiIO_t& newV);
		asciiIO_t& operator=(const asciiIO_t& newV);
		template<class T>
		asciiIO_t& read(T& var,const char* format){
			if(m_file==0){	
				setStatus(readErr_e);	
				throw -1;
			}
			if(strcmp(m_mode,"r") && strcmp(m_mode,"r+") && strcmp(m_mode,"w+")){
				setStatus(readErr_e);
				throw -1;
			}
			if(fscanf(m_file,format,&var)<0){
				throw -2;
			}
			return *this;
		}
		template<class T>
		asciiIO_t& write(T var,const char* format){
			if(m_file==0){	
				setStatus(writeErr_e);	
				throw -1;
			}
			if(strcmp(m_mode,"w") && strcmp(m_mode,"w+") && strcmp(m_mode,"r+")){
				setStatus(writeErr_e);
				throw -1;
			}
			if(fprintf(m_file,format,var)<=0){
				throw -2;
			}
			return *this;
		}	
};


#endif









