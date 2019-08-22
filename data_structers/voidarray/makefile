CFLAGS  = -pedantic -g -ansi -Wall 

generic : generictest.o darray_generic.o
	gcc -o generic generictest.o darray_generic.o

generictest.o : generictest.c darray_generic.h
	gcc -c $(CFLAGS) generictest.c

darray_generic.o : darray_generic.c darray_generic.h
	gcc -c $(CFLAGS) darray_generic.c
