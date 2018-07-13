// 使用链队列是避免”野指针“的出现
// 当删除最有一个数据元素时候，由于一贯的认为数据元素出队列只跟队头指针有关系，会忽略队尾指针
// 当链队列中只剩有一个数据元素时，队尾指针指向的就是这个数据元素， 被删除后，队尾指针指向的空间被释放，但是如果尾指针不进行重新定义，就会变成“野指针”

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int data;
    struct Queue * next;
} Queue;

void InitQueue(Queue* queue)
{
    queue->next = NULL;
}

// 使用尾插法向链队列中添加数据元素
Queue* EnQueue(Queue * rear, int data)
{
    // new node 
    Queue* node = malloc(sizeof(Queue));
    node->data = data;
    node->next = NULL;
    rear->next = node;
    rear = node;
    return rear;
}

Queue*  DeQueue(Queue * head, Queue* rear) 
{
    if (head->next == NULL) {
        printf("queue empty");
        return rear;
    }
    Queue* temp = head->next;
    head->next = temp->next;
    if (rear==temp) {
        rear = head;
    }
    free(temp);
    return rear;
}

void QueueTrace(Queue * queue)
{
    printf("queue trace: ");
    while(queue->next != NULL) {
        queue = queue->next;
        printf("%d, ", queue->data);
    }
    printf("\n");
}

int main()
{
    // 定位头节点
    Queue * queue = malloc(sizeof(Queue));
    Queue * rear ;
    Queue * head;
    head = rear =  queue;
    InitQueue(queue);

    rear = EnQueue(rear, 1);
    rear = EnQueue(rear, 2);
    QueueTrace(queue);

    rear = DeQueue(head, rear);
    rear = DeQueue(head, rear);
    QueueTrace(queue);
    printf("%d", rear->data);

    getchar();
    return 0;
}