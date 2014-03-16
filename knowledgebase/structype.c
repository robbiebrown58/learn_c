#include <stdio.h>
#include <stdlib.h>

//defines a struct type, an alias for the struct type, and an
//alias for the corresponding pointer-to-struct type; it defines no
//objects. 
typedef struct Foobar{
  int a;
  int b;
}Foobar, *fbar;

//defines a struct type, an object of the struct type, and an
//object of the corresponding pointer-to-struct type. 
struct Barbaz{
  int a;
  int b;
}Barbaz, *bbaz;

//defines an anonymous struct type and an alias for that type
//(again, it defines no objects). 
typedef struct{
  long x;
  long y;
}AArdvark;

//defines an object of an anonymous struct type. 
struct{
  char *cp1;
  char *cp2;
}Whoami;



int main(int argc, char** argv){

  Foobar fb1;
  fbar pfb1 = &fb1;

  Barbaz.a = 1;
  bbaz = &Barbaz;

  AArdvark advk;
  
  Whoami.cp1 ="foo";

}
