#include <stdlib.h>


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
        return SearchBST(T->lchild, key, T, p);
}


//二叉查找树T中不存在关键字key时，插入key并返回TRUE，否则返回FALSE
Status InsertBST (BiTree *T, int key)
{
    BiTree s, p;
    if (!SearchBST(*T, key, NULL, &p))  //查找不成功
    {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;
        if (!p)  //二叉查找树T为空树
            *T = s;
        else if (key < p->data)
            p->lchild = s;
        else
            p->rchild = s;
        return TRUE;
    }
    else
        return FALSE;
}


//二叉查找树T中存在关键字key时，删除该关键字的结点，并返回TRUE，否则返回FALSE
Status DeleteBST (BiTree *T, int key)
{
    if (!*T)  //T为空树
        return FALSE;
    else
    {
        if ((*T)->data == key)
            return Delete(T);
        else if((*T)->data > key)
            return DeleteBST(&((*T)->lchild), key);
        else if ((*T)->data < key)
            return DeleteBST(&((*T)->rchild), key);
    }
}


//二叉查找树中删除具体结点p，并重建它的左右子树
Status Delete (BiTree *p)
{
    BiTree q, s;
    if ((*p)->lchild == NULL)  //右子树为空时，只需重接左子树
    {
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }
    else if ((*p)->rchild == NULL)  //左子树为空时，只需重接右子树
    {
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }
    else  //左右子树均不为空
    {
        q = *p;
        s = (*p)->lchild;
        while (s->rchild)  //查找待删除结点左子树的右侧尽头结点，此为p的前驱结点，同理，亦可查找后继结点
        {
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data;  //将直接前驱结点替换待删除结点
        if (q!=*p)
            q->rchild = s->lchild;
        else
            q->lchild = s->lchild;
        free(s);
    }
    return TRUE;
}
