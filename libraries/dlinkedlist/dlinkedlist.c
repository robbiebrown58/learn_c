#include <stdlib.h>
#include <stdio.h>
#include "listypes.h"

typedef struct _node{
  struct _node *previous;
  void *data;
  struct _node *next;
}Node;

struct DoubleLinkedList{
  Node *head;
  Node *tail;
  Node *pointer;
  int count;
};

DLLptr DLLCreate(){
}

void DLLAddHead(void *data, DLLptr pDLL){
}

void DLLAddTail(void *data, DLLptr pDLL){
}

void DLLRemoveHead(DLLptr pPLL){
}

void DLLRemoveTail(DLLptr pPLL){
}

void DLLResetList(DLLptr pDLL){
}

int  DLLHasNext(DLLptr pDLL){
}

void *DLLGetNext(DLLptr pDLL){
}

void *DLLGetIth(int index, DLLptr pDLL){
}

int DLLGetLength(DLLptr pDLL){
}

void DLLFreeList(DLLptr pDLL){
}






/*

int main(int argc, char** argv){

  Node *newNode(void *data){
    Node *n = malloc(sizeof *n);
    n -> previous = NULL;
    n -> data = data;
    n -> next = NULL;
    return n;
  }

  DLinkedList *newDLinkedList(){
    DLinkedList *dll = malloc(sizeof *dll);
    dll -> head = NULL;
    dll -> tail = NULL;
    dll -> pointer = NULL;
    return dll;
  }

  void freeNode(Node *n){
    free(n -> data);
    free(n);
  }

  void freeList(DLinkedList *dll){
    dll -> pointer = dll -> head;
    while(NULL != dll -> pointer){
      dll -> head = dll -> head -> next;
      free(dll -> pointer);
      dll -> pointer = dll -> head;
    }
    free(dll);
  }

  DLinkedList *mydll = newDLinkedList();

  void addHead(DLinkedList *dll, Node *n){
    if(dll -> head == NULL){
      printf("head is NULL\n");
      dll -> tail = n;
      //node next and previous are NULL
    }
    else{
      printf("head is not NULL\n");
      dll -> pointer = n;
      n -> next = dll -> head;
      dll -> head -> previous = dll -> pointer;
    }
    dll -> head = n;
  }  

  char *hello = "Hello World";
  Node *n1 = newNode((void*)hello);
  addHead(mydll, n1);

  char *goodbye = "Goodbye World";
  Node *n2 = newNode((void*)goodbye);
  addHead(mydll, n2);

  char *where = "Where are you World";
  Node *n3 = newNode((void*)where);
  addHead(mydll, n3);

  //start at the back and work forward
  void printForward(DLinkedList *dll){
    dll -> pointer = dll -> tail;
    while(NULL != dll -> pointer){
      printf("%s\n", (char*)dll -> pointer -> data);
      dll -> pointer = dll -> pointer -> previous;
    }
  }

  //start at the front and print backwards
  void printBackward(DLinkedList *dll){
    dll -> pointer = dll -> head;
    while(NULL != dll -> pointer){
      printf("%s\n", (char*)dll -> pointer -> data);
      dll -> pointer = dll -> pointer -> next;
    }
  }

  printForward(mydll);
  printBackward(mydll);

  freeList(mydll);

  void addTail(DLinkedList *dll, void *data){
  }

  void deleteHead(DLinkedList *dll){
  }

  void deleteTail(DLinkedList *dll){
  }

}
*/
