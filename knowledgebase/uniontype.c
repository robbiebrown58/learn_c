#include <stdio.h>
#include <stdlib.h>

//defines a union type, an alias for the union type, and an
//alias for the corresponding pointer-to-union type; it defines no
//objects. 
typedef union Foobar{
  int a;
  char *cptr;
  long l;
}Foobar, *fbar;

//defines a union type, an object of the union type, and an
//object of the corresponding pointer-to-union type. 
union Barbaz{
  int a;
  int b;
}Barbaz, *bbaz;

//defines an anonymous union type and an alias for that type
//(again, it defines no objects). 
typedef union{
  long x;
  long y;
}AArdvark;

//defines an object of an anonymous union type. 
union{
  char *cp1;
  char *cp2;
}Whoami;

int main(int argc, char** argv){
 
  Foobar fb1;
  fbar fbptr;

  Barbaz.a = 1;
  bbaz = &Barbaz;

  AArdvark advk;
  
  Whoami.cp1 ="foo";
 
  return 0;

}
