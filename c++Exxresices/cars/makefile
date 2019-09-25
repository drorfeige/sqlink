CFLAGS  = -pedantic -g -ansi -Wall 

car : carsMain.o 
	g++ -o car carsMain.cpp 

carsMain.o : carsMain.cpp cars.h bus.h private.h
	g++ -c $(CFLAGS) carsMain.cpp
