#include "String.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>

using namespace std;

int String::numOfStrings=0;
size_t String::defCap=8;
bool String::caseSens=true;

/*
int String::nOfString(){
	return numOfStrings;
}

size_t String::getCap(){
	return defCap;
}

size_t String::getPrivateCap() const{
	return privateCap;
}

bool String::getCaseSens(){
	return caseSens;
}

size_t String::setCap(size_t s){
	size_t old=defCap;
	defCap=s;
	return old;
}

bool String::setCaseSens(bool f){
	bool old=caseSens;
	caseSens=f;
	return old;
}
*/
String::String(){
	++numOfStrings;
	m_string=createFrom("");
}

String::String(const char* str){
	++numOfStrings;
	m_string=createFrom(str);
}

String::String(const String& str){
	++numOfStrings;
	m_string=createFrom(str.m_string);
}

String::~String(){
	--numOfStrings;
	delete[] m_string;
}
String& String::operator=(const String& str){
	if(this!=&str){
		delete[] m_string;
		m_string=createFromA(str.m_string);
	}
	return *this;
}
char* String::createFrom(const char* str){
	if((strlen(str+1))>defCap){
		privateCap=nextPowerOf2(strlen(str)+1);
		m_string=new char[privateCap];
	}
	else{
		privateCap=defCap;
		m_string=new char[privateCap];
	}	
	if(str!=0){
		strcpy(m_string,str);
		m_size=strlen(m_string);
	}
	else{
		m_string[0]='\0';
		m_size=0;
	}
	return m_string;
}

char* String::createFromA(const char* str){
	if((strlen(str+1))>privateCap){
		privateCap=nextPowerOf2(strlen(str)+1);
		m_string=new char[privateCap];
	}	
	if(str!=0){
		strcpy(m_string,str);
		m_size=strlen(m_string);
	}
	else{
		m_string[0]='\0';
		m_size=0;
	}
	return m_string;
}
/*
void String::print() const{
	cout << m_string;
}

size_t String::getLength() const{
	return m_size;
}
*/
void String::setString(const char* str){
	delete[] m_string;
	m_string=createFromA(str);
}
/*
const char* String::getString() const{
	return m_string;
}

int String::myStrcmp(const char* str) const{
	int i=0;	
	if(caseSens){	
		i=strcmp(m_string,str);
	}
	else{
		i=strcasecmp(m_string, str);
	}
	if(i<0){
		return 1;
	}
	else if(i>0){
		return 2;
	}
	return 0;
}
*/
void String::toUpper(){
	int i=0;
	while(m_string[i]!='\0'){
		m_string[i]=toupper(m_string[i]);
		i++;
	}
}

void String::toLower(){
	int i=0;
	while(m_string[i]!='\0'){
		m_string[i]=tolower(m_string[i]);
		i++;
	}
}

String& String::operator+=(const String& str){
	addString( m_string, str.m_string);
	return *this;
}

String& String::operator+=(const char* str){
	if(str==0){
		return *this;
	}
	addString( m_string, str);
	return *this;
}

String& String::prepend(const char* pre){
	if(pre==0){
		return *this;
	}
	addString( pre, m_string);
	return *this;
}
String& String::prepend(const String& pre){
	addString( pre.m_string, m_string);
	return *this;
}

/*
bool String::operator<(const String& str) const{
	int i=0;	
	if(caseSens){	
		i=strcmp(m_string,str.m_string);
	}
	else{
		i=strcasecmp(m_string, str.m_string);
	}
	if(i<0){
		return true;
	}
	return false;
}
bool String::operator>(const String& str) const{
	int i=0;	
	if(caseSens){	
		i=strcmp(m_string,str.m_string);
	}
	else{
		i=strcasecmp(m_string, str.m_string);
	}
	if(i>0){
		return true;
	}
	return false;
}
bool String::operator<=(const String& str) const{
	int i=0;	
	if(caseSens){	
		i=strcmp(m_string,str.m_string);
	}
	else{
		i=strcasecmp(m_string, str.m_string);
	}
	if(i>0){
		return false;
	}
	return true;
}
bool String::operator>=(const String& str) const{
	int i=0;	
	if(caseSens){	
		i=strcmp(m_string,str.m_string);
	}
	else{
		i=strcasecmp(m_string, str.m_string);
	}
	if(i<0){
		return false;
	}
	return true;
}
bool String::operator==(const String& str) const{
	int i=0;	
	if(caseSens){	
		i=strcmp(m_string,str.m_string);
	}
	else{
		i=strcasecmp(m_string, str.m_string);
	}
	if(i==0){
		return true;
	}
	return false;
}
bool String::operator!=(const String& str) const{
	int i=0;	
	if(caseSens){	
		i=strcmp(m_string,str.m_string);
	}
	else{
		i=strcasecmp(m_string, str.m_string);
	}
	if(i!=0){
		return true;
	}
	return false;
}
*/
bool String::contains(const String& sub) const{
	int s1len=m_size;
	int s2len=sub.m_size;
	int i=0;
	int j=0;
	for(i=0; i<=s1len-s2len; i++){
		if (m_string[i]==sub.m_string[0]){
			for(j=0;j<s2len;j++){
				if(m_string[i+j]!=sub.m_string[j]){
					break;
				}
			}
			if (j==s2len){
				return true;
			}
		}
	}
	return false;
}

/*
char String::operator[](size_t index) const{
	if(index>=m_size){
		cout << "wrong index\n";
		return 0;
	}
	return m_string[(unsigned int)index];
}

char& String::operator[](size_t index){
	if(index>=m_size){
		cout<< "wrong index\n";
		return m_string[m_size];
	}
	return m_string[index];
}
*/
ostream& operator<<(ostream& os, const String& s){
	os << s.getString();
	return os;
}
istream& operator>>(istream& is, String& s){
	char usrStr[128];	
	is >> usrStr;
	s.setString(usrStr);
	return is;
} 

void String::addString(const char* str1, const char* str2){
	size_t length=strlen(str1)+strlen(str2);
	if(length+1>privateCap){
		privateCap=nextPowerOf2(length+1);
		char* tmp=new char[privateCap];
		strcpy(tmp,str1);
		strcat(tmp,str2);
		delete[] m_string;
		m_string=tmp;
		m_size=length;
	}
	else{
		char* tmp=new char[privateCap];
		strcpy(tmp,str1);
		strcat(tmp,str2);
		delete[] m_string;
		m_string=tmp;
		m_size=length;
	}
}

unsigned int String::fisrtIndex(char c) const{
	unsigned int i=0;
	while(m_string[i]!='\0' && m_string[i]!=c){
		i++;
	}
	return i;
}
unsigned int String::lastIndex(char c) const{
	unsigned int i=0;
	unsigned int ret=m_size;
	while(m_string[i]!='\0'){
		if(m_string[i]==c){
			ret=i;
		}
		i++;
	}
	return ret;
}

String  String::operator()(unsigned int start, unsigned int len) const{
	
	char* str = new char[len+1];
	if(start<=m_size){
		unsigned int i=0;
		while(m_string[start+i]!='\0' && i<len){
			str[i]=m_string[start+i];
			i++;
		}
	}
	else{
		str[0]='\0';
	}
	String sNew(str);
	//String sNew = new String;
	//sNew.setString((const char*) str);
	delete str;	
	return sNew;
}

size_t nextPowerOf2(size_t n){
	n=n-1;
	while (n&(n-1)){
		n=n&(n-1);
	}
	return n << 1;
}












