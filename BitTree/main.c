#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;

//二叉链表结构定义
typedef struct BiTNode
{
    int data;                       //数据域
    struct BiTree *lchild, *rchild; //定义左右结点
}BiTNode, *BiTree;

/* 递归查找二叉排序树T中是否存在key, */
/* 指针f指向T的双亲，其初始调用值为NULL */
/* 若查找成功，则指针p指向该数据元素结点，并返回TRUE */
/* 否则指针p指向查找路径上访问的最后一个结点并返回FALSE */
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{   //初始使用为(T, key, NULL, p)
    if(!T)  //查找不成功
    {
        *p = f;
        return FALSE;
    }
    else if(key==T->data)   //查找到值
    {
        *p = T;
        return TRUE;
    }
    else if(key < T->data)  //向结点左子树继续查找
        return SearchBST(T->lchild, key, T, p);
    else                    //右子树继续查找
        return SearchBST(T->rchild, key, T, p);
}

/*  当二叉排序树T中不存在关键字等于key的数据元素时， */
/*  插入key并返回TRUE，否则返回FALSE */
Status InsertBST(BiTree *T, int key)
{
    BiTree p, s;
    if(!SearchBST(*T, key, NULL, &p))   //没有查找到值
    {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;
        if(!p)      //若p为空结点
            *T = s;     //插入s为新的根节点
        else if(key < p->data)  //若key值小于当前值, 则赋值为左孩子
            p->lchild = s;
        else
            p->rchild = s;
        return TRUE;
    }
    else
        return FALSE;   //树中已有关键结点 不做插入
}

/*  当二叉排序树T中不存在关键字等于key的数据元素时， */
/*  插入key并返回TRUE，否则返回FALSE */
Status DeleteBST(BiTree *T, int key)
{
    if(!*T)     //树为空
        return FALSE;
    else
    {
        if(key == (*T)->data)   //找到当前为key的树结点
            return Delete(T);
        else if(key<(*T)->data) //从它左孩子里面去删除
            return DeleteBST(&(*T)->lchild, key);
        else
            return DeleteBST(&(*T)->rchild, key);
    }
}

/*  从二叉排序树中删除节点p 并重新连接它的左右子树    */
Status Delete(BiTree *p)
{
    BiTree q, s;
    if((*p)->rchild==NULL)  //若右孩子为空
    {
        q = *p; *p=(*p)->lchild; free(q);
    }
    else if((*p)->lchild==NULL) //若左孩子为空
    {
        q = *p; *p=(*p)->rchild; free(q);
    }
    else    //左右子树都不为空
    {
        q = *p; s=(*p)->lchild;
        while(s->lchild)    //右子树找到尽头
        {
            q=s; s=s->rchild;
        }
        (*p)->data = s->data;    //s指向被删除结点的直接前驱
        if(q!=*p)
            q->rchild = s->lchild;  //重新连接q的右子树
        else
            q->lchild = s->lchild;  //重新连接q的左子树
        free(s);
    }
    return TRUE;
}

//先序遍历二叉树
void PreOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    printf("%d ", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

//中序遍历二叉树
void InOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%d ", T->data);
    InOrderTraverse(T->rchild);
}

//后序遍历二叉树
void PostOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%d ", T->data);
}

int main()
{
    int i;
    int number_arr[17] = {62, 88, 58, 47, 35, 73, 51, 99,
                          37, 93, 29, 37, 36, 49, 48, 50, 56};
    BiTree T=NULL;
    for(i=0; i<17; i++)
        InsertBST(&T, number_arr[i]);

    InOrderTraverse(T);
    return 0;
}
