all: struct.o
	gcc -o program main.o

struct.o: struct.c
	gcc -c struct.c

run: 
	./program