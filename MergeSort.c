#include <stdio.h>
#include <stdlib.h>
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


//将SR数组中分组过的元素，进行一次归并排序到TR数组中
void Merge (int SR[], int TR[], int i, int m, int n)
{
    int j, k, l;
    for (j=m+1,k=i; i<=m && j<=n; k++)
    {
        if (SR[i] <= SR[j])
            TR[k] = SR[i++];
        else
            TR[k] = SR[j++];
    }
    if (i <= m)  //若遍历完SR[m+1..n]后，归并剩余元素SR[i..m]
    {
        for (l = 0; l <= m-i; l++)
        {
            TR[k+l] = SR[i+l];
        }
    }
    if (j <= n)  //若遍历完SR[1..m]后，归并剩余元素SR[j..n]
    {
        for (l = 0; l <= n-j; l++)
        {
            TR[k+l] = SR[j+l];
        }
    }
}


//将SR[]中相邻长度为s的子序列两两归并到TR[]
void MergePass (int SR[], int TR[], int s, int n)
{
    int i = 1;
    int j;
    while (i < n-2*s+1)  //剩余最后两个元素
    {
        Merge(SR, TR, i, i+s-1, i+2*s-1);
        i+=2*s;
    }
    if (i < n-s+1)
        Merge(SR, TR, i, i+s-1, n);
    else
        for (j = i; j <= n; j++)
            TR[j] = SR[j];
}


//归并排序的非递归实现
void MergeSort (SqList *L)
{
    int *TR = (int *)malloc(L->length * sizeof(int));  //申请空间用于临时数组
    int k = 1;
    while (k < L->length)
    {
        MergePass(L->r, TR, k, L->length);
        k*=2;  //子序列长度加倍
        MergePass(TR, L->r, k, L->length);
        k*=2;  //子序列长度加倍
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
    MergeSort(&L);
    print(L);
    return 0;
}
