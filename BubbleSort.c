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


void BubbleSort (SqList *L)  //该排序为升序排序
{
    int i, j;
    for (i = 1; i < L->length; i++)
        for (j = L->length-1; j >= i; j--)  //注意，j从后向前循环
        {
            if (L->r[j] > L->r[j+1])
                swap(L, j, j+1);
        }
}

/*该算法优点在于每次循环除了将最小数值置于首位外，还将较小值向上提升*/


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
    BubbleSort(&L);
    print(L);
    return 0;
}
