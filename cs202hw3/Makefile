# Makefile Author: Bulut Gozubuyuk ID: 21702771 Assignment: 3
# std c11 commented

OBJS= heap.o heapsort.o
SOURCE= heap.cpp heapsort.cpp
HEADER= heap.h
OUT= heapsort
CC= g++
FLAGS= -g -c

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)
heap.o: heap.cpp
	$(CC) $(FLAGS) heap.cpp
heapsort.o: heapsort.cpp
	$(CC) $(FLAGS) heapsort.cpp

#heap.o: heap.cpp
#	$(CC) $(FLAGS) heap.cpp -std=c11

#heapsort.o: heapsort.cpp
#	$(CC) $(FLAGS) heapsort.cpp -std=c11
clean:
	rm -f $(OBJS) $(OUT)