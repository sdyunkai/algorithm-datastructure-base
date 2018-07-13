/**
 * 自杀游戏-俄罗斯轮盘赌
 * 
 * 左轮手枪里有两个弹孔，随机放入一颗子弹，两人轮流干自己，直到一个人投降或者挂掉，残忍
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int buckets[6] ;
    srand(time(NULL));
    int idx = rand()%6;
    for(int i = 0 ; i < 6; i++) {
        buckets[i] = 0;    
    }
    buckets[idx] = 1;
    printf("%d\n", idx);
    char player[2] = {'A', 'B'};
    for(int i = 0 ; i < 6; i++) {
        printf("turn %c: %d ", player[i%2], buckets[i]);
        if (buckets[i] == 1) {
            printf("die\n");
            break;
        } else {
            printf("good luck\n");
        }

    }
    getchar();
    return 0;
}

