#include <stdio.h>

/* gcc -g -std=c99 -pedantic-errors complexdecl.c */

typedef void (*fptr)(int);

fptr foo (int, fptr);

/* a function to 'point to' */
void func(int x){
  printf("%s%d", "x in func is ", x);
}

int main(void){ 

  fptr fp2 = foo(10, func); 

  fp2(20);
 
}

fptr foo (int x, fptr f){
  return f;
}



/*
There are two substitutions to here:

   fptr signal(int x, fptr f)

The inner one is simple: you put "f" where the typedef'd name is in

   typedef void (*fptr)(int);

(removing the "typedef" keyword and the ; of course):

   fptr signal(int x, void (*f)(int))

To do the first one, let's go back to the simpler form:

   fptr signal(int x, fptr f)

The key part to know is that you can't separate a function's name from
it parameter list.  Just substituting the function name ("signal") in
the definition of the return type (void (*fptr)(int)) breaks this link:

   void (*signal)(int)(int x, fptr f)  // WRONG!

This now looks like a function that takes a single int.  The trouble is
that the function includes it's parameters -- we need to substitute
"signal(int x, fptr f)" into the defined type:

   void (*fptr)(int)
           ^
         put signal(int x, fptr f) in here:

   void (*signal(int x, fptr f))(int)

Now we can go back and do the other one as well to get the final full
type:

   void (*signal(int x, void (f)(int)))(int)
void (*signal(int, void (*)(int)) ) (int);


*/ 

   /*
fptr bar (int x, void (*f) (int));

void (*baz (int x, fptr f))(int); */

   /* void (*buz (int x, void (*f) (int)))(int); */
