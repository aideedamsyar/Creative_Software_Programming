all: main classes
	g++ -o classes main classes

main: main.cc
	g++ -c -o main main.cc

classes: classes.cc classes.h
	g++ -c -o classes classes.cc

clean:
	rm -f classes classes main