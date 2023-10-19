all: main magic_square
	g++ -o magic_square main magic_square

main: main.cc
	g++ -c -o main main.cc

magic_square: magic_square.cc magic_square.h
	g++ -c -o magic_square magic_square.cc

clean:
	rm -f magic_square magic_square main