CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -std=c99
LDFLAGS = -lcriterion

SRC_DIR = src
TEST_DIR = tests
INCLUDE_DIR = include

SRC_FILES = $(SRC_DIR)/Sample.c
TEST_FILES = $(TEST_DIR)/Sample_test.c

TARGET = test_sample

.PHONY = all test clean

all: $(TARGET)

$(TARGET): $(SRC_FILES) $(TEST_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
	rm -f $(TEST_DIR)/*.o