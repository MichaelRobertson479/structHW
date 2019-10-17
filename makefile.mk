all: main.o
	gcc -o program main.o

main.o: struct.c
	gcc -c struct.c

run:
	./program