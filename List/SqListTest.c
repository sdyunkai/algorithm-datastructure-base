#include <stdio.h>
#include "SqList.h"

/**
 * 动态数组
 * gcc version 8.1.0 (x86_64-win32-seh-rev0, Built by MinGW-W64 project)
 * gcc -c SqList.c SqListTest.c
 * gcc SqList.o SqListTest.o -o main.exe
 */
int main ()
{
    SqList list = Init();
    Traverse(&list);
    // insert
    InsertAt(&list, 1, 2);
    Traverse(&list);
    // delete
    DeleteAt(&list, 1);
    Traverse(&list);
    // update 
    UpdateAt(&list, 1, 2);
    Traverse(&list);
    // select
    int idx = Select(&list, 2);
    printf("select 2, the idx is %d", idx);
    getchar();
    return 0;
}