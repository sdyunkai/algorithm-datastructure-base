// 关键在与用数组模拟动态链表特性
// 分配5个空间 只能用3个空间， 因为要预留一位表示链表末尾，预留以为表示链表头结点
// next  cur  NULL = 0 
#include <stdio.h>
#include <stdlib.h>

typedef struct StaticLinkList {
    int data;
    int cur;
} StaticLinkList;

int  InitArr(StaticLinkList * list)
{
    for(int i = 0 ; i < 4; i++) {
        list[i].cur = i+1;
    }
    list[4].cur = 0;
    int head = list[0].cur;
    list[0].cur = list[head].cur;
    list[head].cur = 0;
    return head;
}

int mallocArr1(StaticLinkList * list){
    int next = list[0].cur;
    list[0].cur = list[next].cur;
    return next;
}

void InsertArr(StaticLinkList * list, int head, int data, int idx)
{
    int next = mallocArr1(list);
    list[next].data = data;
    int i = 1;
    for ( i = 1 ; i < idx; i++) {
        head = list[head].cur;
    }

    int temp = list[head].cur;
    list[next].cur = temp;
    list[head].cur = next;
}

void DeleteArr(StaticLinkList * list ,int head, int idx)
{
     
    for (int i = 1; i < idx; i++) {
        head = list[head].cur;
    }
    int next = list[head].cur ;
    list[head].cur = list[next].cur;

    int avail = list[0].cur;
    list[0].cur = next;
    list[next].cur = avail;
}


void TraverseArr(StaticLinkList * list, int head) 
{
    while( list[head].cur != 0) {
        int next = list[head].cur;
        printf("%d, ", list[next].data);
        head = next;
    }
}

int main() {
    StaticLinkList  list[4] ; // 声明数组
    int head = InitArr(list);

    printf("\n");
    InsertArr(list, head, 3, 1);
    TraverseArr(list, head);

    printf("\n");
    InsertArr(list, head, 4, 1);
    TraverseArr(list, head);

    printf("\n");
    DeleteArr(list, head, 2);
    // printf("%d", list[2].data);
    TraverseArr(list, head);
    getchar();
    return 0;
}

