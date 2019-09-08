CFLAGS  = -pedantic -g -ansi -Wall 
findDup : findDmain.o hash.o files.o MD5.o 
	gcc -o findDup findDmain.o hash.o files.o MD5.o -lcrypto

findDmain.o : findDmain.c hash.h files.h
	gcc -c $(CFLAGS) findDmain.c 

files.o : files.c files.h hash.h MD5.h
	gcc -c $(CFLAGS) files.c 

hash.o : hash.c hash.h
	gcc -c $(CFLAGS) hash.c 

MD5.o : MD5.c MD5.h
	gcc -c $(CFLAGS) MD5.c 

