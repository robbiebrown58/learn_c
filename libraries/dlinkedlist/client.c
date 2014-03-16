#include <stdio.h>
#include <stdlib.h>
#include "listypes.h"

typedef struct _user{
  char *name;
  int age;
}User;

int main(int argc, char *argv[]){

  User *user1 = malloc(sizeof(User));
  user1 -> name = "User1";
  user1 -> age = 55;

  User *user2 = malloc(sizeof(User));
  user2 -> name = "User2";
  user2 -> age = 47;

  User *user3 = malloc(sizeof(User));
  user3 -> name = "User3";
  user3 -> age = 30;

  User *user4 = malloc(sizeof(User));
  user4 -> name = "User4";
  user4 -> age = 65;

  User *user5 = malloc(sizeof(User));
  user5 -> name = "User5";
  user5 -> age = 85;

  
  LLptr pLL = NULL;
  pLL = LLCreate();

  void print(){
    printf("---- printing list, length is %d ----\n", LLGetLength(pLL));
    LLResetList(pLL);
    
    while(LLHasNext(pLL)){
      User *u = LLGetNext(pLL);
       printf("%s\n", u -> name);
    }
  }

  //add one head, remove one head
  printf("* adding head *\n");
  LLAddHead(user1, pLL);
  print(); 

  printf("* removing head *\n");
  LLRemoveHead(pLL);
  print(); 

  //add one head, remove one tail
  printf("* adding head *\n");
  LLAddHead(user1, pLL);
  print(); 

  printf("* removing tail *\n");
  LLRemoveTail(pLL);
  print(); 

  //add one tail, remove one tail
  printf("* adding tail *\n");
  LLAddTail(user1, pLL);
  print(); 

  printf("* removing tail *\n");
  LLRemoveTail(pLL);
  print(); 

  //add one tail, remove one head
  printf("* adding tail *\n");
  LLAddTail(user1, pLL);
  print(); 

  printf("* removing head *\n");
  LLRemoveHead(pLL);
  print(); 

  //add two heads, remove two heads
  printf("* adding head *\n");
  LLAddHead(user1, pLL);
  print(); 

  printf("* adding head *\n");
  LLAddHead(user2, pLL);
  print(); 

  printf("* removing head *\n");
  LLRemoveHead(pLL);
  print(); 

  printf("* removing head *\n");
  LLRemoveHead(pLL);
  print(); 

  //add two heads, remove two tails
  printf("* adding head *\n");
  LLAddHead(user1, pLL);
  print(); 

  printf("* adding head *\n");
  LLAddHead(user2, pLL);
  print(); 

  printf("* removing tail *\n");
  LLRemoveTail(pLL);
  print(); 

  printf("* removing tail *\n");
  LLRemoveTail(pLL);
  print(); 

  //add two tails, remove two tails
  printf("* adding tail *\n");
  LLAddTail(user1, pLL);
  print(); 

  printf("* adding tail *\n");
  LLAddTail(user2, pLL);
  print(); 

  printf("* removing tail *\n");
  LLRemoveTail(pLL);
  print(); 

  printf("* removing tail *\n");
  LLRemoveTail(pLL);
  print(); 

  //add two tails, remove two heads
  printf("* adding tail *\n");
  LLAddTail(user1, pLL);
  print(); 

  printf("* adding tail *\n");
  LLAddTail(user2, pLL);
  print();

  printf("* removing head *\n");
  LLRemoveHead(pLL);
  print(); 

  printf("* removing head *\n");
  LLRemoveHead(pLL);
  print();  

  LLFreeList(pLL); 
 
  free(user1);
  free(user2);
  free(user3);
  free(user4);
  free(user5); 
 
 
  return 0;

}
