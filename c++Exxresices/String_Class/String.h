#ifndef STRING_H
#define STRING_H
#include <stdlib.h>

class String{
	public:
		String();	
		String(const char* str);			
		String(const String& str);
		~String();
		String& operator=(const String& str);
		size_t getLength() const;
		void setString(const char* str);
		const char* getString() const;
		int myStrcmp(const char* str) const;
		void print() const;
	private:
		char* string;
		//size_t size;
		char* createFrom(const char* str);
};



#endif














