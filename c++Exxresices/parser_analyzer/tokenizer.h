#ifndef TOKENIZER_H
#define TOKENIZER_H


#include <queue>
#include <string>



class tokenizer_t{
	public:
		virtual ~tokenizer_t(){}
		tokenizer_t();
		std::queue<std::string>& tokenize(const std::string& line);
		inline const std::string& setDelimiters(const std::string& newDel){ 
			delimiters=newDel; return delimiters;
		}
		inline const std::string& getDelimiters() const{return delimiters;}
	private:
		tokenizer_t(const tokenizer_t& newT);
		tokenizer_t& operator=(const tokenizer_t& newT);
		std::queue<std::string> tokens;
		std::string delimiters; 
};


#endif











