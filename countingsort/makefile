execute: main.o counting.o
	g++ -g main.o counting.o -o execute

main.o: main.cpp counting.h
	g++ -g -c main.cpp

counting.o: counting.cpp counting.h
	g++ -g -c counting.cpp

clean:
	rm -rf *.o execute
