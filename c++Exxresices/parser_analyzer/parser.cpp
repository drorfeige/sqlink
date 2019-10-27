#include "parser.h"
#include "tokenizer.h"
#include "analyzer.h"
#include <fstream>
#include <string>
#include <iostream>
#include <ostream>

using namespace std;

void parser_t::compile(const char* filename){
	string line;
  	ifstream myfile (filename);
 	if (myfile.is_open()){
   		while (getline(myfile,line) ){
			a1->analyze(t1->tokenize(line));
		}
		a1->endAndresetAnalyzer();
		myfile.close();
	}
	else cout << "Unable to open file" << filename << endl; 
}

parser_t::parser_t(){
	t1=new tokenizer_t;
	a1=new analyzer_t;
}

parser_t::~parser_t(){
	delete t1;
	delete a1;
}







