#ifndef STRING_H
#define STRING_H
#include <stdlib.h>
#include <iostream>
#include <string.h>
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
		inline bool operator<(const String& str) const;
		inline bool operator>(const String& str) const;
		inline bool operator<=(const String& str) const;
		inline bool operator>=(const String& str) const;
		inline bool operator==(const String& str) const;
		inline bool operator!=(const String& str) const;
		inline char operator[](size_t index) const;
		inline char& operator[](size_t index);
		String operator()(unsigned int start, unsigned int len) const;
		//member functions
		inline size_t getLength() const;
		void setString(const char* str);
		inline const char* getString() const;
		inline int myStrcmp(const char* str) const;
		inline void print() const;
		void toUpper();
		void toLower();
		String& prepend(const char* pre);
		String& prepend(const String& pre);
		bool contains(const String& sub) const;
		inline static int nOfString();
		inline static size_t getCap();
		inline static bool getCaseSens();
		inline static size_t setCap(size_t s);
		inline size_t getPrivateCap() const;
		inline static bool setCaseSens(bool f);
		unsigned int fisrtIndex(char c) const;
		unsigned int lastIndex(char c) const;
	private:
		//private variables
		char* m_string;
		size_t m_size;
		static int numOfStrings;
		static size_t defCap;
		size_t privateCap;
		static bool caseSens;
		//private functions
		char* createFrom(const char* str);
		char* createFromA(const char* str);
		void addString(const char* str1, const char* str2);
		inline int local(const char* str1, const char* str2) const;
		//size_t nextPowerOf2(size_t n);
};

ostream& operator<<(ostream& os, const String& s);
istream& operator>>(istream& is, String& s);
 
size_t nextPowerOf2(size_t n);

inline int String::local(const char* str1, const char* str2) const{	
	if(caseSens){	
		return strcmp(str1,str2);
	}
	else{
		return strcasecmp(str1, str2);
	}
}

inline int String::nOfString(){
	return numOfStrings;
}

inline size_t String::getCap(){
	return defCap;
}

inline size_t String::getPrivateCap() const{
	return privateCap;
}

inline bool String::getCaseSens(){
	return caseSens;
}

inline size_t String::setCap(size_t s){
	size_t old=defCap;
	defCap=nextPowerOf2(s);;
	return old;
}

inline bool String::setCaseSens(bool f){
	bool old=caseSens;
	caseSens=f;
	return old;
}

inline void String::print() const{
	cout << m_string;
}

inline size_t String::getLength() const{
	return m_size;
}

inline const char* String::getString() const{
	return m_string;
}

inline int String::myStrcmp(const char* str) const{
	int i=local(m_string, str);	
	if(i<0){
		return 1;
	}
	else if(i>0){
		return 2;
	}
	return 0;
}

inline char String::operator[](size_t index) const{
	if(index>=m_size){
		cout << "wrong index\n";
		return 0;
	}
	return m_string[index];
}

inline char& String::operator[](size_t index){
	if(index>=m_size){
		cout<< "wrong index\n";
		return m_string[m_size];
	}
	return m_string[index];
}

bool String::operator<(const String& str) const{
	int i=local(m_string, str.m_string);	
	if(i<0){
		return true;
	}
	return false;
}
bool String::operator>(const String& str) const{
	int i=local(m_string, str.m_string);
	if(i>0){
		return true;
	}
	return false;
}
bool String::operator<=(const String& str) const{
	int i=local(m_string, str.m_string);	
	if(i>0){
		return false;
	}
	return true;
}
bool String::operator>=(const String& str) const{
	int i=local(m_string, str.m_string);	
	if(i<0){
		return false;
	}
	return true;
}
bool String::operator==(const String& str) const{
	int i=local(m_string, str.m_string);	
	if(i==0){
		return true;
	}
	return false;
}
bool String::operator!=(const String& str) const{
	int i=local(m_string, str.m_string);	
	if(i!=0){
		return true;
	}
	return false;
}
#endif














