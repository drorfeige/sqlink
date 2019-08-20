CFLAGS  = -pedantic -g -ansi -Wall 

darr : darray_test.o darray_int.o
	gcc -o darray_test.c darray_int.c

darray_test.o : darray_test.c darray_int.h
	gcc -c $(CFLAGS) darray_test.c

darray_int.o : darray_int.c darray_int.h
	gcc -c $(CFLAGS) darray_int.c
