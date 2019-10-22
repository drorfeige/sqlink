#include "virtlIO.h"
#include "asciiIO.h"
#include <string.h>

bool asciiIO_t::canRead() const{
	if(m_file && (!strcmp(m_mode,"r") ||!strcmp(m_mode,"r+"))){
		setStatus(readErr_e);
		return 0;
	}
	return 1;
}

bool asciiIO_t::canWrite(){
	if(m_file && (!strcmp(m_mode,"w") ||!strcmp(m_mode,"w+"))){
		setStatus(writeErr_e);
		return 0;
	}
	return 1;
}

asciiIO_t& asciiIO_t::operator <<(int var){
	if(canWrite()){
		fprintf(m_file,"%d",var);
	}
	return *this;
}
asciiIO_t& asciiIO_t::operator <<(unsigned int var){
	if(canWrite()){
		fprintf(m_file,"%u",var);
	}
	return *this;
}
asciiIO_t& asciiIO_t::operator <<(unsigned short var){
	if(canWrite()){
		fprintf(m_file,"%hu",var);
	}
	return *this;
}
asciiIO_t& asciiIO_t::operator <<(short var){
	if(canWrite()){
		fprintf(m_file,"%hd",var);
	}
	return *this;
}
asciiIO_t& asciiIO_t::operator <<(long var){
	if(canWrite()){
		fprintf(m_file,"%ld",var);
	}
	return *this;
}
asciiIO_t& asciiIO_t::operator <<(unsigned long var){
	if(canWrite()){
		fprintf(m_file,"%lu",var);
	}
	return *this;
}
asciiIO_t& asciiIO_t::operator <<(char var){
	if(canWrite()){
		fprintf(m_file,"%c",var);
	}
	return *this;
}
asciiIO_t& asciiIO_t::operator <<(unsigned char var){
	if(canWrite()){
		fprintf(m_file,"%c",var);
	}
	return *this;
}
asciiIO_t& asciiIO_t::operator <<(float var){
	if(canWrite()){
		fprintf(m_file,"%f",var);
	}
	return *this;
}
asciiIO_t& asciiIO_t::operator <<(double var){
	if(canWrite()){
		fprintf(m_file,"%f",var);
	}
	return *this;
}
const asciiIO_t& asciiIO_t::operator>>(int& var) const{
	if(canRead()){
		fscanf(m_file,"%d",&var);
	}
	return *this;
}
const asciiIO_t& asciiIO_t::operator>>(unsigned int& var) const{
	if(canRead()){
		fscanf(m_file,"%u",&var);
	}
	return *this;
}
const asciiIO_t& asciiIO_t::operator>>(short& var) const{
	if(canRead()){
		fscanf(m_file,"%hd",&var);
	}
	return *this;
}
const asciiIO_t& asciiIO_t::operator>>(unsigned short& var) const{
	if(canRead()){
		fscanf(m_file,"%hu",&var);
	}
	return *this;
}
const asciiIO_t& asciiIO_t::operator>>(long& var) const{
	if(canRead()){
		fscanf(m_file,"%ld",&var);
	}
	return *this;
}
const asciiIO_t& asciiIO_t::operator>>(unsigned long& var) const{
	if(canRead()){
		fscanf(m_file,"%lu",&var);
	}
	return *this;
}
const asciiIO_t& asciiIO_t::operator>>(char& var) const{
	if(canRead()){
		fscanf(m_file,"%c",&var);
	}
	return *this;
}
const asciiIO_t& asciiIO_t::operator>>(unsigned char& var) const{
	if(canRead()){
		fscanf(m_file,"%c",&var);
	}
	return *this;
}
const asciiIO_t& asciiIO_t::operator>>(double& var) const{
	if(canRead()){
		fscanf(m_file,"%lf",&var);
	}
	return *this;
}
const asciiIO_t& asciiIO_t::operator>>(float& var) const{
	if(canRead()){
		fscanf(m_file,"%f",&var);
	}
	return *this;
}





