CC=gcc
CFLAGS=-Wall -g

all: main

main: main.o helper.o
	$(CC) $(CFLAGS) -o main main.o helper.o

main.o: main.c helper.h
	$(CC) $(CFLAGS) -c main.c

helper.o: helper.c helper.h
	$(CC) $(CFLAGS) -c helper.c

clean:
	rm -f *.o main

