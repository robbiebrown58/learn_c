#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define COUNT 5

typedef struct boundedArray{
  int count;
  void **array;  
}BoundedArray;


int main(int argc, char *argv[]){

  //p &daarr (char ***) 0x7fffffffde40
  // x/1xg 0x7fffffffde40 0x602010
  char **daarr = malloc(sizeof *daarr * 5); //p daarr 0x602010

  *(daarr + 0) = malloc(sizeof("Foo") + 1);           //p *(daarr + 0) 0x602040
  strcpy(*(daarr + 0), "Foo");

  *(daarr + 1) = malloc(sizeof("BarBar") + 1);        //p *(daarr + 1) 0x602060 
  strcpy(*(daarr + 1), "BarBar");

  *(daarr + 2) = malloc(sizeof("BazBazBaz") + 1);     //p *(daarr + 2) 0x602080
  strcpy(*(daarr + 2), "BazBazBaz");

  *(daarr + 3) = malloc(sizeof("BuzBuz") + 1);        //p *(daarr + 3) 0x6020a0 
  strcpy(*(daarr + 3), "BuzBuz");

  *(daarr + 4) = malloc(sizeof("Boz") + 1);           //p *(daarr + 4) 0x6020c0
  strcpy(*(daarr + 4), "Boz");

  for(int i = 0; i < 5; i++){
    printf("%s\n", *(daarr + i));
  }

  /*
  //p &dsarr (char ***) - 0x7fffffffde50
  //x/1xg 0x7fffffffde50 - 0x602010
  char **dsarr = malloc(sizeof *dsarr * 5); //p dsarr 0x602010
  *(dsarr + 0) = "Foo";                     //p *(dsarr + 0) 0x4006cc
  *(dsarr + 1) = "BarBar";                  //p *(dsarr + 1) 0x4006d0
  *(dsarr + 2) = "BazBazBaz";               //p *(dsarr + 2) 0x4006d7
  *(dsarr + 3) = "BuzBuz";                  //p *(dsarr + 3) 0x4006e1
  *(dsarr + 4) = "Boz";                     //p *(dsarr + 4) 0x4006e8

  for(int i = 0; i < 5; i++){
    printf("%s\n", *(dsarr + i));
  }
  */
  
  /*
  //p &psarr (char ***) - 0x7fffffffde50
  //x/1xg 0x7fffffffde50 - 0x00007fffffffde20
  char *sarr[COUNT] = {"Foo", "BarBar", "BazBazBaz", "BuzBuz", "Boz"};
  char **psarr = sarr;                       //p psarr 0x7fffffffde20
                                             //p *(psarr + 0) 0x40065c
                                             //p *(psarr + 1) 0x400660
                                             //p *(psarr + 2) 0x400667
                                             //p *(psarr + 3) 0x400671
                                             //p *(psarr + 4) 0x400678
                                             

  for(int i = 0; i < 5; i++){
    printf("%s\n", *(sarr + i));
  }

  /*
  
  BoundedArray *sba = malloc(sizeof *sba);

  sba -> count = COUNT;
  sba -> array = (void**)psarr;

  for(int i = 0; i < 5; i++){
    printf("%s\n", *(((char**)sba -> array) + i));
  }

  /*--------------- ints ----------------*/

  /*
  int arr[COUNT] = {10, 11, 12, 13, 14};
  int *parr = arr;     
  int **pparr = &parr; 

  BoundedArray *iba = malloc(sizeof *iba);

  iba -> count = COUNT;
  iba -> array = (void**)pparr;

  for(int i = 0; i < iba -> count; i++){
    printf("%d\n", *(*((int**)iba -> array)) + i);
  }

  /*
  int arr[COUNT] = {10, 11, 12, 13, 14};
  int *parr = arr;      //0x7fffffffde30
  int **pparr = &parr;  //0x7fffffffde50

  //(gdb) x/1xg 0x7fffffffde50
  //0x7fffffffde50: 0x00007fffffffde30

  //(gdb) x/1xw 0x7fffffffde30
  //0x7fffffffde30: 0x0000000a
  //0x7fffffffde34: 0x0000000b
  //0x7fffffffde38: 0x0000000c
  //0x7fffffffde3c: 0x0000000d
  //0x7fffffffde40: 0x0000000e

  BoundedArray *ba = malloc(sizeof *ba);

  ba -> count = COUNT;
  ba -> array = (void**)pparr;

  for(int i = 0; i < ba -> count; i++){
    printf("%d\n", *(*((int**)ba -> array)) + i);
  }

  int **pparr2 = (int**)ba -> array;

  for(int i = 0; i < ba -> count; i++){
     printf("bar");
     printf("%d\n", *(*pparr2) + i);
  }
  
  printf("%d\n", *(*pparr2) + 0);
  printf("%d\n", *(*pparr2) + 1);
  printf("%d\n", *(*pparr2) + 2);
  printf("%d\n", *(*pparr2) + 3);
  printf("%d\n", *(*pparr2) + 4);

  /*
  printf("%d\n", arr[0]);
  printf("%d\n", arr[1]);
  printf("%d\n", arr[2]);
  printf("%d\n", arr[3]);
  printf("%d\n", arr[4]);
  printf("%s\n", "-------------------------");
  printf("%d\n", *(arr + 0));
  printf("%d\n", *(arr + 1));
  printf("%d\n", *(arr + 2));
  printf("%d\n", *(arr + 3));
  printf("%d\n", *(arr + 4));
  printf("%s\n", "-------------------------");
  printf("%d\n", *(*pparr) + 0);
  printf("%d\n", *(*pparr) + 1);
  printf("%d\n", *(*pparr) + 2);
  printf("%d\n", *(*pparr) + 3);
  printf("%d\n", *(*pparr) + 4);
  printf("%s\n", "-------------------------");
  */
  
  
  return 0;
}
