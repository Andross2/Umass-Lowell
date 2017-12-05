# Makefile for ps7b
all:
	make ps7b

ps7b: ps7b.o kronos_parse.o
	g++ -o ps7b ps7b.o kronos_parse.o -lboost_regex -lboost_date_time

ps7b.o:
	g++ -c ps7b.cpp -ansi -pedantic -Wall -Werror
	
kronos_parse.o: kronos_parse.hpp kronos_parse.cpp
	g++ -c kronos_parse.cpp -ansi -pedantic -Wall -Werror
	
clean:
	rm -f *.o *~ ps7b
	
test:

	g++ -o test stdin_boost.cpp -lboost_regex
	
r:
	./test
run:
	./ps7b device4_intouch.log
