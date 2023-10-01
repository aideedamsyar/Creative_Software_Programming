all: main zebra
	g++ -o zebra main zebra

main: main.cc zebra.h
	g++ -c -o main main.cc

zebra: zebra.cc zebra.h
	g++ -c -o zebra zebra.cc

clean:
	rm -f main zebra