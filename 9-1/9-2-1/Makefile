all: main.o shapes.o
	g++ -o shapes main.o shapes.o

main.o: main.cc
	g++ -c -o main.o main.cc

shapes.o: shapes.cc shapes.h
	g++ -c -o shapes.o shapes.cc

clean:
	rm -f main.o shapes.o shapes
