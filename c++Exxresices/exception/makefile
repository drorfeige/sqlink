CFLAGS  = -pedantic -g -ansi -Wall 

ex : exTest.o 
	g++ -o ex exTest.cpp 

exTest.o : exTest.cpp exception_t.h 
	g++ -c $(CFLAGS) exTest.cpp
