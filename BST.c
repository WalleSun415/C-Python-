/*二叉查找树（Binary Sort Tree，BST）即可以使得插入删除效率不错，又可以比较高效的实现查找*/
#define FALSE 0
#define TRUE 1

typedef int Status;

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

/*递归查找二叉排序树T中是否存在key，f表示T的双亲，当T为根结点时，f为NULL；
  若查找成功，p指向该结点，失败则p指向查找的最后结点*/
Status SearchBST (BiTree T, int key, BiTree f, BiTree *p)  
{
    if (!T)  //判断树是否为空或是否到达叶子结点
    {
        *p = f;
        return FALSE;
    }
    else if (T->data == key)
    {
        *p = T;
        return TRUE;
    }
    else if (T->data > key)
        return SearchBST(T->rchild, key, T, p);
    else if (T->data < key)
        return SearchBST(T->lchild, key, T, p)
}



