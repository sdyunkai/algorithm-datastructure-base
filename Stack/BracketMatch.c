// 括号匹配问题  用栈来解决
// ( { [  入栈
// ]}) 出栈
// TestCase: ({})
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1;
void Push(char* stack, char data)
{
    stack[++top] = data;
}

void Pop(char* stack)
{
    if (top == -1) {
        printf("empty stack \n");
    }else {
        top--;
    }
}

void StackTrace(char* stack) 
{
    int cursor = top;
    while(cursor != -1) {
        printf("%c,", stack[cursor]);
        cursor--;
    }
    printf("\n");
}

int main()
{
    char* in_str = "({})";
    char stack[4];
    int len = strlen(in_str); 
    for (int i = 0 ; i < len ; i++) {
        char symbol = in_str[i];
        if (symbol == '(' || symbol == '{') {
            Push(stack, symbol);
        } else {
            Pop(stack);
        }
        StackTrace(stack);
    }
    Pop(stack);
    StackTrace(stack);
    getchar();
    return 0 ;
}