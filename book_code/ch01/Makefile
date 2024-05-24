
CC=gcc


OBJ_DIR := ./obj
BUILD_DIR := ./build
SRC_DIR := ./src
INC_DIR := ./include
FINAL_TARGET := $(BUILD_DIR)/http $(BUILD_DIR)/webserver

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')

DEPS := $(INC_DIR)/base64.h

//OBJS := $(SRCS:%=$(OBJ_DIR)/%.o)

OBJS := $(OBJ_DIR)/base64.o $(OBJ_DIR)/http.o $(OBJ_DIR)/webserver.o

CFLAGS := -Wall -I.

all: $(FINAL_TARGET)

base64.o: base64.c base64.h
	$(CC) $(CFLAGS) -c $< -o $@


http.o: http.c base64.h
	$(CC) $(CFLAGS) -c $< -o $@

webserver.o: webserver.c base64.h
	$(CC) $(CFLAGS) -c $< -o $@

http: http.o base64.o
	$(CC) $(CFLAGS) $^ -o $@

webserver: webserver.o base64.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm *.o
	rm http
	rm webserver
