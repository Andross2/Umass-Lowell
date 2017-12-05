#
#  Make file for ps4
#

CC = g++
CFLAGS = -c -g -Wall -pedantic -Werror -ansi
LFLAGS = -lsfml-system

all: ED

ED: Main.o ED.o
	$(CC) -o ED -g Main.o ED.o $(LFLAGS)

Main.o: ED.cpp Main.cpp
	$(CC) $(CFLAGS) Main.cpp

ED.o: ED.hpp ED.cpp
	$(CC) $(CFLAGS) -O2 ED.cpp

clean:
	rm -f *.o *~ ED
