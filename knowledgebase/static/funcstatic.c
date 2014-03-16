#include <stdlib.h>

//if this is static it can't be seen 'extern'
//static int bar = 10;

//this isn't static and can be seen 'extern'
int bar = 10;

//if this is static it can't be seen 'extern'
//static int (*fptr) (void);

//this isn't static and can be seen 'extern'
int (*fptr) (void);

struct Bozza{
  char *foobar;
  char *barbaz;
};

int somefunc(void){
  static int foo;
  foo++;
  fptr = somefunc;
  return foo;
}
