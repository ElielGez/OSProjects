CC=gcc
FLAGS= -Wall -g -fPIC

all: check_pid server client

check_pid: check_pid.c
	$(CC) $(FLAGS) -o check_pid check_pid.c

server: server.c
	$(CC) $(FLAGS) -o server server.c

client: client.c
	$(CC) $(FLAGS) -o client client.c

.PHONY: clean all

clean:
	rm -f *.o check_pid server


