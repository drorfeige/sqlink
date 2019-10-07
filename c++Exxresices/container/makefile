CFLAGS  = -pedantic -g -ansi -Wall 

con : contMain.o 
	g++ -o con contMain.cpp 

contMain.o : contMain.cpp tcontainer.h 
	g++ -c $(CFLAGS) contMain.cpp
