#include "String.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


String::String(){
	size=0;
	string=createFrom("");
}

String::String(const char* str){
	string=createFrom(str);
}

String::String(const String& str){
	string=createFrom(str.string);
}

String::~String(){
	delete[] string;
}
String& String::operator=(const String& str){
	if(this!=&str){
		delete[] string;
		string=createFrom(str.string);
	}
	return *this;
}
char* String::createFrom(const char* str){
	char* tmp= new char[strlen(str)+1];
	strcpy(tmp,str);
	size=strlen(tmp);
	return tmp;
}

void String::print() const{
	printf("%s\n",string);
}

size_t String::getLength() const{
	return size;
}

void String::setString(const char* str){
	delete[] string;
	string=createFrom(str);
}

const char* String::getString() const{
	return string;
}

int String::myStrcmp(const char* str) const{
	int i=strcmp(string,str);
	if(i<0){
		return 1;
	}
	else if(i>0){
		return 2;
	}
	return 0;
}









