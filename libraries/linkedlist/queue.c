#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

Queue QCreate(){
  return LLCreate();
}

void Qenqueue(void *data, Queue queue){
  LLAddTail(data, queue);
}

void Qdequeue(Queue queue){
  LLRemoveHead(queue);
}

