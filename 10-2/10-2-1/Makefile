all: main.o setfunc.o
	g++ -o simple_int_set main.o setfunc.o

main.o: main.cc
	g++ -c -o main.o main.cc

setfunc.o: setfunc.cc setfunc.h
	g++ -c -o setfunc.o setfunc.cc

clean:
	rm -f main.o setfunc.o simple_int_set
