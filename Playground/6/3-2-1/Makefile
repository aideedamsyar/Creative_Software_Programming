all: main accounts
	g++ -o simple_account main accounts

main: main.cc accounts.h
	g++ -c -o main main.cc

accounts: accounts.cc accounts.h
	g++ -c -o accounts accounts.cc

clean:
	rm main accounts simple_account