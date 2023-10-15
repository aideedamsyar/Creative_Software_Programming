all: main shapes
	g++ -o draw_shape main shapes

main: main.cc
	g++ -c -o main main.cc

shapes: shapes.cc shapes.h
	g++ -c -o shapes shapes.cc

clean:
	rm -f draw_shape shapes main