CFLAGS  = -pedantic -g -ansi -Wall 

qq-- : qq.o analyzer.o
	g++ -o qq-- qq.o analyzer.o  

qq.o : qq.cpp parser.h 
	g++ -c $(CFLAGS) qq.cpp

analyzer.o : analyzer.cpp analyzer.h 
	g++ -c $(CFLAGS) analyzer.cpp

