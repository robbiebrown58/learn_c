#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){

  int x;
  char buf[100];
  x = 1;
  
  snprintf(buf, sizeof(buf), argv[1]);
  printf("buffer (%d): %s\n", strlen(buf), buf);
  printf("x is %d/%#x (@ %p)\n", x, x, &x);

  //7af000 ...
  
  //ffde1c ... ffde1f - x
  //ffde20 ... ffde28 - abcdefgh/0
  //ffde29 ... ffde2f - 0
  //ffde30 ... ffde37 - stack address 0x00007fffffffde9e
  //ffde38 ... ffde3f - heap address  0x00000000004007f0
  //ffde40 ... ffde47 - 0
  //ffde48 ... ffde4f - heap address  0x00000000004004a3
  //ffde50 ... ffde57 - stack address 0x00007fffffffdf76

  //ffe238 ... ffe25c - argv[0] /home/lipska/c/practice/practice.out/0
  //ffe25d ... ffe265 - argv[1] 12345678/0
  //ffe266 ... ffefff - environment


  return 0;
}



