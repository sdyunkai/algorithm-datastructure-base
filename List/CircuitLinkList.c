#include <stdlib.h>
#include <stdio.h>

// 循环链表
typedef struct node
{
    int number;
    struct node *next;
} person;

person *InitList(int n)
{
    person *head = (person *)malloc(sizeof(person));
    head->number = 1;
    head->next = NULL;
    person *cyclic = head;
    for (int i = 2; i <= n; i++)
    {
        person *body = malloc(sizeof(person));
        body->number = i;
        body->next = NULL;
        cyclic->next = body;
        cyclic = cyclic->next;
    }
    cyclic->next = head;
    return head;
}

void FindAndKill(person *head, int k, int m)
{
    person *tail = head;
    // 找到链表第一个结点的上一个结点，为删除操作做准备
    while (tail->next != head)
    {
        tail = tail->next;
    }
    person *p = head;
    // 找到编号为k的人
    while (p->number != k)
    {
        tail = p;
        p = p->next;
    }

    //从编号为k的人开始， 只有符合p->next=p 时， 说明链表中除了P结点�? 所有编号都出列了�?
    while (p->next != p)
    {
        for (int i = 1; i < m; i++)
        {
            tail = p;
            p = p->next;
        }
        tail->next = p->next;
        printf("out person number: %d, \n", p->number);
        free(p);
        p = tail->next; // 继续使用p指针，指向出列编号的下一个编号，游戏继续
    }
    printf("the last person %d alive", p->number);
}

int main()
{

    // init game player  5
    person *head = InitList(5);

    // 从第1个人开始报数， 数到2的人出列

    FindAndKill(head, 1, 2);

    getchar();
    return 0;
}