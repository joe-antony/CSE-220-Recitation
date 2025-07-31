# Build and run the demo program
CC = gcc
CFLAGS = -g -Wall -Wextra -Wshadow -Wdouble-promotion -Wformat=2 -Wundef -DDEBUG -std=c99
TARGET = R8

all: $(TARGET)

$(TARGET): R8_linked_list.c
	$(CC) $(CFLAGS) -o $@ $<


run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
# This Makefile compiles a simple C program and provides targets to build, run, and clean up.