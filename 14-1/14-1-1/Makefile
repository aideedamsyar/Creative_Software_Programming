all: main.o
	g++ -std=c++11 -o container main.o

main.o: main.cc my_container.h
	g++ -std=c++11 -c -o main.o main.cc

clean:
	rm -f main.o container
