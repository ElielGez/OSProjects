CC=gcc
OBJECTS_MAIN=main.o
OBJECTS_LIB=hello_Ariel.o
FLAGS= -Wall -g -fPIC
all: main1_1 main1_2 main1_3

main1_1: $(OBJECTS_MAIN) $(OBJECTS_LIB)
	$(CC) $(FLAGS) -o main1_1 $(OBJECTS_MAIN) $(OBJECTS_LIB)
main1_2: $(OBJECTS_MAIN) lib
	$(CC) $(OBJECTS_MAIN) -L. -l HelloAriel -o main1_2
main1_3: main1_3.o lib
	$(CC) main1_3.o $(FLAGS) -ldl -o main1_3
lib: $(OBJECTS_LIB)
	$(CC) -shared $(OBJECTS_LIB) $(FLAGS) -o libHelloAriel.so	
hello_Ariel.o: hello_Ariel.c hello_Ariel.h
	$(CC) $(FLAGS) -c hello_Ariel.c
main.o: main.c hello_Ariel.h  
	$(CC) $(FLAGS) -c main.c -o main.o
main1_3.o: main1_3.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_3.c -o main1_3.o
.PHONY: clean all

clean:
	rm -f *.o *.a *.so main1_*.o


