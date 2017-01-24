execute: main.o quick.o
	g++ -g main.o quick.o -o execute

main.o: main.cpp quick.h
	g++ -g -c main.cpp

quick.o: quick.cpp quick.h
	g++ -g -c quick.cpp

clean:
	rm -rf *.o execute
