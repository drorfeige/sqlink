#ifndef ANALYZER_H
#define ANALYZER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class analyzer_t{
	public:
		virtual ~analyzer_t(){}
		analyzer_t(){main=0;ifCount=0;}
		void analyze(const vector<string>& tokens){}
		void endAnalyzer(){main=0;ifCount=0;predefinedF=0;
                                     variables.clear();}
	private:
		analyzer_t(const analyzer_t& newA);
		analyzer_t& operator=(const analyzer_t& newA);
		unsigned int lineNum;
		bool main;
		bool predefinedF;
		unsigned int ifCount;
		vector<string> variables;
		unsigned int plus;
		unsigned int minus;
		unsigned int curlyBrackets;
		unsigned int squareBrackets;
		unsigned int circleBrackets;
		vector<string> predefinedV;
		vector<string> operators;
		vector<string> keyWords;
		
};

#endif
















