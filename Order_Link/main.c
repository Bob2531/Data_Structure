#include<stdio.h>
#define MAXSIZE 20 //�������Ա����󳤶�
#define InitSize 100 //���ȵĳ�ʼ����
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;

typedef struct //����˳���ṹ��
{
    ElemType data[MAXSIZE]; //˳���Ԫ��
    int length;             //˳�����
}SqList;

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
    L->data[i-1] = e;   //���ݴ��������i-1��λ��
    L->length++;            //˳����ȼ�һ
    printf("Data %d has been Inserted\n", e);
    return OK;
}

//˳���ɾ������
Status ListDelete(SqList *L, int i, ElemType *e)
{
    int position;
    //�ж�˳����Ƿ�Ϊ��
    if(L->length == 0)
    {
        printf("List is empty, delete fail\n");
        return ERROR;
    }
    //�ж�i��λ���Ƿ�Ϸ�
        //��i<0 || i>length+1 �Ƿ�
    if(i<1 || i>L->length)
    {
        printf("Illegal position i\n");
        return ERROR;
    }
    //����λ��i������
    *e = L->data[i-1];

    if(i<L->length)
    {
        for(position=i; position<L->length; position++)
            L->data[position-1] = L->data[position];//˳��ǰ�ƶ�
//        for(position=L->length; position<i; position--)
//            L->data[position-2] = L->data[position-1];//˳��ǰ�ƶ�
    }
    L->length--;
    return OK;
}

//˳������ʾ
void ListShow(SqList L)
{
    int position;
    printf("\n---------Display List---------\n");
    for(position=0; position<L.length; position++)
        printf("%d  ", L.data[position]);
    printf("\n---------Display Done---------\n");
}

//�õ�λ��i��Ԫ��
Status GetElem(SqList L, int i)
{
    //�ж�i��λ���Ƿ�Ϸ�
    if(i<1 || i>L.length)
    {
        printf("Illegal position i\n");
        return ERROR;
    }
    else
    {
        printf("\n---------GetElem---------");
        printf("\nGet Data[%d] is %d\n", i, L.data[i-1]);
        printf("---------GetElem---------\n");
    }
    return OK;
}

//��λ˳����е�Ԫ��
Status LocateElem(SqList L, int e)
{
    printf("\n---------LocatElem---------\n");
    int position;
    for(position=0; position<L.length;position++)
    {
        if(e == L.data[position])
        {
            printf("data[%d]'s location is %d\n", L.data[position], position);
            printf("---------LocatElem---------\n");
            return OK;
        }
    }
    printf("Missing Data\n");
    printf("---------LocatElem---------\n");
    return ERROR;
}

//˳�����
ElemType ListLength(SqList L)
{
    return L.length;
}

int main()
{
    SqList L;   //��ʼ��˳���
    InitList(&L);   //˳����ȸ�ֵΪ0
    int length;

    int i;
    int del_num; //���屻ɾ������
    for(i=1; i<13; i++)
    {
        ListInsert(&L, i, i);
    }
    for(i=8; i>4; i--)
    {
        ListDelete(&L, i, &del_num);
        printf("\ndata %d has been deleted", del_num);
    }
    GetElem(L, 5);
    LocateElem(L, 10);
    ListShow(L);

    length = ListLength(L);
    printf("\nList length is %d\n", length);
    return 0;
}
