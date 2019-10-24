#ifndef PARSER_H
#define PARSER_H

#include "tokenizer.h"
#include "analyzer.h"
#include <fstream>
#include <string>
#include <iostream>
#include <ostream>

using namespace std;

class parser_t{
	public:
		virtual ~parser_t(){};
		parser_t(){}
		void compile(const char* filename){
			string line;
  			ifstream myfile ("example.txt");
 	 		if (myfile.is_open()){
    				while (getline (myfile,line) ){
					a1.analyze(t1.tokenize(line));
				}
				t1.cleanTokens();
				a1.endAnalyzer();
				myfile.close();
			}
			else cout << "Unable to open file" << filename << endl; 
		}
	private:
		parser_t(const parser_t& newP);
		parser_t& operator=(const parser_t newP);
		tokenizer_t t1;
		analyzer_t a1;
};




#endif

















