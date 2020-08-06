CC=gcc
FLAGS= -Wall -g -fPIC

all: server client

server: server.c
	$(CC) $(FLAGS) -o server server.c

client: client.c
	$(CC) $(FLAGS) -o client client.c

.PHONY: clean all

clean:
	rm -f *.o server client


