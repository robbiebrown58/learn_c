#include <stdio.h>
#include <stddef.h>

int main(void) {

  struct abbcd {
    char c;
    int b;
    short d;
  };

  struct abbcd s1;
  s1.c = 'a';
  s1.b = 0xff;
  s1.d = 1;

  printf("%s%zu\n", "sizeof s1 is ", sizeof(s1));

#pragma pack(1)

  struct abbcd_packed {
    char c;
    int b;
    short d;
  }; 

  struct abbcd_packed s2;
  s2.c = 'a';
  s2.b = 0xff;
  s2.d = 1;

  printf("%s%zu\n", "sizeof s2 is ", sizeof(s2));

}
