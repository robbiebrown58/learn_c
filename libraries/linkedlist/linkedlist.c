#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

typedef struct _node{
  void *data;
  struct _node *next;
}Node;

struct LinkedList{
  Node *head;
  Node *tail;
  Node *pointer;
  int len;
};

//--- 'private' functions ---
Node *newNode(void *data){
  Node *node = malloc(sizeof(Node)); 
  node -> data = data;
  node -> next = NULL;
  return node;
}

//--- 'public' functions ---
LLptr LLCreate(){
  LLptr pLL = malloc(sizeof(struct LinkedList));
  pLL -> head = NULL;
  pLL -> tail = NULL;
  pLL -> pointer = NULL;
  pLL -> len = 0;
}

void LLAddHead(void *data, LLptr pLL){
  Node *node = newNode(data);
  if(pLL -> head == NULL){
    pLL -> tail = node;
    node -> next = NULL; 
  }
  else{
    node -> next = pLL -> head; 
  }
  pLL -> head = node;
  pLL -> len = pLL -> len++;
}

void *LLGetHead(LLptr pLL){
  if(NULL != pLL -> head){
    return pLL -> head -> data;
  }
  else{
    return NULL;
  }
}

void LLRemoveHead(LLptr pLL){
  if(NULL != pLL -> head){
    if(NULL == pLL -> head -> next){
      free(pLL -> head);
      pLL -> head = NULL;
      pLL -> tail = NULL;
      pLL -> pointer = NULL;
    }
    else{
      pLL -> pointer = pLL -> head;
      pLL -> head = pLL -> head -> next;
      free(pLL -> pointer);
      pLL -> pointer = pLL -> head;
    }
    pLL -> len = pLL -> len - 1;
  }
}

void LLAddTail(void *data, LLptr pLL){
  Node *node = newNode(data);
  if(pLL -> tail == NULL){
    pLL -> head = node;
    node -> next = NULL; 
  }
  else{
    pLL -> tail -> next = node;
  }
  pLL -> tail = node;
  pLL -> len = pLL -> len++;
}

void LLRemoveTail(LLptr pLL){
  if(NULL != pLL -> tail){
    pLL -> pointer = pLL -> head;
    if(NULL == pLL -> head -> next){
      LLRemoveHead(pLL);
    }
    else{
      while(pLL -> pointer -> next != pLL -> tail){
	pLL -> pointer = pLL -> pointer -> next;
      }
      free(pLL -> tail);
      pLL -> tail = pLL -> pointer;
      pLL -> tail -> next = NULL;
      pLL -> len = pLL -> len -1;
    }  
  }
}

void LLResetList(LLptr pLL){
  pLL -> pointer = pLL -> head;
}

int LLHasNext(LLptr pLL){
  return pLL -> pointer != NULL;
}

void *LLGetNext(LLptr pLL){
  void *data = pLL -> pointer -> data;
  pLL -> pointer = pLL -> pointer -> next;
  return data;
}

int LLGetLength(LLptr pLL){
  return pLL -> len;
}

void LLFreeList(LLptr pLL){
  LLResetList(pLL);
  while(pLL -> pointer != NULL){
    pLL -> pointer = pLL -> pointer -> next;
    free(pLL -> head);
    pLL -> head = pLL -> pointer;
  }
  free(pLL);
}

void *LLFind(LLptr pLL, COMPARE compare, void *data){
  LLResetList(pLL);
  while(LLHasNext(pLL)){
    void *next = LLGetNext(pLL);
    //if next == data ???
    if(compare(next, data) == 0){
      return next;
    }
  }
  return NULL;
}

//pass a User, check the user, delete the user and the node
void LLDelete(LLptr pLL, void *data){
  LLResetList(pLL);
  if(NULL != pLL -> head){
    if(pLL -> head -> data == data){
      printf("Deleting head\n");
      LLRemoveHead(pLL);
    }
    else if(pLL -> tail -> data == data){
      printf("Deleting tail\n");
      LLRemoveTail(pLL);
    }
    else{
    }
  }
}
