all: main.o message.o
	g++ -o message_book main.o message.o

main.o: main.cc
	g++ -c -o main.o main.cc

message.o: message.cc message.h
	g++ -c -o message.o message.cc

clean:
	rm -f main.o message.o message_book
