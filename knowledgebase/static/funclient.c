#include <stdio.h>
#include <stdlib.h>
#include "funcstatic.h"

int main(int argc, char **argv){

  extern int bar;

  extern int (*fptr) (void);

  extern struct Bozza buzz;
  
  printf("%s %d\n", "bar is ", bar);

  int c = somefunc();
  printf("%s%d\n", "Hello World, c is ", c);
  c = somefunc();
  printf("%s%d\n", "Hello World, c is ", c);
  c = somefunc();
  printf("%s%d\n", "Hello World, c is ", c);  
  c = somefunc();
  printf("%s%d\n", "Hello World, c is ", c); 

  c = fptr();
  printf("%s%d\n", "Hello World, c is ", c); 

  buzz.foobar = "Hello Foo";

  return 0;
}
