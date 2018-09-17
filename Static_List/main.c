#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FAUSE 0
#define MAXSIZE 100

typedef int ElemType;   //�Զ�����������
typedef int Status;		//����״̬����Ϊ����

typedef struct Node
{
    ElemType data;      //����������
    int cur             //�α�(Cursor) Ϊ0ʱ��ʾ��ָ��
} Component, StaticLinkList[MAXSIZE]

//��ʼ����̬����
Status InitList(StaticLinkList space)
{
    int i;      //iΪ�±�
    for (i=0; i<MAXSIZE-1; i++)
        space[i].cur = i+1;     //�Դ˸��±�
    space[MAXSIZE-1].cur = 0;   //�������һ��Ԫ�ص��α�Ϊ0
    return OK;
}

//ʵ����malloc��������ռ�
int Malloc_SLL(StaticLinkList space)
{
    int i = space[i].cur        //��ǰ�����һ��Ԫ�ص�curֵ ���ص�һ��Ԫ�ر��ÿ����±�
    if(space[i])
        space[0].cur = space[i].cur;    //����һ�������������ø�ֵ����һ��Ԫ�ص�cur
    return i;       //�����ҵ��ı����±��ֵ
}

