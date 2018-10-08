#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 7

typedef int QElemType;  //������������
typedef int Statue;     //����״̬

typedef struct QNode    //���ṹ
{
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
    QueuePtr front, rear;   //��ͷ, ��βָ��
}LinkQueue;

Statue InitQueue(LinkQueue *Q)
{
    printf("Initializing Queue ... ");
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if(!Q->front)
    {
        printf("Initialize Queue fail\n");
        return ERROR;
    }
    Q->front->next = NULL;
    printf("Done \n");
    return OK;
}

/* ����еĳ��� */
int QueueLength(LinkQueue Q)
{
    int length=0;
    QueuePtr p = Q.front->next;
    while(p)
    {
        length++;
        p = p->next;
    }
    return length;
}

/* �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR */
Statue GetHead(LinkQueue Q,QElemType *e)
{
    if(Q.front != Q.rear)   //�����в���
    {
        *e = Q.front->next->data;
        return *e;
    }
    return ERROR;
}

/* ����Ԫ��eΪQ���µĶ�βԪ�� */
Statue EnQueue(LinkQueue *Q,QElemType e)
{
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if(!s)
    {
        printf("Allocation fail\n");
        return ERROR;
    }
    s->data = e;
    Q->rear->next = s;
    Q->rear = s;
    s->next = NULL;
    printf("%d has been EnQueued\n", s->data);
    return OK;
}

/* �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR */
Statue DeQueue(LinkQueue *Q,QElemType *e)
{
    QueuePtr p;
    if(Q->front==Q->rear)
    {
        printf("Queue is empty\n");
        return ERROR;
    }
    p = Q->front->next;
    Q->front->next = p->next;
    *e = p->data;

    if(Q->rear == p)    //front ��һ��������rear
        Q->front = Q->rear;
    free(p);
    printf("%d has been Delete\n", *e);
    return OK;
}

/* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ����� */
void QueueTraverse(LinkQueue Q)
{

    QueuePtr p;
    p = Q.front->next;
    printf("\n---------Traverse---------\n");
    while(p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n---------Traverse---------\n");
}

int main()
{
    int i,j, top;
    LinkQueue Q;
    InitQueue(&Q);
    for(i=0; i<10; i++)
        EnQueue(&Q, i%5);
    QueueTraverse(Q);
    DeQueue(&Q, &j);
    GetHead(Q, &top);
    printf("top is %d\n", top);
    DeQueue(&Q, &j);
    DeQueue(&Q, &j);
    GetHead(Q, &top);
    printf("top is %d\n", top);
    printf("length is %d\n", QueueLength(Q));
    QueueTraverse(Q);
    return 0;
}
