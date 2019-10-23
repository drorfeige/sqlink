#ifndef VIRTLIO_H
#define VIRTLIO_H

#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

class virtlIO_t{
	public:
		typedef enum{ok_e , cant_open_file_e , bad_access_e , writeErr_e , readErr_e }IOstatus;
		virtlIO_t(){m_file=0;m_name="";}
		virtlIO_t(const char* name, const char* mode){
			if(strlen(mode)<4){
				strcpy(m_mode,mode);
				m_file=fopen(name,mode);
				m_name=name;
				m_status=ok_e;
			}else{
				m_file=0;
				m_name="";
				m_status=cant_open_file_e;
			}
		}
		const IOstatus& getStatus()const{return m_status;}
		void setStatus(const IOstatus& newSt){m_status=newSt;}
		long getPos()const{return m_file? ftell(m_file):-1;}
		bool setPos(size_t pos){return !fseek(m_file,pos,SEEK_SET);}
		const char* getAccess(){return m_mode;}
		string getPath(){return m_name;}
		void close(){
			if(m_file){
				fclose(m_file);
				m_file=0; 
				m_name="";
			}
		}
		bool open(const char* name, const char* mode){
			if(strlen(mode)<4){
					strcpy(m_mode,mode);
					m_name=name;
					m_status=ok_e;	
			}
			else{
				m_status=cant_open_file_e;
			}
			return (m_file=fopen(name,mode));
		}
		long getLength(){
			long old,length;
			old=ftell(m_file);
			fseek(m_file,0,SEEK_END);
			length=ftell(m_file);
			fseek(m_file,old,SEEK_SET);
			return length;
		}
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
		virtual virtlIO_t& operator>>(int& var)=0;
		virtual virtlIO_t& operator>>(unsigned int& var)=0;
		virtual virtlIO_t& operator>>(short& var)=0;
		virtual virtlIO_t& operator>>(unsigned short& var)=0;
		virtual virtlIO_t& operator>>(long& var)=0;
		virtual virtlIO_t& operator>>(unsigned long& var)=0;
		virtual virtlIO_t& operator>>(char& var)=0;
		virtual virtlIO_t& operator>>(unsigned char& var)=0;
		virtual virtlIO_t& operator>>(double& var)=0;
		virtual virtlIO_t& operator>>(float& var)=0;
	
	protected:
		virtual ~virtlIO_t(){
			if(m_file){
				fclose(m_file);
			}
		}
		FILE* m_file;
		char m_mode[4];
	private:
		virtlIO_t(const virtlIO_t& newV);
		virtlIO_t& operator=(const virtlIO_t& newV);
		IOstatus m_status;
		string m_name;
		
};


#endif















