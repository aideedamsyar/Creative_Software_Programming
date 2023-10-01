all: main message
	g++ -o final main message

main: main.cc message.h
	g++ -c -o main main.cc

message: message.cc message.h
	g++ -c -o message message.cc

clean:
	rm -f main message final