CFLAGS=-g -Wall -O2 -pedantic $(shell pkg-config --cflags glib-2.0)
CFLAGS=-g -Wall -O2 -pedantic

LDFLAGS=$(shell pkg-config --libs glib-2.0)

server1: server1.c
	gcc $(CFLAGS) -o $@ $<
server: server.c
	gcc $(CFLAGS) -o $@ $<  -lpthread
	
.PHONY: clean
clean:
	rm -f server server1
