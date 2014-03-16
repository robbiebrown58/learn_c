all: main

main: file1.o file2.o file3.o
	gcc -std=c99 file1.o file2.o file3.o -o main.out

file3.o: file3.c
	gcc -std=c99 -g -c file3.c

file2.o: file2.c
	gcc -std=c99 -g -c file2.c

file1.o: file1.c
	gcc -std=c99 -g -c file1.c 

clean:
	rm *~ *.o *.out