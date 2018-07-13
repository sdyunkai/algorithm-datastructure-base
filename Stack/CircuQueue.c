// 循环队列顺序存储实现
// 定义头指针和尾指针
// 当头尾相连时 队为空， 也可能是队满 ,增加一个额外条件, 循环的关键是采用取模算法
// 牺牲一个存储空间，队的下一个元素d
#include <stdio.h>
#include <stdlib.h>
int rear = 0;
int head = 0;
int queue_len = 3;
void Enqueue(int * q, int data) 
{
    if ( (rear+1)%queue_len == head ) {
        printf("full queue\n");
        return;
    }
    q[rear] = data;
    rear = (rear+1)%queue_len ;
}
void Dequeue(int* q) 
{
    if (head == rear) {
        printf("empty queue\n");
        return;
    }
    head = (head+1)%queue_len;
}
void QueueTrace(int* q) 
{
    printf("QueueTrace: ");
    if (rear > head) {
        for(int i = head; i < rear; i++) {
            printf("%d,", q[i]);
        }
    } else {
        for (int i = head; i < queue_len; i++) {
            printf("%d,", q[i]);
        }
        for (int i =0 ; i < rear; i++) {
            printf("%d,", q[i]);
        }
    }
    printf("\n");
}
int main()
{
    int q[queue_len];
    Enqueue(q, 1);
    Enqueue(q, 2);
    Enqueue(q, 3);
    QueueTrace(q);
    
    Dequeue(q);
    Enqueue(q, 3);
    QueueTrace(q);
    Dequeue(q);
    Enqueue(q, 4);
    QueueTrace(q);
    getchar();
    return 0;
}