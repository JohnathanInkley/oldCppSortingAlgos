execute: main.o merge.o
	g++ -g main.o merge.o -o execute

main.o: main.cpp merge.h
	g++ -g -c main.cpp

merge.o: merge.cpp merge.h
	g++ -g -c merge.cpp

clean:
	rm -rf *.o execute
