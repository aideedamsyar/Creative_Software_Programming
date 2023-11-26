all: main.o my_vector.o
	g++ -o MyVector main.o my_vector.o

main.o: main.cc
	g++ -c -o main.o main.cc

my_vector.o: my_vector.cc my_vector.h
	g++ -c -o my_vector.o my_vector.cc

clean:
	rm -f main.o my_vector.o MyVector
