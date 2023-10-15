draw_shape: canvas.o main.o
	g++ -o draw_shape canvas.o main.o
canvas.o: canvas.cc
	g++ -c -o canvas.o canvas.cc
main.o: main.cc
	g++ -c -o main.o main.cc
clean:
	rm draw_shape canvas.o main.o