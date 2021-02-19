#Makefile
CC = gcc
INCLUDE = /usr/lib
LIBS =
OBJS =

all: client server

server: server.c
	$(CC) -o server server.c $(CFLAGS) $(LIBS)
client: client.c
	$(CC) -o client client.c $(CFLAGS) $(LIBS)
clean:
	rm -f server client core
