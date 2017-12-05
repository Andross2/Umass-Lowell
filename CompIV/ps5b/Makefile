#
# Make file for ps5b
#

CC = g++
OFLAGS = -c -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -ansi -pedantic -Wall -Werror -lboost_unit_test_framework
CFLAGS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -ansi -pedantic -Wall -Werror -lboost_unit_test_framework

all: GuitarHero

GuitarHero: RingBuffer.o GuitarString.o GuitarHero.o
	$(CC) -o GuitarHero GuitarHero.o GuitarString.o RingBuffer.o $(CFLAGS)
	
GuitarHero.o: GuitarHero.cpp GuitarString.hpp RingBuffer.hpp
	$(CC) $(OFLAGS) GuitarHero.cpp

GuitarString.o: GuitarString.cpp GuitarString.hpp RingBuffer.hpp
	$(CC) $(OFLAGS) GuitarString.cpp

RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	$(CC) $(OFLAGS) RingBuffer.cpp

permissions: all
	chmod o+x GuitarHero

clean:
	rm -f *.o *~GuitarHero