CFLAGS  = -pedantic -g -ansi -Wall 

city : cityMain.o 
	g++ -o city cityMain.cpp 

cityMain.o : cityMain.cpp city.h street.h building.h
	g++ -c $(CFLAGS) cityMain.cpp
