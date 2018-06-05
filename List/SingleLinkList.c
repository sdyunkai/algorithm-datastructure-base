#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkList.h"

SingleLinkList* InitList()
{
    SingleLinkList * linkList = (SingleLinkList *)malloc(sizeof(SingleLinkList));
    SingleLinkList * head = linkList;
    linkList->next = NULL;
    for(int i = 0 ; i < 4; i++) {
        SingleLinkList * node = (SingleLinkList *)malloc(sizeof(SingleLinkList));
        node->data = i;
        node->next = NULL;
        head->next = node;
        head = head->next;
    }
    return linkList;
}

void Traverse(SingleLinkList * linkList)
{
    SingleLinkList * node = linkList;
    while( node->next ) {
        node = node->next;
        printf("%d, ", node->data);
    }
}

int SelectNode(SingleLinkList * linkList, int data)
{
    SingleLinkList* node  = linkList;
    int i = 0;
    while(node->next) {
        node = node->next;
        if (node->data == data) {
            return i; 
        }
        i++;
    }
    return -1;
}

int UpdateNode(SingleLinkList * linkList, int data, int idx)
{
    SingleLinkList* node  = linkList;
    int i = 0;
    while(node->next) {
        node = node->next;
        i++;
        if (i == idx) {
            node->data = data;
            return 0;
        }
    }
    return -1;
}

int InsertNode(SingleLinkList * linkList, int data, int idx)
{
    SingleLinkList* node  = linkList;
    SingleLinkList* target = (SingleLinkList*)malloc(sizeof(SingleLinkList));
    target->data = data;
    int i = 0;
    while(node->next) {
        if (idx -1 == i) {
            break;
        }
        node = node->next;
        i++;
    }
    if (i == idx-1) {
        target->next = node->next;
        node->next = target;
        return 0;
    }

    return -1;
}

int DeleteNode(SingleLinkList * linkList, int idx)
{
    SingleLinkList* node  = linkList;
    int i = 0;
    while(node->next) {
        if (i == idx - 1) {
            SingleLinkList * temp = node->next;
            node->next = node->next->next;
            free(temp);
            return 0;
        }
        node = node->next;
        i++;
    }
    return -1;
}
