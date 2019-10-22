#ifndef ASCIIIO_H
#define ASCIIIO_H

#include "virtlIO.h"

class asciiIO_t: public virtlIO_t{
	public:
		asciiIO_t();
		asciiIO_t(const char* name, const char* mode);
		asciiIO_t& operator <<(int var); 
		asciiIO_t& operator <<(unsigned int var);
		asciiIO_t& operator <<(unsigned short var);
		asciiIO_t& operator <<(short var);
		asciiIO_t& operator <<(long var);
		asciiIO_t& operator <<(unsigned long var);
		asciiIO_t& operator <<(char var);
		asciiIO_t& operator <<(unsigned char var);
		asciiIO_t& operator <<(float var);
		asciiIO_t& operator <<(double var);
		const asciiIO_t& operator>>(int& var) const;
		const asciiIO_t& operator>>(unsigned int& var) const;
		const asciiIO_t& operator>>(short& var) const;
		const asciiIO_t& operator>>(unsigned short& var) const;
		const asciiIO_t& operator>>(long& var) const;
		const asciiIO_t& operator>>(unsigned long& var) const;
		const asciiIO_t& operator>>(char& var) const;
		const asciiIO_t& operator>>(unsigned char& var) const;
		const asciiIO_t& operator>>(double& var) const;
		const asciiIO_t& operator>>(float& var) const;
	private:	
		bool canRead() const;
		bool canWrite();
};


#endif









