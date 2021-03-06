#make file - dll

CFLAGS=-ansi -pedantic-errors -Wall -Wextra
DEBUG=	-g
RELEASE= '-DNDBUG -O3'
CC=gcc
TARGET=trie
INCLUDE_DIR = ../include/
SHARED_OBJ_DIR = ../lib/
RELEASE_OBJ_DIR = ../lib_release/
INNER_OBJ_DIR= ./obj/
DLL_MAKE_PATH= ../dll/makefile

.PHONY: debug
$(TARGET).out: $(SHARED_OBJ_DIR)lib$(TARGET).so $(INNER_OBJ_DIR)$(TARGET)_test.o
	$(CC) $(CFLAGS) -o $@ $(INNER_OBJ_DIR)$(TARGET)_test.o -L$(SHARED_OBJ_DIR) -l$(TARGET) -Wl,-rpath,'$$ORIGIN/../lib'

$(SHARED_OBJ_DIR)lib$(TARGET).so: $(INNER_OBJ_DIR)$(TARGET).o
	$(CC) $(CFLAGS) -shared $< -o $@

$(INNER_OBJ_DIR)$(TARGET).o: $(INCLUDE_DIR)$(TARGET).h $(TARGET).c
	$(CC) -c $(CFLAGS) $(DEBUG) -fPIC $(TARGET).c -I$(INCLUDE_DIR) -o $@

$(INNER_OBJ_DIR)$(TARGET)_test.o: $(INCLUDE_DIR)$(TARGET).h $(TARGET)_test.c
	$(CC) -c $(CFLAGS) $(DEBUG) $(TARGET)_test.c -I$(INCLUDE_DIR) -o $@

.PHONY: clean
clean:
	rm	$(INNER_OBJ_DIR)$(TARGET).o $(INNER_OBJ_DIR)$(TARGET)_test.o $(TARGET).out $(SHARED_OBJ_DIR)lib$(TARGET).so

release:
	make -f $(TARGET).mk DEBUG=$(RELEASE) SHARED_OBJ_DIR=$(RELEASE_OBJ_DIR) 
