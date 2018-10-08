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

typedef enum {Link, Thread} PointerTag; /* Link==0表示指向左右孩子指针, */
										/* Thread==1表示指向前驱或后继的线索 */
typedef struct BiThrNode
{
    TElemType data;     //结点数据
    struct BiThrNode *lchild, *rchild;  //左右孩子指针
    PointerTag LTag;    //左右标志
    PointerTag RTag;
}BiThrNode, *BiThrTree;

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

Status CreateBiThrTree(BiThrTree *T)
{
    TElemType charactor;
    deepth++;
    //scanf("%c", &charactor);
    charactor = Tree_Str[index++];
    if(charactor=='#')
        *T = NULL;
    else
    {
        *T = (BiThrTree)malloc(sizeof(BiThrNode));
        if(!*T)
        {   printf("malloc fail\n");return;}
        (*T)->data = charactor;
        CreateBiThrTree(&(*T)->lchild);     //递归构造左子树
        if((*T)->lchild)    //若存在左子树
            (*T)->LTag = Link;
        CreateBiThrTree(&(*T)->rchild);     //递归构造右子树
        if((*T)->rchild)    //若存在右子树
            (*T)->RTag = Link;
    }deepth--;
    if(deepth == 0)
        printf("Create BiThrTree Done\n");
    return OK;
}

BiThrTree pre; /* 全局变量,始终指向刚刚访问过的结点 */
/* 中序遍历进行中序线索化 */
void InThreading(BiThrTree p)
{
    if(p)
    {
        InThreading(p->lchild);     //左孩子递归
        if(!p->lchild)  //若左孩子为空
        {
            p->LTag = Thread;
            p->lchild = pre;    //令pre等于当前左孩子的结点
        }
        if(!pre->rchild)  //若右孩子为空
        {
            pre->RTag = Thread;
            pre->rchild = p;    //pre的右孩子链到p的结点
        }
        pre = p;                //令p = pre 执行下一次递归
        InThreading(p->rchild);     //右孩子递归
    }
}

int main()
{
    BiThrTree T;
    AssignStr(Tree_Str, "ABDH#K###E##CFI###G#J##");
    CreateBiThrTree(&T);
    //printf("Hello world!\n");
    return 0;
}
