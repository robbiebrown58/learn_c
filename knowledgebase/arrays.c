#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SIZE 5

void show(char *array){
  printf("%c\n", array[0]);
}

int main(int argc, char **argv){
  
  char *pc = malloc(sizeof *pc * 10);
  memset(pc, 33, 10);
  //p pi 0x00602010

  char **ppc = &pc;
  //p ppi 0x7fffffffde40 -> 0x00602010  

  char ***pppc = &ppc; 
  //p pppi 0x7fffffffde48 -> 0x7fffffffde40 -> 0x00602010

  char ac[10];
  
  char (*pac)[10] = &ac;

  memset(pac, 'a', 10);
  
  

  char a1 [] = "arsebiscuits";
  //(gdb) p &a1
  //$11 = (char (*)[13]) 0x7fffffffde60
  //(gdb) x/1xb 0x7fffffffde60
  //0x7fffffffde60: 0x61 'a'
  //(gdb) 
  //0x7fffffffde61: 0x72 'r'
  //(gdb) 
  //0x7fffffffde62: 0x73 's'
  //(gdb) 
  //0x7fffffffde63: 0x65 'e' ...

  char *p1 = "arsebiscuits";
  //(gdb) p &p1
  //$15 = (char **) 0x7fffffffde58
  //(gdb) x/1xw 0x7fffffffde58
  //0x7fffffffde58: 0x004006e0
  //(gdb) x/1xb 0x004006e0
  //0x4006e0:       0x61
  //(gdb) 
  //0x4006e1:       0x72
  //(gdb) 
  //0x4006e2:       0x73
  //(gdb) 
  //0x4006e3:       0x65
  
  /*

  //declare ap as pointer to array 5 of int, no storage set aside
  int (*p) [5];
  //p contains a memory address 0x7fffffffdf60
  printf("%s %p\n", "p is ", p);
  //*p or p[0] is an (uninitialized) array 5 of int {1, 0, -7647, -32767, 0}
  printf("%s %p\n", "*p is ", *p);
  printf("%s %p\n", "p[0] is ", p[0]);
  //**p or *p[0] is the first element of the array (1)
  printf("%s %d\n", "**p is ", **p);
  printf("%s %d\n", "*p[0] is ", *p[0]);


  int a1[] = {10, 11, 12, 13, 14};

  p = &a1;

  **p = 16;
  *(*p + 1) = 17;

  int (*ap2) [5];

  ap2 = malloc(sizeof(int) * 5);

  **ap2 = 18;
  *(*ap2 + 1) = 19;

  /*

  char *str1 = malloc(sizeof(*str1) * SIZE);

  *str1 = 'A';
  *(str1 + 1) = 'B';
  *(str1 + 2) = 'C';
  *(str1 + 3) = 'D';
  *(str1 + 4) = '\0'; 

  show(str1);

  //(gdb) p &str1
  //$1 = (char **) 0x7fffffffde78

  //(gdb) p str1
  //$2 = 0x602010 "ABCD"

  //(gdb) x /1xg 0x7fffffffde78
  //0x7fffffffde78: 0x0000000000602010

  //(gdb) x/1xb 0x602010
  //0x602010:       0x41
  //(gdb) 
  //0x602011:       0x42
  //(gdb) 
  //0x602012:       0x43
  //(gdb) 
  //0x602013:       0x44
  //(gdb) 
  //0x602014:       0x00

  char str2[SIZE];

  str2[0] = 'F';
  str2[1] = 'G';
  str2[2] = 'H';
  str2[3] = 'I';
  str2[4] = '\0';

  //(gdb) p &str2
  //$2 = (char (*)[5]) 0x7fffffffde80

  //(gdb) p str2
  //$3 = "FGHI"

  //(gdb) x/1xb 0x7fffffffde80
  //0x7fffffffde80: 0x46
  //(gdb) 
  //0x7fffffffde81: 0x47
  //(gdb) 
  //0x7fffffffde82: 0x48
  //(gdb) 
  //0x7fffffffde83: 0x49
  //(gdb) 
  //0x7fffffffde84: 0x00
  //(gdb) 

  show(str2);
  */
  
  return 0;
}




