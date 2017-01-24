execute: main.o radix.o
	g++ -g main.o radix.o -o execute

main.o: main.cpp radix.h
	g++ -g -c main.cpp

radix.o: radix.cpp radix.h
	g++ -g -c radix.cpp

clean:
	rm -rf *.o execute
