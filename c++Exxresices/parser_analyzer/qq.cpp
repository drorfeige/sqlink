#include "parser.h"



int main(int argc, char** argv){
	int i=1;
	parser_t p1;
	while(i<argc){
		p1.compile(argv[i]);
	}
	return 0;
}



