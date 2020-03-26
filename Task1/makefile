CC=gcc
AR=ar
OBJECTS_MAIN=main1_1.o
OBJECTS_LIB=hello_Ariel.o
FLAGS= -Wall -g -fPIC

all: main1_1 main1_2 main1_3

main1_1: $(OBJECTS_MAIN) $(OBJECTS_LIB)
	$(CC) $(FLAGS) -o main1_1 $(OBJECTS_MAIN) $(OBJECTS_LIB)
main1_2: $(OBJECTS_MAIN) hello_Ariel_s
	$(CC) $(FLAGS) -o main1_2 $(OBJECTS_MAIN) hello_Ariel.a
main1_3: $(OBJECTS_MAIN) hello_Ariel_d
	$(CC) $(FLAGS) -o main1_3 $(OBJECTS_MAIN) ./hello_Ariel.so
hello_Ariel_d: $(OBJECTS_LIB)
	$(CC) -shared -o hello_Ariel.so $(OBJECTS_LIB)
hello_Ariel_s: $(OBJECTS_LIB)
	$(AR) -rcs hello_Ariel.a $(OBJECTS_LIB)	
hello_Ariel.o: hello_Ariel.c hello_Ariel.h
	$(CC) $(FLAGS) -c hello_Ariel.c
main1_1.o: main.c hello_Ariel.h  
	$(CC) $(FLAGS) -c main.c -o main1_1.o

.PHONY: clean all

clean:
	rm -f *.o *.a *.so main1_*


