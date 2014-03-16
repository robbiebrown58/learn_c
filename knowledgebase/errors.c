#include <errno.h> //apparently /usr/include/asm-generic/errno.h
#include <string.h>
#include <stdio.h>

int main(void){

  printf("%s\n", strerror(ESHUTDOWN));
  printf("%d\n", errno);
}
