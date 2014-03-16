#include <stdio.h>
#include <stdlib.h>

#define INT_TYPE 1
#define CHAR_TYPE 2
#define LONG_TYPE 3

//anonymous union and alias
typedef union{
  int a;
  char *cptr;
  long l;
}worker;

//struct type and alias
typedef struct container{
  int current_wtype;
  worker w1;
}container;

//struct type and alias
typedef struct container2{
  int current_wtype;
  worker *workerptr;
}*c2ptr;

void print_container(container c){
  switch(c.current_wtype){
  default:
    printf("Unknown type in union\n");
    break;
  case LONG_TYPE:
    printf("%ld\n", c.w1.l);
    break;
  case CHAR_TYPE:
    printf("%s\n", c.w1.cptr);
    break;
  case INT_TYPE:
    printf("%d\n", c.w1.a);
    break;
  }
}

void print_cptr(c2ptr c2p){
  switch(c2p -> current_wtype){
  default:
    printf("Unknown type in union\n");
    break;
  case LONG_TYPE:
    printf("%ld\n", c2p -> workerptr -> l);
    break;
  case CHAR_TYPE:
    printf("%s\n", c2p -> workerptr -> cptr);
    break;
  case INT_TYPE:
    printf("%d\n", c2p -> workerptr -> a);
    break;
  }
}

void print_regardless(c2ptr c2p){
  printf("%ld\n", c2p -> workerptr -> l);
  printf("%s\n", c2p -> workerptr -> cptr);
  printf("%d\n", c2p -> workerptr -> a);
}

struct{
  
  struct{
    int utype;
    union{
      int x;
      char *y;
      long z;
    }_isiu;
  }_iscomplex;

  int utype;
  union{
    int x;
    char *y;
    long z;
  }_iubasic;

}static s_complex;


union bits32_tag {
  int whole;
  struct {unsigned char c0,c1,c2,c3;} byte; 
} value;


int main(int/*@unused@*/argc, char/*@unused@*/**argv){

  value.whole = 4294967295;
  printf("whole value %u\n", value.whole);
  printf("byte c0 %d\n", value.byte.c0);
  printf("byte c1 %d\n", value.byte.c1);
  printf("byte c2 %d\n", value.byte.c2);
  printf("byte c3 %d\n", value.byte.c3);


  /*
  s_complex.utype = CHAR_TYPE;
  s_complex._iubasic.y = "Simple internal union";

  s_complex._iscomplex.utype = INT_TYPE;
  s_complex._iscomplex._isiu.x = 1000;  

  printf("%s\n", s_complex._iubasic.y);
  printf("%d\n", s_complex._iscomplex._isiu.x);
 
  /*
  container c;
  c.current_wtype = INT_TYPE;
  c.w1.a = 12;

  print_container(c);

  worker *wptr = malloc(sizeof *wptr);

  c2ptr cptr2 = malloc(sizeof(cptr2));
  cptr2 -> workerptr = wptr;

  cptr2 -> current_wtype = INT_TYPE;
  cptr2 -> workerptr -> a = 500;
  print_cptr(cptr2);
 
  cptr2 -> current_wtype = CHAR_TYPE;
  cptr2 -> workerptr -> cptr = "Foo Bar";
  print_cptr(cptr2);
 
  cptr2 -> current_wtype = LONG_TYPE;
  cptr2 -> workerptr -> l = 5000000000000;
  print_cptr(cptr2);
  */

  return 0;
}
