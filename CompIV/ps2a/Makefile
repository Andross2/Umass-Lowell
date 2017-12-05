#
#  Make file for ps2a
#

CC = g++
CFLAGS = -lboost_unit_test_framework -Wall -ansi -pedantic -Werror
OFLAGS =  -ansi -pedantic -Wall -Werror

all: ps2a

ps2a: test.o LFSR.o
	$(CC) -o ps2a test.o LFSR.o $(CFLAGS)

test.o:	test.cpp
	$(CC) -c test.cpp $(OFLAGS)

LFSR.o: LFSR.hpp LFSR.cpp 
	$(CC) -c LFSR.cpp $(OFLAGS)

clean:
	rm -f *.o *~ ps2a
