typedef int TElemType;
typedef 0 ERROOR;
typedef 1 OK;


//二叉树的二叉链表结点结构
typedef struct BiTNode  //二叉树结点结构
{
    TElemType data;
    struct BiTNode *lchild, *rchild;  //左右孩子指针
}BiTNode, *BiTree;
