#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXTOKENS 100
#define MAXTOKENLEN 64

enum type_tag { 
  IDENTIFIER, QUALIFIER, TYPE 
};

struct token{
  char type;
  char string[MAXTOKENLEN];
};

void printToken(struct token *t){
  printf("%s %d %s %s\n", "type is", t -> type, "string is", t -> string);
   
}

struct token stack[MAXTOKENS];

#define STRCMP(a,R,b) (strcmp(a,b) R 0)

int stop = -1;

#define push(s) stack[++stop] = s
#define pop stack[stop--]
#define top stack[stop]

int main(void){

  char *a = "hello";
  char *b = "hello";
  char *c = "goodbye";

  if(STRCMP(a, ==, b)){
    printf("%s\n", "they are the same");
  }
  else{
    printf("%s\n", "they are not the same");
  }

  struct token t1 = {IDENTIFIER, "an identifier"};
  struct token t2 = {QUALIFIER, "a qualifier"};
  struct token t3 = {TYPE, "a type"};

  push(t1);
  push(t2);
  push(t3);

  /*
  printToken(&top);
  pop;
  printToken(&top);
  pop;
  printToken(&top);
  */

  return 0;
}
