#ifndef STRING_H
#define STRING_H
#include <stdlib.h>
#include <iostream>

using namespace std;

class String{
	public:
		//constructor and destructor
		~String();
		String();	
		String(const char* str);			
		String(const String& str);	
		//operators
		String& operator=(const String& str);
		String& operator+=(const String& str);
		String& operator+=(const char* str);
		bool operator<(const String& str) const;
		bool operator>(const String& str) const;
		bool operator<=(const String& str) const;
		bool operator>=(const String& str) const;
		bool operator==(const String& str) const;
		bool operator!=(const String& str) const;
		char operator[](size_t index) const;
		char& operator[](size_t index);
		//member functions
		size_t getLength() const;
		void setString(const char* str);
		const char* getString() const;
		int myStrcmp(const char* str) const;
		void print() const;
		void toUpper();
		void toLower();
		void prepend(const char* pre);
		void prepend(const String& pre);
		bool contains(const String& sub) const;
	private:
		char* m_string;
		size_t m_size;
		char* createFrom(const char* str);
};

ostream& operator<<(ostream& os, const String& s);
istream& operator>>(istream& is, String& s); 

#endif














