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


//本函数调整L->r[s]的关键字，使L->r[s..m]成为一个最大堆
void HeapAdjust (SqList *L, int s, int m)
{
    int i, temp;
    temp = L->r[s];
    for (i = 2*s; i <= m; i*=2)  //s的左孩子一定时2s，右孩子一定是2s+1,他们的孩子也一定是2倍增加
    {
        if (i < m && L->r[i] < L->r[i+1])
            ++i;  //i用于记录关键字中较大记录的下标
        if (temp >= L->r[i])
            break;
        L->r[s] = L->r[i];
        s = i;  //定位与关键字调换的下标
    }
    L->r[s] = temp;
}

/*堆排序：首先构造一个最大堆，将堆顶元素与末尾元素交换，将剩余n-1个序列重新构造最大堆，循环进行得到有序序列*/
void HeapSort (SqList *L)
{
    int i;
    for (i = L->length/2; i > 0; i--)  //初始化构造最大堆，构造length/2表示这是最后一个有孩子结点的父结点
        HeapAdjust(L, i, L->length);

    for (i = L->length; i > 1; i--)  //堆排序
    {
        swap(L, 1, i);
        HeapAdjust(L, 1, i-1);
    }
}


void print(SqList L)
{
    int i;
    for (i = 0; i < 10; i++)
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
    HeapSort(&L);
    print(L);
    return 0;
}
