all: main shapes
	g++ -o shapes main shapes

main: main.cc
	g++ -c -o main main.cc

shapes: shapes.cc shapes.h
	g++ -c -o shapes shapes.cc

clean:
	rm -f shapes shapes main