#include <stdio.h>

extern char **environ;
extern char etext, edata, end;


int main(int argc, char** argv){

  int i = 0;
  while(environ[i]) {
    printf("%s\n", environ[i++]);
  }

  printf("%p\n", &etext);
  printf("%p\n", &edata);
  printf("%p\n", &end);
 

  return 0;
}
