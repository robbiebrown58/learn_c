#include <stdio.h>

#define INT_TYPE 1
#define CHAR_TYPE 2
#define LONG_TYPE 3

#define DEBUG 

int main(){

#ifdef DEBUG
  printf("%s\n", "INT_TYPE is defined"); 
#endif


}
