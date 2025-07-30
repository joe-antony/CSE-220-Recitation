# Build and run the demo program
CC = gcc
CFLAGS = 
TARGET = R7

all: $(TARGET)

$(TARGET): R7_2.c
	$(CC) $(CFLAGS) -o $@ $<


run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
# This Makefile compiles a simple C program and provides targets to build, run, and clean up.