CFLAGS  = -pedantic -g -ansi -Wall 

mem : memMain.o 
	g++ -o mem memMain.cpp 

memMain.o : memMain.cpp memMan.h memPage.h memPool.h
	g++ -c $(CFLAGS) memMain.cpp
