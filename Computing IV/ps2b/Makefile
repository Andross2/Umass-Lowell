#
#  Make file for ps2b
#
CC = g++
CFLAGS = -c -Wall -pedantic -Werror
OFLAGS = -Wall -pedantic -Werror
LFLAGS = -lsfml-window -lsfml-graphics -lsfml-system

all: PhotoMagic PhotoMagicDeluxe

PhotoMagic: PhotoMagic.o LFSR.o
	$(CC) -o PhotoMagic PhotoMagic.o LFSR.o $(LFLAGS) $(OFLAGS)

PhotoMagic.o: PhotoMagic.cpp
	$(CC) $(CFLAGS) PhotoMagic.cpp 

PhotoMagicDeluxe: PhotoMagicDeluxe.o LFSR.o
	$(CC) -o PhotoMagicDeluxe PhotoMagicDeluxe.o LFSR.o $(LFLAGS) $(OFLAGS)

PhotoMagicDeluxe.o: PhotoMagicDeluxe.cpp
	$(CC) $(CFLAGS) PhotoMagicDeluxe.cpp 

LFSR.o: LFSR.hpp LFSR.cpp 
	$(CC) $(CFLAGS) LFSR.cpp 

clean:
	rm -f *.o *~ PhotoMagic PhotoMagicDeluxe
