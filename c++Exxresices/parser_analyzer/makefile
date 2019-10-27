CFLAGS  = -pedantic -g -ansi -Wall 

qq-- : qq.o parser.o tokenizer.o analyzer.o
	g++ -o qq-- qq.o analyzer.o parser.o tokenizer.o

qq.o : qq.cpp parser.h 
	g++ -c $(CFLAGS) qq.cpp

parser.o : parser.cpp parser.h tokenizer.h analyzer.h
	g++ -c $(CFLAGS) parser.cpp 

tokenizer.o : tokenizer.cpp tokenizer.h
	g++ -c $(CFLAGS) tokenizer.cpp

analyzer.o : analyzer.cpp analyzer.h 
	g++ -c $(CFLAGS) analyzer.cpp

