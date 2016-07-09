#Homework 1 makefile
CFLAGS = -Wall -Werror -g
BINS =  hw1 

all: $(BINS)

hw1: hw1.o converter.o

	gcc $(CFLAGS) $^ -o $@

hw.o: hw1.c
	gcc $(CFLAGS) -c $^

converter.o: converter.c
	gcc $(CFLAGS) -c $^ 


clean:
	rm -f *.o $(BINS)
