#include "analyzer.h"
#include <iterator>

analyzer_t::analyzer_t(){
	main=0;
	ifCount=0;
	lineNum=0;
	predefinedF=0;
	plus=0;
	minus=0;
	curlyBraces=0;
	squareBraces=0;
	circleBraces=0;
	string helper[]={"char","short","int","long","float","double","void"};
	predefinedV.insert(helper,helper+sizeof(helper)/sizeof(string));
	string helper2[]={"if","else","for","while","class","private","public","protected","main","const","virtual"};
	operators.insert(helper2,helper2+sizeof(helper2)/sizeof(string));
	string helper3[]={"++","--","==","->","+","-","=","*","&",">>","<<"};
	keyWords.insert(helper3,helper3+sizeof(helper3)/sizeof(string));
}

void analyzer_t::endAnalyzer(){
	main=0;
	ifCount=0;
	lineNum=0;
	predefinedF=0;
	plus=0;
	minus=0;
	curlyBraces=0;
	squareBraces=0;
	circleBraces=0;
	variables.clear();
}

void analyzer_t::analyze(const vector<string>& tokens){
	lineNum++;
	for(vector<string>::const_iterator it=tokens.begin();it!=tokens.end();it++){
			
	}

}









