#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

typedef struct _user{
  char *name;
  int age;
}User;

void main(int argc, char** argv){
  printf("Hello stack client\n");

  Stack stack = NULL;
  stack = SCreate();

  void print(){
    printf("---- printing stack, count is %d ----\n", LLGetLength(stack));
    LLResetList(stack);
    
    while(LLHasNext(stack)){
      User *u = LLGetNext(stack);
      printf("%s\n", u -> name);
    }
  }

  User *user1 = malloc(sizeof(User));
  user1 -> name = "User1";
  user1 -> age = 55;

  User *user2 = malloc(sizeof(User));
  user2 -> name = "User2";
  user2 -> age = 47;

  SPush(user1, stack);
  SPush(user2, stack);

  User *usr = NULL;

  usr = STop(stack);

  printf("%s\n", usr -> name);

  SPop(stack);

  usr = STop(stack);

  printf("%s\n", usr -> name);
 
}
