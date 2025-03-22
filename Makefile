# Makefile

CC = gcc
CFLAGS = -Wall -pthread -Iinclude
SRC_DIR = src
BIN_DIR = bin
TARGET = $(BIN_DIR)/mqtt_broker

SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/mqtt_socket.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(SOURCES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

