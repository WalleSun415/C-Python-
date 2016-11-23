#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;  //函数类型，假定为整型
typedef int ElemType;  //数据类型，假定为整型


typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;  //线性表的单链表存储结构
typedef struct Node *LinkList;  



