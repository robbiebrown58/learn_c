all: jnicalc

jnicalc: calculator.o calcdriver.o
	gcc -shared -o libcalc.so -fPIC calculator.o calcdriver.o 

calcdriver.o: calcdriver.c
	gcc -std=c99 -pedantic -fPIC -c calcdriver.c

calculator.o: calculator.c
	gcc -std=c99 -pedantic -fPIC -c calculator.c

clean:
	rm *.o *~ *.out *.so
