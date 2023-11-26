all: main.o my_string.o
	g++ -o string main.o my_string.o

main.o: main.cc
	g++ -c -o main.o main.cc

my_string.o: my_string.cc my_string.h
	g++ -c -o my_string.o my_string.cc

clean:
	rm -f main.o my_string.o string
