#include <stdio.h>
#define MAX_SIZE 20 //Ĭ�����ֵ
#define OK 1
#define ERROR 0

typedef int SElemType;
typedef int Status;
/*
Oprations
    InitStack(*S)       ��ʼ��ջ���� ����һ����ջ
    DestoryStack(*S)    ����ջ���� (������)
    ClearStack(*S)      ���ջ
    StackEmpty(S)       ջ�п� ��Ϊ�շ��� true ���� false
    GetTop(S, *e)       ��ջ�ǿշ���ջ��Ԫ��e
    Push(*S, e)         ��ջ����, ��eԪ��ѹջ
    Pop(*S, *e)         ��ջ����, ��eԪ�س�ջ
    StackLength(S)      ����ջS�е�Ԫ�ظ���
*/

typedef struct stack
{
    SElemType data[MAX_SIZE];   //��������Ԫ��
    int top;                    //ջ��ָ��
}SqStack;

Status InitStack(SqStack *S)
{
    S->top = -1;
    return OK;
}

Status Push(SqStack *S, SElemType e)
{
    if(S->top == MAX_SIZE-1)    //ջ�Ѿ������λ�� ������ѹջ
    {
        printf("Stack is already full, can't push anything\n");
        return ERROR;
    }
    S->top ++;
    S->data[S->top] = e;        //��������
    return OK;
}

Status Pop(SqStack *S, SElemType *e)
{
    if(S->top == -1)        //ջ�Ѿ�����ײ�û��Ԫ�� ���ܳ�ջ
    {
        printf("Stack is empty, can't pop anything\n");
        return ERROR;
    }
    *e = S->data[S->top];
    S->top --;
    return *e;
}

void TraverseStack(SqStack S)
{
    printf("\n--------Traverse--------\n");
    while(S.top != -1)      //ջԪ�ز�����
    {
        printf("%d ",S.data[S.top]);
        S.top--;
    }
    printf("\n--------Traverse---------\n");
}
int main()
{
    int i, j;
    SqStack S;
    InitStack(&S);
    for(i=1; i<10; i++)
        Push(&S, i);
     TraverseStack(S);
    for(i=1; i<6; i++)
    {
        Pop(&S, &j);
        printf("%d-", j);
    }printf("\n");
    TraverseStack(S);
    printf("ջԪ�ظ���ΪS.top+1 : %d ", S.top+1);
    return 0;
}
