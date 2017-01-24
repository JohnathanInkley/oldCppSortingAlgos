execute: main.o bucket.o
	g++ -g main.o bucket.o -o execute

main.o: main.cpp bucket.h
	g++ -g -c main.cpp

bucket.o: bucket.cpp bucket.h
	g++ -g -c bucket.cpp

clean:
	rm -rf *.o execute
