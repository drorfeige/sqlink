CFLAGS  = -pedantic -g -ansi -Wall 

hash : hashtest.o hash.o
	gcc -o hash hashtest.o hash.o

hashtest.o : hashtest.c hash.h
	gcc -c $(CFLAGS) hashtest.c

hash.o : hash.c hash.h
	gcc -c $(CFLAGS) hash.c
