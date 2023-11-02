all: main.o intset.o
	g++ -o integer_set main.o intset.o

main.o: main.cc
	g++ -c -o main.o main.cc

intset.o: intset.cc intset.h
	g++ -c -o intset.o intset.cc

clean:
	rm -f main.o intset.o integer_set
