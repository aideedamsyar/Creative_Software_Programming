all: main.o sorted.o
	g++ -o sorted_array main.o sorted.o

main.o: main.cc
	g++ -c -o main.o main.cc

sorted.o: sorted.cc sorted.h
	g++ -c -o sorted.o sorted.cc

clean:
	rm -f main.o sorted.o sorted_array
