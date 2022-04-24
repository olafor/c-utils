CC=gcc
CFLAGS= -g -Wall
TARGET=main

all:
	$(CC) $(CFLAGS) test.c linkedlist.c -o $(TARGET)

clean: 
	rm $(TARGET)
