#include <stdio.h>
#include <stdlib.h>
#define Stack_SIZE 3

typedef struct Stack {
    char data;
    struct Stack * next;
} Stack ;

void Traverse(Stack * stack);
Stack* Push(Stack * stack , int data);
Stack* Pop(Stack * stack );

void Traverse(Stack * stack) 
{
    while(stack != NULL) {
        printf(",%c", stack->data);
        stack = stack->next;
    }
}
Stack* Push(Stack * stack , int data) 
{
    Stack * node =(Stack *) malloc(sizeof(Stack));
    node->data = data;
    node->next = stack;
    stack = node;
    return stack;
}
Stack* Pop(Stack * stack )
{
    if (stack) {
        Stack* node = stack ;
        stack = stack->next;
        printf("pop element is %c", node->data);
        free(node);
        return stack;
    } else{
        printf("stack empty");
        return stack;
    }
}
int main() 
{
    // 创建头指针就行了， 不需要创建头结点
    Stack * stack = NULL;
    // push 
    stack = Push(stack, 'a');
    Traverse(stack);
    printf("\n");
    stack = Push(stack, 'b');
    Traverse(stack);
    printf("\n");
    stack = Push(stack, 'c');
    Traverse(stack);
    
    
    // pop
    printf("\n");
    stack = Pop(stack);
    Traverse(stack);
    printf("\n");
    stack = Pop(stack);
    Traverse(stack);
    printf("\n");
    stack = Pop(stack);
    Traverse(stack);
    printf("\n");
    Pop(stack);
    Traverse(stack);
    
    getchar();
    return 0 ;
}
