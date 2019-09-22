CFLAGS  = -pedantic -g -ansi -Wall 

str : stringMain.o String.o
	g++ -o str stringMain.cpp String.cpp

stringMain.o : stringMain.cpp String.h
	g++ -c $(CFLAGS) stringMain.cpp

String.o : String.cpp String.h
	g++ -c $(CFLAGS) String.cpp
