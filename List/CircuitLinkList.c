#include <stdlib.h>
#include <stdio.h>

typedef struct CircuitLinkList {
    int data;
    struct CircuitLinkList * next;
} CircuitLinkList;

CircuitLinkList * InitList() {
    CircuitLinkList * node = malloc(sizeof(CircuitLinkList));
    node->data = NULL;
    node->next = NULL;
    CircuitLinkList * head = node;
    for(int i =0 ; i < 5; i++) {
        CircuitLinkList * tempnode = malloc(sizeof(CircuitLinkList));
        node->data = i;
        node->next = NULL;
        head->data++;
        head->next = tempnode;
        head = head->next;
    }
    head->next = node;
    return node;
}

void Traverse(CircuitLinkList * list) {
    CircuitLinkList * head  = list;
    while(head->next->data) {
        printf("%d, ", head->next->data);
        head = head->next;
    }
}


int main () {

    CircuitLinkList * list = InitList();
    Traverse(list);

    // FindAndKill();
    return 0;
}