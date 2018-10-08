#include "string.h"
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

typedef char TElemType;  //自定义变量
typedef char String[30]; //树的存储空间
typedef int Status;
int index=1, deepth=0;   //递归深度
String Tree_Str;

typedef struct BiTNode
{
    TElemType data;                     //定义数据域
    struct BiTNode *lchild, *rchild;    //定义左子树 右子树
}BiTNode, *BiTree;

//构造空二叉树
Status InitBiTree(BiTree *T)
{
    *T = NULL;
    return OK;
}

Status AssignStr(String T, char *str)
{
    if(strlen(str)>MAXSIZE)
        {printf("lots of characters\n");return ERROR;}
    else
    {
        int i;
        T[0] = strlen(str);//存储树的长度
        for(i=1; i<= str[0]; i++)
            T[i] = *(str+i-1);
        printf("Initialize Tree Done\n");
        return OK;
    }
}

//创建二叉树
Status CreateBiTree(BiTree *T)
{
    //T = (BiTree)malloc(sizeof(BiTNode));    //分配一个大小为BiTNode的类型为BiTree 空间给T;
    //TElemType charactor[10];
    //scanf("%c", &charactor);
    deepth++;
    char charactor;
    charactor = Tree_Str[index++];
    if(charactor == '#')        //若输入为 '#' 则表示输入结束 此节点赋空指针
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if(!*T)     //如果T节点为空 表示分配内存失败
            {printf("malloc fail\n");return ERROR;}
        else
        {
            (*T)->data = charactor;
            //printf("please input left-child: ");
            CreateBiTree(&(*T)->lchild);
            //printf("please input right-child: ");
            CreateBiTree(&(*T)->rchild);
        }
    }
    deepth--;
    if(deepth == 0)
        printf("Create BiTree Done\n");
    //printf("%d ", deepth);
}
//
int DeepTree(BiTree T)
{
    int deep_left, deep_right;
    if(T==NULL)
        return 0;
    if(T->lchild)
        deep_left = DeepTree(T->lchild);
    else
        deep_left = 0;
    if(T->rchild)
        deep_right = DeepTree(T->rchild);
    else
        deep_right = 0;
    return deep_left>deep_right? deep_left+1: deep_right+1;
}
//先序遍历二叉树
void PreOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    printf("%c ", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

//中序遍历二叉树
void InOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%c ", T->data);
    InOrderTraverse(T->rchild);
}

//后序遍历二叉树
void PostOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c ", T->data);
}

int main()
{

    /* ABDH#K###E##CFI###G#J## */
    //PreOrderTraverse:     ABDHKECFIGJ
    //InOrderTraverse:      HKDBEAIFCGJ
    //PostOrderTraverse:    KHDEBIFJGCA
    BiTree T;
    int Tree_deep;
    AssignStr(Tree_Str, "ABDH#K###E##CFI###G#J##");
    InitBiTree(&T);
    CreateBiTree(&T);

    printf("PreOrderTraverse:  ");
    PreOrderTraverse(T);
    printf("\n");

    printf("InOrderTraverse:   ");
    InOrderTraverse(T);
    printf("\n");

    printf("PostOrderTraverse: ");
    PostOrderTraverse(T);
    printf("\n");

    printf("Deepth of the Tree is %d\n", DeepTree(T));
    return 0;
}
