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


//返回一个关键字，将其放在一个位置，使得左边的值都比它小，右边的值都比它大
int Partition (SqList *L, int low, int high)
{
    int pivotkey;
    pivotkey = L->r[low];  //将首元素作为枢轴纪录
    while (low < high)  //从表的两端交替向中间扫描
    {
        while (low < high && L->r[high] >= pivotkey)
            high--;
        swap(L, low, high);  //将高位比枢轴纪录小的值交换到低位
        while (low < high && L->r[low] <= pivotkey)
            low++;
        swap(L, low, high);  //将低位比枢轴纪录大的值交换到高位
    }
    return low;  //当前坐标low和high相等，返回任意一个
}


void QSort (SqList *L, int low, int high)
{
    int pivot;  //定义枢轴纪录的下标
    if (low < high)
    {
        pivot = Partition(L, low, high);  
        QSort(L, low, pivot-1);  //根据枢轴下标将低子表递归进行快速排序
        QSort(L, pivot+1, high);  //根据枢轴下标将高子表递归排序快速排序
    }
}


//快速排序的递归实现，保证与其它排序的参数定义一致，封装一个函数用于递归调用
void QuickSort (SqList *L)
{
    QSort(L, 1, L->length);
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
    QuickSort(&L);
    print(L);
    return 0;
}
