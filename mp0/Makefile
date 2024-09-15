CXX = c++

CC = $(CXX) -x c -g -Wall 
CFLAGS_CATCH = -fpermissive -w $(CS340) -pthread -g -std=c++11
CFLAGS = -W -Wall $(CS340) -pthread

.POHNY: all test clean

all: main

# .o rules:
main.o: main.c
	$(CC) $(CFLAGS) $^ -c -o $@

gif.o: gif.c
	$(CC) $(CFLAGS) $^ -c -o $@


# exe rules:
main: main.o gif.o
	${CXX} $^ -o $@


# test rules:
test: tester
	bash tester.sh

tester: tests/test.o tests/test-all.o
	$(CXX) $(CFLAGS_CATCH) $^ -o $@

tests/test.o: tests/test.cpp
	$(CXX) $(CFLAGS_CATCH) $^ -c -o $@

tests/test-all.o: tests/test-all.cpp
	$(CXX) $(CFLAGS_CATCH) $^ -c -o $@


clean:
	rm -f main tester *.o tests/*.o tests/tay-small-illinify.gif
