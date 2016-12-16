#include <stdio.h>
#define MAXSIZE 5 

typedef struct 
{
    int r[MAXSIZE+1];  //r[0]用作哨兵或是临时变量
    int length;
}SqList;

void swap (SqList *L, int i,int j)  //交换L中的数组r的下标i和j的值d
{
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}


void InsertSort (SqList *L)
{
    int i, j;
    for (i = 2; i <= L->length; i++)
    {
        if (L->r[i] < L->r[i-1])
        {
            L->r[0] = L->r[i];  //设置哨兵，充当中间变量
            for (j = i-1; L->r[0] < L->r[j]; j--)  //从较大值处开始向数组前循环
                L->r[j+1] = L->r[j];  //将j处的较大值后移
            L->r[j+1] = L->r[0];  //由于在循环中j自减，所以此句的j+1相当于上一句的j位置
        }
    }
}


void print(SqList L)
{
    int i;
    for (i = 0; i < L.length; i++)
        printf("%d", L.r[i]);
    printf("%d\n", L.length);
}


int main()
{
    int i;
    SqList L;
    int m[6]={0,5,3,4,6,2};
    for (i = 0; i < 6; i++)
        L.r[i] = m[i];
    L.length = 6;
    print(L);
    InsertSort(&L);
    print(L);
    return 0;
}
