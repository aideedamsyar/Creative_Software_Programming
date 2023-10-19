all: main print_member
	g++ -o print_member main print_member

main: main.cc
	g++ -c -o main main.cc

print_member: print_member.cc print_member.h
	g++ -c -o print_member print_member.cc

clean:
	rm -f print_member print_member main