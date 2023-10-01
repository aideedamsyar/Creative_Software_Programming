all: main reply_admin
	g++ -o reply_admin main reply_admin

main: main.cc reply_admin.h
	g++ -c -o main main.cc

reply_admin: reply_admin.cc reply_admin.h
	g++ -c -o reply_admin reply_admin.cc

clean:
	rm -f main reply_admin