CC=gcc
FLAGS= -Wall -g -fPIC

all: dir_traversal

dir_traversal: dir_traversal.c
	$(CC) $(FLAGS) -o dir_traversal dir_traversal.c

.PHONY: clean all

clean:
	rm -f *.o dir_traversal


