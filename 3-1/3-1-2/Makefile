# 


all: main shapes
	g++ -o simple_shape main shapes

main: main.cc shapes.h
	g++ -c -o main main.cc

shapes: shapes.cc shapes.h
	g++ -c -o shapes shapes.cc

clean:
	rm main shapes simple_shape