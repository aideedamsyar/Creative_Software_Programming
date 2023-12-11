all: main.o
	g++ -std=c++11 -o list main.o

main.o: main.cc list.h
	g++ -std=c++11 -c -o main.o main.cc

clean:
	rm -f main.o list
