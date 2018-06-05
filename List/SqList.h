typedef struct SqList {
    int * head;
    int len ;
    int size;
    int inrement_size;
} SqList;

SqList Init();

void Traverse(SqList* list);

int InsertAt(SqList* list, int idx, int value);

int DeleteAt(SqList* list, int idx);

void UpdateAt(SqList* list, int idx, int replace);

int Select(SqList* list, int target);