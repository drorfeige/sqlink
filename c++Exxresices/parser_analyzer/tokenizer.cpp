#include "tokenizer.h"

using namespace std;


tokenizer_t::tokenizer_t(){
	delimiters=" \t\v\f\r\n;(){}[]<>=+-&*";
}

queue<string>& tokenizer_t::tokenize(const string& line){
	size_t found = line.find_first_of(delimiters);
	size_t begin=0;
	while (found!=string::npos){
		if(begin!=found){
			tokens.push(line.substr(begin,found-begin));
		}
		if(!isspace(line[found])){
			tokens.push(line.substr(found,1));
		}
		begin=found+1; 
		found=line.find_first_of(delimiters,begin);
	}
	return tokens;
}



























