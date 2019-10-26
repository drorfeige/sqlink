#ifndef ANALYZER_H
#define ANALYZER_H

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class analyzer_t{
	public:
		virtual ~analyzer_t(){}
		analyzer_t();
		void analyze(const vector<string>& tokens);
		void endAnalyzer();
	private:
		analyzer_t(const analyzer_t& newA);
		analyzer_t& operator=(const analyzer_t& newA);
		unsigned int lineNum;
		bool main;
		bool predefinedF;
		unsigned int ifCount;
		set<string> variables;
		unsigned int plus;
		unsigned int minus;
		unsigned int curlyBraces;
		unsigned int squareBraces;
		unsigned int circleBraces;
		set<string> predefinedV;
		set<string> operators;
		set<string> keyWords;
		void predefinedHandler();
		void keywordsHanler(){}
		void operatorsHandler(){}
		void variableHandler(){}
		void bracesHandler(){}
		
			
};

#endif
















