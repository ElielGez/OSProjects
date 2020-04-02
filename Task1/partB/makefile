CC=gcc
FLAGS= -Wall -g -fPIC

all: main1_1 main1_2 main1_3

main1_1: main1_1.c
	$(CC) $(FLAGS) -o main1_1 main1_1.c

main1_2: main1_2.c
	$(CC) $(FLAGS) -o main1_2 main1_2.c

main1_3: main1_3.c
	$(CC) $(FLAGS) -o main1_3 main1_3.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so main1_1 main1_2 main1_3


