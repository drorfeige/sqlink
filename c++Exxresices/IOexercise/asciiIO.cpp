#include "virtlIO.h"
#include "asciiIO.h"



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
asciiIO_t& asciiIO_t::operator>>(int& var){
	if(canRead()){
		fscanf(m_file,"%d",&var);
	}
	return *this;
}
asciiIO_t& asciiIO_t::operator>>(unsigned int& var){
	if(canRead()){
		fscanf(m_file,"%u",&var);
	}
	return *this;
}
asciiIO_t& asciiIO_t::operator>>(short& var){
	if(canRead()){
		fscanf(m_file,"%hd",&var);
	}
	return *this;
}
asciiIO_t& asciiIO_t::operator>>(unsigned short& var){
	if(canRead()){
		fscanf(m_file,"%hu",&var);
	}
	return *this;
}
asciiIO_t& asciiIO_t::operator>>(long& var){
	if(canRead()){
		fscanf(m_file,"%ld",&var);
	}
	return *this;
}
asciiIO_t& asciiIO_t::operator>>(unsigned long& var){
	if(canRead()){
		fscanf(m_file,"%lu",&var);
	}
	return *this;
}
asciiIO_t& asciiIO_t::operator>>(char& var){
	if(canRead()){
		fscanf(m_file,"%c",&var);
	}
	return *this;
}
asciiIO_t& asciiIO_t::operator>>(unsigned char& var){
	if(canRead()){
		fscanf(m_file,"%c",&var);
	}
	return *this;
}
asciiIO_t& asciiIO_t::operator>>(double& var){
	if(canRead()){
		fscanf(m_file,"%lf",&var);
	}
	return *this;
}
asciiIO_t& asciiIO_t::operator>>(float& var){
	if(canRead()){
		fscanf(m_file,"%f",&var);
	}
	return *this;
}





