/* LinkedList */
typedef struct LinkedList *LLptr;
typedef int(*COMPARE)(void*, void*);

typedef LLptr List;

LLptr LLCreate();
void LLAddHead(void *data, LLptr pLL);
void *LLGetHead(LLptr pLL);
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

/* LIFO Stack */
typedef LLptr Stack;

Stack SCreate();
void SPush(void *data, Stack stack);
void *SPop(Stack stack);
void *STop(Stack stack);

/* FIFO Queue */
typedef LLptr Queue;

Queue QCreate();
void Qenqueue(void *data, Queue queue);
void Qdequeue(Queue queue);
