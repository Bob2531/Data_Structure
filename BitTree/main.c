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

typedef int Status;

//��������ṹ����
typedef struct BiTNode
{
    int data;                       //������
    struct BiTree *lchild, *rchild; //�������ҽ��
}BiTNode, *BiTree;

/* �ݹ���Ҷ���������T���Ƿ����key, */
/* ָ��fָ��T��˫�ף����ʼ����ֵΪNULL */
/* �����ҳɹ�����ָ��pָ�������Ԫ�ؽ�㣬������TRUE */
/* ����ָ��pָ�����·���Ϸ��ʵ����һ����㲢����FALSE */
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{   //��ʼʹ��Ϊ(T, key, NULL, p)
    if(!T)  //���Ҳ��ɹ�
    {
        *p = f;
        return FALSE;
    }
    else if(key==T->data)   //���ҵ�ֵ
    {
        *p = T;
        return TRUE;
    }
    else if(key < T->data)  //������������������
        return SearchBST(T->lchild, key, T, p);
    else                    //��������������
        return SearchBST(T->rchild, key, T, p);
}

/*  ������������T�в����ڹؼ��ֵ���key������Ԫ��ʱ�� */
/*  ����key������TRUE�����򷵻�FALSE */
Status InsertBST(BiTree *T, int key)
{
    BiTree p, s;
    if(!SearchBST(*T, key, NULL, &p))   //û�в��ҵ�ֵ
    {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;
        if(!p)      //��pΪ�ս��
            *T = s;     //����sΪ�µĸ��ڵ�
        else if(key < p->data)  //��keyֵС�ڵ�ǰֵ, ��ֵΪ����
            p->lchild = s;
        else
            p->rchild = s;
        return TRUE;
    }
    else
        return FALSE;   //�������йؼ���� ��������
}

/*  ������������T�в����ڹؼ��ֵ���key������Ԫ��ʱ�� */
/*  ����key������TRUE�����򷵻�FALSE */
Status DeleteBST(BiTree *T, int key)
{
    if(!*T)     //��Ϊ��
        return FALSE;
    else
    {
        if(key == (*T)->data)   //�ҵ���ǰΪkey�������
            return Delete(T);
        else if(key<(*T)->data) //������������ȥɾ��
            return DeleteBST(&(*T)->lchild, key);
        else
            return DeleteBST(&(*T)->rchild, key);
    }
}

/*  �Ӷ�����������ɾ���ڵ�p ����������������������    */
Status Delete(BiTree *p)
{
    BiTree q, s;
    if((*p)->rchild==NULL)  //���Һ���Ϊ��
    {
        q = *p; *p=(*p)->lchild; free(q);
    }
    else if((*p)->lchild==NULL) //������Ϊ��
    {
        q = *p; *p=(*p)->rchild; free(q);
    }
    else    //������������Ϊ��
    {
        q = *p; s=(*p)->lchild;
        while(s->lchild)    //�������ҵ���ͷ
        {
            q=s; s=s->rchild;
        }
        (*p)->data = s->data;    //sָ��ɾ������ֱ��ǰ��
        if(q!=*p)
            q->rchild = s->lchild;  //��������q��������
        else
            q->lchild = s->lchild;  //��������q��������
        free(s);
    }
    return TRUE;
}

//�������������
void PreOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    printf("%d ", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

//�������������
void InOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%d ", T->data);
    InOrderTraverse(T->rchild);
}

//�������������
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
