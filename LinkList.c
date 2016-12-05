#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;  //函数类型，假定为整型
typedef int ElemType;  //数据类型，假定为整型


/*对于插入或删除数据越频繁的操作，单链表的效率优势就越明显；当线性表中元素较大或位置时，宜采用单链表结构
  若线性表需要频繁的执行查找操作，很少进行插入和删除操作，并且预知线性表的大致长度，宜采用顺序存储结构*/
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;  //线性表的单链表存储结构
typedef struct Node *LinkList;  


Status ListInsert (LinkList *L, int i, ElemType e)
{
    int j;
    LinkList p, s;
    p = *L;
    j=1;
    while(p && j<i)  //遍历寻找第i-1个结点
    {
        p = p->next;
        j++;
    }
    if(!p || j>i)
        return ERROR;

    s = (LinkList)malloc(sizeof(Node));

    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;  //单链表第i个结点的插入
}


Status ListDelete (LinkList *L, int i, ElemType *e)
{
    int j;
    LinkList p, q;
    p = *L;
    j = 1;
    while (p && j<i)  //遍历寻找第i-1个结点
    {
        p = p->next;
        j++;
    }
    
    if (! (p->next) || j>i)
        return ERROR;

    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;  //单链表删除第i个结点,并用e返回其值
}


/*用数组描述的链表叫做静态链表，静态链表是为了给没有指针的高级语言设计的一种实现链表的方法*/

/*双向链表为循环链表的高级形态，由于具有良好的对称性，是的对某个结点的前后结点操作更加方便，
  可以有效的提高算法时间性能，即用空间换时间。*/
