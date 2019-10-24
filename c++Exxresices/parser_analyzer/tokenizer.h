#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>

using namespace std;

class tokenizer_t{
	public:
		virtual ~tokenizer_t(){}
		tokenizer_t(){}
		inline void cleanTokens(){tokens.clear();}
		const vector<string>& tokenize(string line){
			tokens.clear();
			const char delimiters[]=" \t\v\f\r\n;(){}[]<>=+-&*";
			size_t found = line.find_first_of(delimiters);
			size_t begin=0;
			while (found!=string::npos){
				if(begin!=found){
					tokens.push_back(line.substr(begin,found-begin));
				}
				if(!isspace(line[found])){
					tokens.push_back(line.substr(found,1));
				}
				begin=found+1; 
				found=line.find_first_of(delimiters,begin);
			}
			return tokens;
		}
	private:
		tokenizer_t(const tokenizer_t& newT);
		tokenizer_t& operator=(const tokenizer_t& newT);
		vector<string> tokens;
};


#endif











