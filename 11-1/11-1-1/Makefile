all: main.o
	g++ -o match main.o

main.o: main.cc
	g++ -c -o main.o main.cc

clean:
	rm -f main.o match
