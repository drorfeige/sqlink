#include "analyzer.h"
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

analyzer_t::analyzer_t(){
	main=0;
	lineNum=0;
	ifCount=0;
	predefinedF=0;
	plus=0;
	minus=0;
	curlyBraces=0;
	squareBraces=0;
	circleBraces=0;
	string helper[]={"char","short","int","long","float","double","void"};
	predefinedV.insert(helper,helper+sizeof(helper)/sizeof(string));
	string helper2[]={"if","else","for","while","class","private","public","protected","main","const","virtual"};
	keyWords.insert(helper2,helper2+sizeof(helper2)/sizeof(string));
	string helper3[]={"++","--","==","->","+","-","=","*","&",">>","<<"};
	operators.insert(helper3,helper3+sizeof(helper3)/sizeof(string));
	delimiters=";(){}[]<>=+-&*";
}

void analyzer_t::endAndresetAnalyzer(){
	if(curlyBraces){
		cout << "error – "<< curlyBraces <<"'{' not closed" << endl;
	}
	if(squareBraces){
		cout << "error – "<< squareBraces <<"'[' not closed" << endl;
	}
	if(circleBraces){
		cout << "error – "<< circleBraces <<"'(' not closed" << endl;
	}
	main=0;
	lineNum=0;
	ifCount=0;
	predefinedF=0;
	plus=0;
	minus=0;
	curlyBraces=0;
	squareBraces=0;
	circleBraces=0;
	variables.clear();
}

void analyzer_t::analyze(queue<string>& tokens){
	lineNum++;
	string tmp;
	while(!tokens.empty()){
		tmp=tokens.front();
		if(!main){
			main=1;
			if(!strcmp(tmp.c_str(),"main")){
				tokens.pop();
				continue;
			}
			else{
				cout << "line " << lineNum << ": error illigal declaration before main"<< endl;	
			}
		}
		if(keyWords.find(tmp)!=keyWords.end()){
			ifHandler(tmp);
		}
		else if(operators.find(tmp)!=operators.end()){
			operatorsHandler(tmp);
			if(predefinedF){
				predefinedF=0;
				cout << "line " << lineNum << ": error invalid variable declaration"<< endl;
			}
			tokens.pop();
			continue;
		}
		else if(delimiters.find(tmp)!=string::npos){
			bracesHandler(tmp);
		}
		else if(predefinedV.find(tmp)!=predefinedV.end()){
			predefinedHandler();
			minus=0;
			plus=0;
			tokens.pop();
			continue;
		}
		else{
			variableHandler(tmp);
		}
		if(predefinedF){
			predefinedF=0;
			cout << "line " << lineNum << ": error invalid variable declaration"<< endl;
		}
		minus=0;
		plus=0;
		tokens.pop();		
	}
}

void analyzer_t::bracesHandler(const string& isBraces){
	if(!strcmp(isBraces.c_str(),"(")){
		circleBraces++;
	}
	else if(!strcmp(isBraces.c_str(),")")){
		if(circleBraces){
			circleBraces--;
		}else{
			cout << "line "<< lineNum << ": error,is illegal  ‘(‘ has to be before ‘)’"  <<endl;
		}
	}
	else if(!strcmp(isBraces.c_str(),"[")){
		squareBraces++;
	}
	else if(!strcmp(isBraces.c_str(),"]")){
		if(squareBraces){
			squareBraces--;
		}
		else{
			cout << "line "<< lineNum << ": error,is illegal  ‘[‘ has to be before ‘]’"  <<endl;
		}
	}
	else if(!strcmp(isBraces.c_str(),"{")){
		curlyBraces++;
	}
	else if(!strcmp(isBraces.c_str(),"}")){
		if(curlyBraces){
			curlyBraces--;
		}
		else{
			cout << "line "<< lineNum << ": error,is illegal  ‘{‘ has to be before ‘}’"  <<endl;
		}	
	}
}

void analyzer_t::ifHandler(const string& kw){
	if(!strcmp(kw.c_str(),"if")){
		ifCount++;
	}
	else if(!strcmp(kw.c_str(),"else")){
		if(ifCount){
			ifCount--;
		}
		else{
			cout << "line "<< lineNum << ": error, else without if"  <<endl;
		}
	}	
}

void analyzer_t::operatorsHandler(const string& o){
	//cout << o << endl;
	if(!strcmp(o.c_str(),"+")){
		if(plus<2){
			plus++;
		}
		else{
			plus=0;
			cout << "line "<< lineNum << ": error, no operator+++"  <<endl;
		}
		minus=0;
	}
	else if(!strcmp(o.c_str(),"-")){
		if(minus<2){
			minus++;
		}
		else{
			minus=0;
			cout << "line "<< lineNum << ": error, no operator---"  <<endl;
		}
		plus=0;
	}
}

void analyzer_t::predefinedHandler(){
	if(predefinedF){
		cout << "line "<< lineNum << ": error, multiple type"  <<endl;	
		predefinedF=0;
	}
	else{
		predefinedF=1;
	}
}

void analyzer_t::variableHandler(const string& var){
	const char first=var[0];
	if((first>='A' && first<='Z') || (first>='a' && first<='z') || first=='_'){
		if(predefinedF){
			if(!variables.insert(var).second){
				cout << "line "<< lineNum << ": error, multiple type declaration"  <<endl;	
			}
		}
		else{
			if(!variables.count(var)){
				cout << "line "<< lineNum << ": " << var << " is not declared"  <<endl;
			}
		}
		predefinedF=0;
	}
	else{
		if(predefinedF){
			cout << "line " << lineNum << ": error, invalid variable name" << endl;
			predefinedF=0;
		}
		else{
			cout << "line " << lineNum << ": error, invalid variable type declaration" << endl;
		}
	}	
}













