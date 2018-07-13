#include <stdio.h>
#include <stdlib.h>

typedef struct DblLinkList{
    struct DblLinkList * prior;
    struct DblLinkList * next;
    int data;
} DblLinkList;

DblLinkList * InitList();

DblLinkList * InsertList(DblLinkList * list, int data, int add);

void Traverse(DblLinkList * list);

DblLinkList * InitList() 
{
    DblLinkList * head = malloc(sizeof(DblLinkList));
    head->next = NULL;
    head->prior = NULL;
    head->data = 1;

    DblLinkList * p = head;
    for(int i = 2; i <=3; i++) {
        DblLinkList * node = malloc(sizeof(DblLinkList));
        node->data = i;
        node->next = NULL;
        node->prior = p;
        p->next = node;
        p = p->next;
    }

    return head;
}

DblLinkList *  InsertList(DblLinkList * list, int data, int add) 
{
    DblLinkList * node = malloc(sizeof(DblLinkList));
    node->data = data;
    node->prior = NULL;
    node->next = NULL;

    DblLinkList * head = list;
    if (add == 1) {
        head->prior = node;
        node->next = head;
        list = node;
    } else {
        int i = 1;
        while(head->next != NULL && i < add-1) {
            i++;
            head = head->next;
        }
        if(head->next ==NULL && i < add - 1) {
            printf("error position\n");
        }else if (head->next == NULL) {
            head->next = node;
            node->prior = head;
        } else {
            node->next = head->next;
            node->prior = head;
            head->next->prior = node;
            head->next = node;
        }
    }
    return list;

}

void Traverse(DblLinkList * list) 
{
    DblLinkList * head = list;

    printf(" ,%d ", head->data);    
    while(head->next != NULL) {
        head = head->next;
        printf(" ,%d ", head->data);    
    }
}

int main() 
{
    DblLinkList * list = InitList();
    // Traverse(list);

    list = InsertList(list, 12,2);
    printf("InsertList 12 on 1\n");
    Traverse(list);
    getchar();
    return 0;
}