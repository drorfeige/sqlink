#ifndef PARSER_H
#define PARSER_H

class tokenizer_t;
class analyzer_t;


class parser_t{
	public:
		virtual ~parser_t();
		parser_t();
		virtual void compile(const char* filename);
	protected:
		tokenizer_t* t1;
		analyzer_t* a1;
	private:
		parser_t(const parser_t& newP);
		parser_t& operator=(const parser_t newP);
		
};




#endif

















