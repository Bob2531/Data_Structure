#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 7

typedef int QElemType;  //定义数据类型
typedef int Statue;     //定义状态

typedef struct
{
    QElemType data[MAXSIZE];
    int front;  //定义头指针
    int rear;   //定义尾指针
}SqQueue;

//初始化顺序队列
Statue InitQueue(SqQueue *Q)
{
    printf("Initializing Queue ... ");
    Q->front = 0;
    Q->rear = 0;
    printf("Done \n");
    return OK;
}

//求队列长度
Statue QueueLength(SqQueue Q)
{
    return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

//入队列
Statue EnQueue(SqQueue *Q,int e)
{
    //判断队列是否满
    if((Q->rear+1)%MAXSIZE == Q->front)
    {
        printf("Queue if full, EnQueue fail\n");
        return ERROR;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1)%MAXSIZE;
    printf("EnQueue Element %d\n", e);
    return OK;
}

//出队列
Statue DeQueue(SqQueue *Q,int *e)
{
    //判断队列是否为空
    if(Q->front==Q->rear)
    {
        printf("Queue is empty, Delete fail\n");
        return ERROR;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front+1)%MAXSIZE;
    printf("Delete Elment %D\n", *e);
    return OK;
}

void TraverseQueue(SqQueue Q)
{
    printf("\n---------Traverse---------\n");
    while(Q.front != Q.rear)
    {
        printf("%d ", Q.data[Q.front]);
        Q.front = (Q.front+1)%MAXSIZE;
    }
    printf("\n---------Traverse---------\n");
}

int main()
{
    SqQueue Q;
    InitQueue(&Q);
    int i, j;

    for(i=0; i<6; i++)
    {
        EnQueue(&Q, i-5);
    }
    TraverseQueue(Q);
    DeQueue(&Q, &j);
    DeQueue(&Q, &j);
    DeQueue(&Q, &j);
    TraverseQueue(Q);
    return 0;
}
