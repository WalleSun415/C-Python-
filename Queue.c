typedef 0 ERROR;
typedef 1 OK;
typedef int Status;
typedef int QElemaType;


typedef struct QNode
{
    QElemaType data;
    struct QNode *next;
}QNode, *QueuePtr;


typedef struct
{
    QueuePtr front, rear;
}LinkQueue;  //队列的链式存储结构


Status EnQueue (LinkQueue *Q, QElemaType e)  //链式队列的入队操作
{
    QueuePtr q = (QueuePtr)malloc(sizeof(QNode));
    q->data = e;
    q->next = NULL;
    Q->rear->next = q;  //q为指向QNode结构体的指针，next为指向QNode结构体的指针
    Q->rear = q;
    return OK;
}


Status DeQueue (LinkQueue *Q, QElemaType *e)  //链式队列出队，用e返回出队元素的值
{
    QueuePtr q;
    if (Q->front == Q->rear)
        return ERROR;
    q = Q->front->next;  //队列的头指针指向头结点，出队为头结点的下一个结点出队
    *e = q->data;
    Q->front->next = q->next;   
    if (q == Q->rear)  //若出队的为尾指针指向的结点，则出队后，尾指针将指向头结点,即头指针、尾指针均指向头结点，队列为空
        Q->rear = Q->front;
    free(q);
    return OK;
}
