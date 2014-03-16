#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

Stack SCreate(){
  return LLCreate();
}

void SPush(void *data, Stack stack){
  LLAddHead(data, stack);
}

void *SPop(Stack stack){
  LLResetList(stack);
  void *data = STop(stack);
  if(NULL != data){
    LLRemoveHead(stack);
  }
  return data;
}

void *STop(Stack stack){
  LLResetList(stack);
  void *data = NULL;
  if(LLHasNext(stack)){
    data = LLGetNext(stack);
  }
  return data;
}

