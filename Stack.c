#include <stdlib.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 20
typedef int Status;
typedef int SElemType;
typedef struct
{
    SElemType data[MAXSIZE];
    int top;  //用于指示栈顶指针
}SqStack;  //用数组实现顺序栈结构


Status Push(SqStack *S, SElemType e)  //传值调用，添加元素e，只是e值的拷贝 
{
    if (S->top == MAXSIZE-1)  //判断栈满
    {
        return ERROR;
    }
    ++S->top;
    S->data[S->top] = e;
    return OK;  //插入元素e为栈顶元素
}


Status Pop(SqStack *S, SElemType *e)  //传址调用，修改*e的值
{
    if (S->top == -1)
    {
        return ERROR;
    }
    *e = S->data[S->top];
    S->top--;
    return OK;  //若栈不为空，删除栈顶元素，用e返回其值，并返回OK
}


/*该种数据结构，通常是当两个栈的空间需求有相反关系时，即一个栈
  增长另一个栈在缩短的情况，并且两个栈必须具有相同的数据类型*/
typedef struct
{
    SElemType data[MAXSIZE];
    int top1;
    int top2;
}SqDoubleStack;  //两栈共享数组空间


Status Push (SqDoubleStack *S, SElemType e, int stackNumber)  //插入e为新的栈顶元素

{
    if (S->top1 + 1 == S->top2)
        return ERROR;
    if (stackNumber == 1)
    {
        S->data[++S->top1] = e;
        return OK;
    }
    else if (stackNumber == 2)
    {
        S->data[--S->top2] = e;
        return OK;
    }
    else
        return ERROR;  
}


Status Pop(SqDoubleStack *S, SElemType *e, int stackNumber)  //删除S的栈顶元素，用e返回其值
{
    if (stackNumber == 1)
    {
        if(S->top1 == -1)  //判断栈1是否是空栈
            return ERROR;
        *e = S->data[S->top1--];  //将栈1的栈顶元素出栈
        return OK;
    }
    else if (stackNumber == 2)
    {
        if (S->top2 == MAXSIZE)  //判断栈2是否是空栈
            return ERROR;
        *e = S->data[S->top2++];  //将栈2的栈顶元素出栈
        return OK;
    }
    else 
        return ERROR;

}


typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;  //链式栈的节点结构

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
}LinkStack;  //链式栈结构


Status Push (LinkStack *S, SElemType e)  //插入元素e作为新的栈顶元素
{
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));  //申请StackNode空间作为新的插入结点
    s->data = e;
    s->next = S->top;
    S->top = s;
    S->count++;
    return OK;
}


Status Pop (LinkStack *S,SElemType *e)  //删除S的栈顶元素，用e返回其值
{
    LinkStackPtr p = NULL;
    if (S->top == NULL)  //出栈操作首先需判断栈是否为空
        return ERROR;
    *e = S->top->data;
    p = S->top;
    S->top = S->top->next;
    free(p);
    S->count--;
    return OK;
}

/*顺序栈与链栈的插入删除操作时间复杂度均为O(1),
  如果栈的使用过程中元素变化不可预料时，最好使用链栈；
  如果它的变化在可控范围内，使用顺序栈则更好。*/
