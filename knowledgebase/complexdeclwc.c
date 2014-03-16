#include <stdio.h>

/* declare signal as function (int, pointer to function (int) returning void)
   returning pointer to function (int) returning void */

void (*signal(int, void (*)(int)) ) (int);

/* simplify things a bit */
typedef void (*fptr)(int);

/* declare and define function that takes int and returns void */
  void foobar(int x){
    printf("%s%d\n", "x in foobar is ", x);
  }

 /* define signal using the typedef, compiles */
  fptr signal(int x, fptr y){
    return NULL;
  }

  /* Q1. Here I can say, void y(), void (y)(), void (*y)(), void y(int), void(y)(int)
     void (*y)(int) for the second arg and they all compile */

  fptr signal2(int x, void (*y)(int) ){
     NULL;
  }

  /* finally I want to do something like
     return a pointer to a function taking int and returning void
     but I just can't figure out how to do it. I've tried
     void (*)(int), void (int), (void (*) (int)) etc etc without success */

  /* can't get this to compile in any way */
  void (*) (int) signal3(int x, void (*y)(int) ){
    return  NULL;
  }


int main(void){

  

 
}
