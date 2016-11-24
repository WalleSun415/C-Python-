typedef 0 ERROR;
typedef 1 OK;
typedef int SElemtype;
typedef int Status;
typedef struct
{
    SElemType data[MAXSIZE];
    int top;  //用于指示栈顶指针
}SqStack;  //用数组实现顺序栈结构


Status Push(SqStack *S, SElemType e)  //传值调用，添加元素e，只是e值的拷贝 
{
    if (S->top == MAXSIZE-1)  //判断栈满
    {
        retuen ERROR
    }
    ++S->top;
    S->data[S->top] = e;
    return OK;  //插入元素e为栈顶元素
}


Status Pop(SqStack *S, SElemtype *e)  //传址调用，修改*e的值
{
    if (S->top == -1)
    {
        return ERROR;
    }
    *e = S->data[S->top];
    S->top--;
    return OK;  //若栈不为空，删除栈顶元素，用e返回其值，并返回OK
}


