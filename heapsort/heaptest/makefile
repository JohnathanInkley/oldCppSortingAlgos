execute: main.o heap.o
	g++ -g main.o heap.o -o execute

main.o: main.cpp heap.h
	g++ -g -c main.cpp

heap.o: heap.cpp heap.h
	g++ -g -c heap.cpp

clean:
	rm -rf *.o execute
