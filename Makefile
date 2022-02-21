#Tag Makefile

CC=g++
CCFLAGS=-std=c++11
LIB= -lm -lX

#build rules

tag.o: tag.cpp driver.cpp tag.h
	$(CC) $(CCFLAGS) tag.cpp driver.cpp -c

tag: tag.o driver.o
	$(CC) $(CCFLAGS) tag.o driver.o -o tag

run: tag
	./tag

clean:
	rm -f *.o tag
