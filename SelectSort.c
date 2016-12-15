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
    for (i = 1; i < L->length; i++)
    {
        min = i;
        for (j = i+1; j <= L->length; j++)
        {
            if (L->r[min] > L->r[j])
                min = j;
        }
        if (min !=i)
            swap(L, min, i);
    }
}
