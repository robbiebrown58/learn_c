/* LinkedList */
typedef struct LinkedList *LLptr;

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

/* DoubleLinkedList */
typedef struct DoubleLinkedList *DLLptr;

DLLptr DLLCreate();
void DLLAddHead(void *data, DLLptr pDLL);
void DLLAddTail(void *data, DLLptr pDLL);
void DLLRemoveHead(DLLptr pPLL);
void DLLRemoveTail(DLLptr pPLL);
void DLLResetList(DLLptr pDLL);
int  DLLHasNext(DLLptr pDLL);
void *DLLGetNext(DLLptr pDLL);
void *DLLGetIth(int index, DLLptr pDLL);
int DLLGetLength(DLLptr pDLL);
void DLLFreeList(DLLptr pDLL);

/* CircularLinkedList */
typedef struct CircularLinkedList *CLLptr;
