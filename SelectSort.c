#include <stdio.h>
#define MAXSIZE 10

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


void SelectSort (SqList *L)
{
    int i, j, min;
    for (i = 1; i < L->length; i++)  //数组中的最后元素不需排序，剩下的即为最大的
    {
        min = i;
        for (j = i+1; j <= L->length; j++)
        {
            if (L->r[min] > L->r[j])
                min = j;
        }
        if (min != i)
            swap(L, min, i);
    }
}


void print(SqList L)
{
    int i;
    for (i = 1; i < 10; i++)
        printf("%d,", L.r[i]);
    printf("\n%d\n", L.length);
}


int main()
{
    int i;
    SqList L;
    int m[10]={0, 50, 10, 90, 30, 70, 40, 80, 60, 20};
    for (i = 0; i < 10; i++)
        L.r[i] = m[i];
    L.length = 9;
    print(L);
    SelectSort(&L);
    print(L);
    return 0;
}
