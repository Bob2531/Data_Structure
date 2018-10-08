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

typedef enum {Link, Thread} PointerTag; /* Link==0��ʾָ�����Һ���ָ��, */
										/* Thread==1��ʾָ��ǰ�����̵����� */
typedef struct BiThrNode
{
    TElemType data;     //�������
    struct BiThrNode *lchild, *rchild;  //���Һ���ָ��
    PointerTag LTag;    //���ұ�־
    PointerTag RTag;
}BiThrNode, *BiThrTree;

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
        CreateBiThrTree(&(*T)->lchild);     //�ݹ鹹��������
        if((*T)->lchild)    //������������
            (*T)->LTag = Link;
        CreateBiThrTree(&(*T)->rchild);     //�ݹ鹹��������
        if((*T)->rchild)    //������������
            (*T)->RTag = Link;
    }deepth--;
    if(deepth == 0)
        printf("Create BiThrTree Done\n");
    return OK;
}

BiThrTree pre; /* ȫ�ֱ���,ʼ��ָ��ոշ��ʹ��Ľ�� */
/* ��������������������� */
void InThreading(BiThrTree p)
{
    if(p)
    {
        InThreading(p->lchild);     //���ӵݹ�
        if(!p->lchild)  //������Ϊ��
        {
            p->LTag = Thread;
            p->lchild = pre;    //��pre���ڵ�ǰ���ӵĽ��
        }
        if(!pre->rchild)  //���Һ���Ϊ��
        {
            pre->RTag = Thread;
            pre->rchild = p;    //pre���Һ�������p�Ľ��
        }
        pre = p;                //��p = pre ִ����һ�εݹ�
        InThreading(p->rchild);     //�Һ��ӵݹ�
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
