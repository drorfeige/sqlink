CFLAGS  = -pedantic -g -ansi -Wall 

cal : calenderMain.o calender.o meeting.o
	g++ -o cal calenderMain.o calender.o meeting.o 

calenderMain.o : calenderMain.cpp calender.h meeting.h
	g++ -c $(CFLAGS) calenderMain.cpp

calender.o : calender.cpp calender.h meeting.h
	g++ -c $(CFLAGS) calender.cpp

meeting.o : meeting.cpp meeting.h
	g++ -c $(CFLAGS) meeting.cpp
