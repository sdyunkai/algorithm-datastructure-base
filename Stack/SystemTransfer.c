#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int top = -1;
void Push(char *a , char elem) 
{
    a[++top] = elem;
}

void Pop(char *a)
{
    if (top == -1) {
        return;
    }
    if (a[top] >= 10) {
        printf("%c", a[top]+55);
    } else {
        printf("%d", a[top]);
    }
    top--;
}

int transform_10_data(char * s, int s_system) 
{
    int len = strlen(s);
    int system_10_data = 0 ;
    for(int i = 0 ; i < len; i++) {
        int temp;
        if (s[i] >= 48 && s[i] <= 57) {
            temp = s[i] - 48;
        } else {
            temp = s[i] - 55; 
        }
        system_10_data += temp * pow(s_system, len-1-i);
    }
    printf("sytem_10_data: %d \n", system_10_data);
    
    return system_10_data;
}

int main()
{
    // input data
    // input in_system （输入进制）
    // input out_system （输出进制）
    // output tranform_data 
    char s[100];
    int in_system;
    int out_system;
    // 通过栈结构输出数据
    printf("1. typing data: ");
    scanf("%s", s);
    getchar();
    
    printf("2. typing in_system: ");
    scanf("%d", &in_system);
    getchar();

    printf("3. typing out_system: ");
    scanf("%d", &out_system);
    getchar();
    printf("\nenter any key to transform\n");
    getchar();

    int system_10_data = transform_10_data(s, in_system);
    // 核心算法 ，10进制转换任意进制, 构造栈结构
    char data[100];
    while(system_10_data / out_system) {
        Push(data, system_10_data % out_system);
        system_10_data /= out_system;
    }
    Push(data, system_10_data % out_system);
    printf("tranformed data: ");
    while(top != -1) {
        Pop(data);
    }

    printf("\nout: %s, in_system: %d, out_system: %d", s, in_system, out_system);
    getchar();
    return 0;
}