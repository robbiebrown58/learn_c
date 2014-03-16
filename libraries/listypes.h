/* LinkedList */
typedef struct LinkedList *LLptr;
typedef int(*COMPARE)(void*, void*);
/* I think this says that a Stack 'is a' LLptr */
typedef LLptr Stack;

LLptr LLCreate();
void LLAddHead(void *data, LLptr pLL);
void LLAddTail(void *data, LLptr pLL);
void LLRemoveHead(LLptr pLL);
void LLRemoveTail(LLptr pLL);
void LLResetList(LLptr pLL);
int  LLHasNext(LLptr pLL);
void *LLGetNext(LLptr pLL);
void *LLGetIth(int index, LLptr pLL);
int LLGetLength(LLptr pLL);
void LLFreeList(LLptr pLL);
void *LLFind(LLptr pLL, COMPARE compare, void *data);
void LLDelete(LLptr pLL, void *data);

/* DoubleLinkedList */
typedef struct DoubleLinkedList *DLLptr;

/* CircularLinkedList */
typedef struct CircularLinkedList *CLLptr;
