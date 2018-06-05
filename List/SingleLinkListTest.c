#include "SingleLinkList.h"
#include <stdio.h>

int main()
{
    SingleLinkList * head = InitList();
    printf("InitList: ");
    Traverse(head);

    printf("\nSelectNode 2: ");
    int idx= SelectNode(head, 2);
    printf("%d", idx);

    printf("\nUpdateNode 2: ");
    UpdateNode(head, 5, 2);
    Traverse(head);

    printf("\nInsertNode 2 4: ");
    InsertNode(head, 2, 4);
    Traverse(head);
    
    printf("\nDeleteNode 2 4: ");
    DeleteNode(head, 2);
    Traverse(head);
    getchar();
    return 0;
}