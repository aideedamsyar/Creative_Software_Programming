all: main.o my_clock.o
	g++ -std=c++11  -o my_clock main.o my_clock.o

main.o: main.cc
	g++ -std=c++11 -c -o main.o main.cc

my_clock.o: my_clock.cc my_clock.h
	g++ -std=c++11 -c -o my_clock.o my_clock.cc

clean:
	rm -f main.o my_clock.o my_clock
