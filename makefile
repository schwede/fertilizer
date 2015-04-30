CC=clang++
CFLAGS=-c -Wall

all: fertilizer

fertilizer: main.o MarriageRecord.o 
	$(CC)  main.o MarriageRecord.o -o fertilizer	

main.o: src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp

MarriageRecord.o: src/MarriageRecord.cpp
	$(CC) $(CFLAGS) src/MarriageRecord.cpp

clean:
	rm *.o fertilizer

rebuild: clean all
