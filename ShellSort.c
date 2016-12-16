#include <stdio.h>
#define MAXSIZE 100 

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


void  ShellSort(SqList *L)
{
    int i, j;
    int increment = L->length;
    do
    {
        increment = increment/3+1;  //设置增量序列
        for (i = increment+1; i < L->length; i++)
        {
            if (L->r[i] < L->r[i-increment])  //将较小值插入到有序增量子表中
            {
                L->r[0] = L->r[i];
                for (j = i-increment; j>0 && L->r[0]<L->r[j]; j-=increment)  //交换数据时，若有重复坐标，需向前重新比较
                    L->r[j+increment] = L->r[j];
                L->r[j+increment] = L->r[0];
            }
        }
    }
    while (increment > 1);  //当增量序列值为1时，停止停止循环
}


void print(SqList L)
{
    int i;
    for (i = 0; i < L.length; i++)
        printf("%d", L.r[i]);
    printf("\n%d\n", L.length);
}


int main()
{
    int i;
    SqList L;
    int m[10]={0, 9, 1, 5, 8, 3, 7, 4, 6, 2};
    for (i = 0; i < 10; i++)
        L.r[i] = m[i];
    L.length = 10;
    print(L);
    ShellSort(&L);
    print(L);
    return 0;
}
