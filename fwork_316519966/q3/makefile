CC=gcc
FLAGS= -Wall -g -fPIC

all: set_policy

set_policy: set_policy.c
	$(CC) $(FLAGS) -o set_policy set_policy.c

.PHONY: clean all

clean:
	rm -f *.o set_policy


