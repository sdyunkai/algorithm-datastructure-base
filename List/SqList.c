#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"
#define Size 4
#define IncrementSize 2

SqList Init() 
{
    SqList list;
    list.head = (int *)malloc(sizeof(int) * Size);
    list.size = Size;
    list.len = 0;
    for(int i = 0 ; i < list.size; i++) {
        list.head[i] = i;
        list.len++;
    }
    return list;
}

void Traverse(SqList* list)
{
    printf("Traverse: ");
    for(int i = 0; i < list->len; i++) {
        printf("%d,", list->head[i]);
    }
    printf("\n");
}

int InsertAt(SqList* list, int idx, int value)
{
    if (idx < 1 || idx > list->len + 1) {
        printf("插入位置有问题");
        return 0;
    }
    if (list->len >= list->size) {
        list->head = (int *)realloc(list->head, (list->size+IncrementSize)* sizeof(int));
        if (!list->head) {
            printf("存储分配失败");
            exit(0);
        }
        list->size += IncrementSize;
    }
    
    for(int i = list->len -1; i >= idx - 1; i--) {
        list->head[i+1] = list->head[i];
    }
    list->head[0] = value;
    list->len++;
    return 1;
}

int DeleteAt(SqList* list, int idx)
{
    // 删除位置判断
    if (idx < 1 || idx > list->len) {
        printf("删除位置有误");
        exit(0);
    }
    int i = list->head[idx-1];
    // 移动元素
    for(int i = idx -1 ; i < list->len -1; i++) {
        list->head[i] = list->head[i+1];
    }
    list->len--;
    return i;
}

void UpdateAt(SqList* list, int idx, int replace)
{
    // 更新位置判断
    if (idx < 1 || idx > list->len) {
        printf("更新位置有误");
        exit(0);
    }
    list->head[idx-1] = replace;
}

int Select(SqList* list, int target)
{
    for(int i = 0; i < list->len; i++) {
        if (target == list->head[i]) {
            return i+1;
        }
    }
    return -1;
}