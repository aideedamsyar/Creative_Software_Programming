all: main animal
	g++ -o animal main animal

main: main.cc
	g++ -c -o main main.cc

animal: animal.cc animal.h
	g++ -c -o animal animal.cc

clean:
	rm -f animal animal main