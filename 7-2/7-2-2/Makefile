all: main print_info
	g++ -o print_info main print_info

main: main.cc
	g++ -c -o main main.cc

print_info: print_info.cc print_info.h
	g++ -c -o print_info print_info.cc

clean:
	rm -f print_info print_info main