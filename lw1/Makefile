CC = g++
CFLAGS = -Wall -c

all: delvowels

delvowels: functions.o delvowels.o
	$(CC) functions.o delvowels.o -o delvowels

functions.o: functions.cpp functions.h
	$(CC) $(CFLAGS) functions.cpp

delvowels.o: delvowels.cpp functions.h
	$(CC) $(CFLAGS) delvowels.cpp

clean:
	rm -f *.o delvowels
