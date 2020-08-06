CC=gcc
FLAGS= -Wall -g -fPIC

all: check_pid

check_pid: check_pid.c
	$(CC) $(FLAGS) -o check_pid check_pid.c

.PHONY: clean all

clean:
	rm -f *.o check_pid


