#include <stdio.h>


int main(){

  //00011001
  int a = 25;

  //00100100
  int b = 36;

  //00011001
  //00100100
  //00111101 = 61

  int c = a | b;

  printf("%d\n", c);
}
