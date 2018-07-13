#include <stdio.h>
#include <stdlib.h>
#define Stack_SIZE 3

typedef struct Stack {
    int top ;
    int list[Stack_SIZE];
} Stack ;

void Init(Stack * stack);
void Traverse(Stack * stack);
void Push(Stack * stack , int data);
void Pop(Stack * stack );

void Init(Stack * stack)
{
    stack->top = -1; 
}
void Traverse(Stack * stack) 
{
    int data ;
    int temp = stack->top ;
    while(temp != -1) {
        data = stack->list[temp];
        temp--;
        printf(",%d", data);
    }
}
void Push(Stack * stack , int data) 
{
    if (stack->top == Stack_SIZE - 1) {
        printf("overflow ");
    } else {
        stack->top++;
        stack->list[stack->top] = data;
    }
}
void Pop(Stack * stack )
{
    if (stack->top == -1) {
        printf("empty statck");
    } else {
        stack->top--;
    }
    
}
int main() 
{
    Stack * stack =(Stack *) malloc(sizeof(Stack));
    Init(stack);
    // push 
    Push(stack, 1);
    Traverse(stack);
    printf("\n");
    Push(stack, 2);
    Traverse(stack);
    printf("\n");
    Push(stack, 3);
    Traverse(stack);
    printf("\n");
    Push(stack, 4);
    Traverse(stack);
    
    // pop
    printf("\n");
    Pop(stack);
    Traverse(stack);
    printf("\n");
    Pop(stack);
    Traverse(stack);
    printf("\n");
    Pop(stack);
    Traverse(stack);
    printf("\n");
    Pop(stack);
    Traverse(stack);
    
    getchar();
    return 0 ;
}
