// 单链表

typedef struct SingleLinkList {
    int data;
    struct SingleLinkList * next;
} SingleLinkList;

SingleLinkList* InitList();

int SelectNode(SingleLinkList * linkList, int data);

int UpdateNode(SingleLinkList * linkList, int data, int idx);

int InsertNode(SingleLinkList * linkList, int data, int idx);

int DeleteNode(SingleLinkList * linkList, int idx);

void Traverse(SingleLinkList * linkList);
