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

#define MAXSIZE 100 /* �洢�ռ��ʼ������ */

typedef char TElemType;  //�Զ������
typedef char String[30]; //���Ĵ洢�ռ�
typedef int Status;
int index=1, deepth=0;   //�ݹ����
String Tree_Str;

typedef struct BiTNode
{
    TElemType data;                     //����������
    struct BiTNode *lchild, *rchild;    //���������� ������
}BiTNode, *BiTree;

//����ն�����
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
        T[0] = strlen(str);//�洢���ĳ���
        for(i=1; i<= str[0]; i++)
            T[i] = *(str+i-1);
        printf("Initialize Tree Done\n");
        return OK;
    }
}

//����������
Status CreateBiTree(BiTree *T)
{
    //T = (BiTree)malloc(sizeof(BiTNode));    //����һ����СΪBiTNode������ΪBiTree �ռ��T;
    //TElemType charactor[10];
    //scanf("%c", &charactor);
    deepth++;
    char charactor;
    charactor = Tree_Str[index++];
    if(charactor == '#')        //������Ϊ '#' ���ʾ������� �˽ڵ㸳��ָ��
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if(!*T)     //���T�ڵ�Ϊ�� ��ʾ�����ڴ�ʧ��
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
//�������������
void PreOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    printf("%c ", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

//�������������
void InOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%c ", T->data);
    InOrderTraverse(T->rchild);
}

//�������������
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
