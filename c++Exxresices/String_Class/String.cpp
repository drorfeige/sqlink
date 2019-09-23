#include "String.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>

using namespace std;

String::String(){
	m_string=createFrom("");
}

String::String(const char* str){
	m_string=createFrom(str);
}

String::String(const String& str){
	m_string=createFrom(str.m_string);
}

String::~String(){
	delete[] m_string;
}
String& String::operator=(const String& str){
	if(this!=&str){
		delete[] m_string;
		m_string=createFrom(str.m_string);
	}
	return *this;
}
char* String::createFrom(const char* str){
	char* tmp;
	if(str!=0){
		tmp= new char[strlen(str)+1];
		strcpy(tmp,str);
		m_size=strlen(tmp);
	}
	else{
		tmp=new char[1];
		tmp[0]='\0';
		m_size=0;
	}
	return tmp;
}

void String::print() const{
	cout << m_string;
}

size_t String::getLength() const{
	return m_size;
}

void String::setString(const char* str){
	delete[] m_string;
	m_string=createFrom(str);
}

const char* String::getString() const{
	return m_string;
}

int String::myStrcmp(const char* str) const{
	int i=strcmp(m_string,str);
	if(i<0){
		return 1;
	}
	else if(i>0){
		return 2;
	}
	return 0;
}

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
	int length=m_size+strlen(str.m_string);
	char* tmp= new char[length+1];
	tmp[0]='\0';
	strcat(tmp,m_string);
	strcat(tmp,str.m_string);
	delete m_string;
	m_string=tmp;
	m_size=length;
	return *this;
}

String& String::operator+=(const char* str){
	if(str==0){
		return *this;
	}
	int length=m_size+strlen(str);
	char* tmp= new char[length+1];
	tmp[0]='\0';
	strcat(tmp,m_string);
	strcat(tmp,str);
	delete m_string;
	m_string=tmp;
	m_size=length;
	return *this;
}

void String::prepend(const char* pre){
	if(pre==0){
		return;
	}
	int length=m_size+strlen(pre);
	char* tmp= new char[length+1];
	tmp[0]='\0';
	strcat(tmp,pre);
	strcat(tmp,m_string);
	delete m_string;
	m_string=tmp;
	m_size=length;

}
void String::prepend(const String& pre){
	int length=m_size+strlen(pre.m_string);
	char* tmp= new char[length+1];
	tmp[0]='\0';
	strcat(tmp,pre.m_string);
	strcat(tmp,m_string);
	delete m_string;
	m_string=tmp;
	m_size=length;
}

bool String::operator<(const String& str) const{
	if((strcmp(m_string,str.m_string))<0){
		return true;
	}
	return false;
}
bool String::operator>(const String& str) const{
	if((strcmp(m_string,str.m_string))>0){
		return true;
	}
	return false;
}
bool String::operator<=(const String& str) const{
	if((strcmp(m_string,str.m_string))>0){
		return false;
	}
	return true;
}
bool String::operator>=(const String& str) const{
	if((strcmp(m_string,str.m_string))<0){
		return false;
	}
	return true;
}
bool String::operator==(const String& str) const{
	if((strcmp(m_string,str.m_string))==0){
		return true;
	}
	return false;
}
bool String::operator!=(const String& str) const{
	if((strcmp(m_string,str.m_string))!=0){
		return true;
	}
	return false;
}

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

ostream& operator<<(ostream& os, const String& s){
	os << s.getString();
	return os;
}
istream& operator>>(istream& is, String& s){
	char usrStr[128];	
	is >> usrStr;
	s.setString((const char*)usrStr);
	return is;
} 



















