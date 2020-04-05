CC=gcc
FLAGS= -Wall -g -fPIC

all: main2_1 main2_2 main2_3 main2_4

main2_1: main2_1.c
	$(CC) $(FLAGS) -o main2_1 main2_1.c

main2_2: main2_2.c
	$(CC) $(FLAGS) -o main2_2 main2_2.c

main2_3: main2_3.c
	$(CC) $(FLAGS) -o main2_3 main2_3.c

main2_4: main2_4.c
	$(CC) $(FLAGS) -o main2_4 main2_4.c


.PHONY: clean all

clean:
	rm -f *.o *.a *.so main2_1 main2_2 main2_3 main2_4


