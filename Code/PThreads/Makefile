#Makefile
CC = gcc
INCLUDE = /usr/lib
LIBS = -lpthread
OBJS = 

all: pgm1 pgm2 pgm3 pgm4 pgm5

pgm1: pgm1.c
	$(CC) -o pgm1 pgm1.c $(CFLAGS) $(LIBS)
pgm2: pgm2.c
	$(CC) -o pgm2 pgm2.c $(CFLAGS) $(LIBS)
pgm3: pgm3.c
	$(CC) -o pgm3 pgm3.c $(CFLAGS) $(LIBS)
pgm4: pgm4.c
	$(CC) -o pgm4 pgm4.c $(CFLAGS) $(LIBS)
pgm5: pgm5.c
	$(CC) -o pgm5 pgm5.c $(CFLAGS) $(LIBS)

clean:
	rm -f pgm1 pgm2 pgm3 pgm4 pgm5
