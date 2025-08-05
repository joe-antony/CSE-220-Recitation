# Build and run the demo program
CC = gcc
CFLAGS = -std=c99
TARGET = R9

all: $(TARGET)

$(TARGET): Pointer.c
	$(CC) $(CFLAGS) -o $@ $<


run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
# This Makefile compiles a simple C program and provides targets to build, run, and clean up.