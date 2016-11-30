typedef int TElemType;
typedef 0 ERROOR;
typedef 1 OK;


//二叉树的二叉链表结点结构
typedef struct BiTNode  //二叉树结点结构
{
    TElemType data;
    struct BiTNode *lchild, *rchild;  //左右孩子指针
}BiTNode, *BiTree;


void PreOrderTraverse (BiTree T)  //二叉树前序遍历递归算法
{
    if (T==NULL)
        return;
    printf("%c", T->data);  //打印结点数据，或其他对结点的操作，一般二叉树结点均用于保存数据
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}


void InOrderTraverse (BiTree T)  //二叉树中序遍历递归算法
{
    if (T==NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%c", T->data);
    InOrderTraverse(T->rchild);
}


void PostOrderTraverse (BiTree T)  //二叉树后序遍历递归算法
{
    if (T==NULL)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c", T->data);
}
