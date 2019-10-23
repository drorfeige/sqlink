CFLAGS  = -pedantic -g -ansi -Wall 

fl : fileMain.o 
	g++ -o fl fileMain.o  

fileMain.o : fileMain.cpp virtlIO.h asciiIO.h binIO.h
	g++ -c $(CFLAGS) fileMain.cpp


