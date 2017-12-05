#
#  Make file for ps1
#

CC = g++
OFLAGS = -c -Wall -ansi -pedantic -Werror
CFLAGS = -Wall -ansi -pedantic -Werror
LFLAGS = -lsfml-window -lsfml-graphics -lsfml-system

all: ps1 ps1_original

ps1: main.o sierpinski.o
	$(CC) main.o sierpinski.o $(CFLAGS) $(LFLAGS) -o sierpinski

main.o: main.cpp
	$(CC) $(OFLAGS) main.cpp

sierpinski.o: sierpinski.cpp
	$(CC) $(OFLAGS) sierpinski.cpp

ps1_original: original.o original_h.o
	$(CC) original.o original_h.o $(CFLAGS) $(LFLAGS) -o original

original.o: original.cpp
	$(CC) $(OFLAGS) original.cpp

original_h.o: original_h.cpp
	$(CC) $(OFLAGS) original_h.cpp

clean:
	\rm -f *.o  *~ sierpinski original