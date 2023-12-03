all: main.o calendar.o
	g++ -std=c++11  -o calendar main.o calendar.o

main.o: main.cc
	g++ -std=c++11 -c -o main.o main.cc

calendar.o: calendar.cc calendar.h
	g++ -std=c++11 -c -o calendar.o calendar.cc

clean:
	rm -f main.o calendar.o calendar
