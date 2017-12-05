#
# Make file for ps5a
#
CC = g++
CFLAGS = -c -Wall -pedantic -Werror -ansi
LFLAGS = -lboost_unit_test_framework

all: ps5a

ps5a: test.o RingBuffer.o
	$(CC) -o ps5a  test.o RingBuffer.o $(LFLAGS)

test.o: RingBuffer.cpp test.cpp
	$(CC) $(CFLAGS) test.cpp

RingBuffer.o: RingBuffer.hpp RingBuffer.cpp
	$(CC) $(CFLAGS) RingBuffer.cpp

clean:
	rm -f *.o *~ ps5a
