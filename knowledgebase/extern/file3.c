/* file3.c */
#include "extern.h"
#include <stdio.h>

int main(void){
  printf("%s %d\n", "x is ", x);
  x++;
  printf("%s %d\n", "x is ", x);
  incx();
  printf("%s %d\n", "x is ", x);
  return 1;
}
