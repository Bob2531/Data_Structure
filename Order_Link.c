#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAXSIZE 10      //�洢�ռ������
#define OK 1
#define ERROR 0
#define TRUE 1
#define FAUSE 0
typedef int Status;
typedef int ElemType;

typedef struct //����˳���ṹ��
{
    ElemType data[MAXSIZE]; //˳���Ԫ��
    int length;             //˳�����
}SqList;

/*
typedef struct
{
    ElemType *data;          //˳���Ԫ��
    int length;             //˳�����
}SeqList;
*/

//��ʼ��˳���
Status InitList(SqList *L)
{
    L->length = 0;   //��˳���ĳ��ȸ�ֵΪ0
    return OK;
}

//ȡ˳����е�i��Ԫ�ص�ֵ
Status GetLlem(SqList L,int i, ElemType *e)
{
    //�����ж�:
    //�����Ϊ0 || λ��С��1 || λ�ô��ڱ�
    //���ȡʧ��
    if (L.length<0 || i<1 || i>L.length)
        return ERROR;
    //��ȡ��i��λ�õ�ֵ,��Ӧ�����о���i-1��λ��
    *e = L.data[i-1];
    return OK;
}

//�������
Status ListInsert(SqList *L, int i, ElemType e)
{
    int position;   //�������λ��
//  ����ʱ�Ƚ����ж�
//  ��˳�����==MAXSIZE ��ʾ���Ա����� ���ܲ���
    if(L->length==MAXSIZE)
    {
        printf("List full, insert fail\n");
        return ERROR;
    }
//  ������λ��   i<0 λ�÷Ƿ�
//               i>length+1 λ��Խ��    ���ܲ���
    if(i<1 || i>L->length+1)
    {
        printf("Illegal position i\n");
        return ERROR;
    }
//  ��i<length ��ʾ����Ԫ�ز��ڱ�β
    if(i<L->length)
    {
        //˳λ����
        for(position=L->length-1; position>i-1; position--)
            L->data[position+1] = L->data[position];  //���ݺ���
    }
    L->data[position] = e;   //���ݴ��������i-1��λ��
    L->length++;            //˳����ȼ�һ
    printf("Data %d has been Inserted\n", e);
    return OK;
}

int main()
{
    SqList L;   //��ʼ��˳���
    InitList(&L);   //˳����ȸ�ֵΪ0

    int i;
    for(i=1; i<10; i++)
    {
        ListInsert(&L, i, i);
    }
    return 0;
}
