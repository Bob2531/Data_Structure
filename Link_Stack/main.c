#include <stdio.h>
#include <malloc.h>
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

typedef struct StackNode
{
    SElemType data;     //��������Ԫ��
    struct Stack *next; //ջ��ָ��
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
}LinkStack;

Status InitLinkStack(LinkStack *S)
{
    printf("Initializing ... ");
    S->top = (LinkStackPtr)malloc(sizeof(StackNode));   //��̬����һ��LinkStackPtr���͵Ĵ�СΪStackNode��ջ��
    if(!S->top) //������ʧ��: S-topΪ��
        {printf("malloc fail, check\n");return ERROR;}
    S->top = NULL;
    S->count = 0;
    printf("Done\n");
    return OK;
}

int StackEmpty(LinkStack S)
{
    if (S.count == 0)     //���ջ��ָ��ΪNULL
        return 1;
    else
        return 0;
}
Status Push(LinkStack *S, SElemType e)
{
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top;   //��s����һ���ڵ�ָ��ջS��ջ��ָ��
    S->top = s;         //ջS��ջ��ָ��ָ��s
    S->count++;
    return OK;
}

Status Pop(LinkStack *S, SElemType *e)
{
    LinkStackPtr p;
    if(StackEmpty(*S))
//    if(S->count==0)
        {printf("Stack is empty\n");return ERROR;}
    p = S->top;             //�ջ��ָ�븳ֵ��ָ��p
    *e = S->top->data;      //����ջ��ָ���Ԫ��
    S->top = S->top->next;  //��ջ��ָ������һ��
    free(p);                //�ͷ�
    S->count--;
    printf("Pop :%d\n", *e);
    return OK;
}

void TraverseStack(LinkStack S)
{
    LinkStackPtr p;
    p = S.top;
    printf("\n-------Traverse-------\n");
    while(p)
    {
        printf("%d-", p->data);
        p = p->next;
    }
    printf("\n-------Traverse-------\n");
}
int main()
{
    int i, j;
    LinkStack S;
    InitLinkStack(&S);
    for(i=0; i<10; i++)
        Push(&S, i);
    TraverseStack(S);
    for(i=3; i<14; i++)
        Pop(&S, &j);
    if (StackEmpty(S))
        printf("empty\n");
    TraverseStack(S);
    return 0;
}
