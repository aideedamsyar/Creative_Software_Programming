all: main.o
	g++ -std=c++11 -o exception2 main.o

main.o: main.cc
	g++ -std=c++11 -c -o main.o main.cc

clean:
	rm -f main.o exception2