# Build and run the demo program
CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = program

all: $(TARGET)

$(TARGET): R4_revision.c
	$(CC) $(CFLAGS) -o $@ $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
# This Makefile compiles a simple C program and provides targets to build, run, and clean up.