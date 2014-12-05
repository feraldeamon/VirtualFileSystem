# VirtualPC - David Hunt
CC = g++
CFLAGS= -c -Wall

all: disk

disk: disk.cpp disk.h
	$(CC) disk.cpp disk.h -o disk

clean:
		rm -rf *o disk