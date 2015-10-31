CC=clang++
CFLAGS=-c -g

# How to use this makefile template:
# object file: source file dependencies
#	$(CC) $(CFLAGS) source file

all: fertilizer

fertilizer: main.o MarriageRecord.o 
	$(CC) main.o MarriageRecord.o -o fertilizer	

main.o: src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp

MarriageRecord.o: src/MarriageRecord.cpp src/MarriageRecord.hpp
	$(CC) $(CFLAGS) src/MarriageRecord.cpp

clean:
	rm *.o fertilizer

rebuild: clean all

test:
	./fertilizer
