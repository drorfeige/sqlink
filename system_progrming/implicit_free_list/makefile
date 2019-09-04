CFLAGS  = -pedantic -g -ansi -Wall
 

fr : freetest.o free.o 
	gcc -o fr freetest.o free.o 

freetest.o : freetest.c free.h 
	gcc -c $(CFLAGS) freetest.c

free.o : free.c free.h
	gcc -c $(CFLAGS) free.c

