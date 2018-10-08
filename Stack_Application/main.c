#include <stdio.h>
#include <malloc.h>
#include <string.h>

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

int StackLength(LinkStack S)
{
    LinkStackPtr s = S.top;
    int Stack_length = 0;
    while(s)
    {
        Stack_length++;
        s = s->next;
    }
    printf("Stack's length is %d\n", Stack_length);
    return Stack_length;
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
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n-------Traverse-------\n");
}

int calculator(int num_1, int num_2, char op)
{
    switch(op)
        {
            case'+':return num_1 + num_2;
            case'-':return num_1 - num_2;
            case'/':return num_1 / num_2;
            case'*':return num_1 * num_2;
            default: return ERROR;
        }
}
int main()
{
    int i, j, Str_len, num;

    char Postfix_expression[30];
    //Postfix_expression = "132-+";
    char charactor;      //�洢��׺���ʽ
    LinkStack S;
    InitLinkStack(&S);

    printf("Please input the Postfix_Expression:");
    gets(Postfix_expression);
    printf("Postfix_Expression is %s\n", Postfix_expression);
    Str_len = strlen(Postfix_expression);      //�õ�ջ�ĳ���
    printf("Len Str is %d\n", strlen(Postfix_expression));

    int Op_1, Op_2, Outcome;
    for(i=0; i<Str_len; i++)
    {
        //charactor = Postfix_expression[i]-'0';
        if (Postfix_expression[i]<='9' && Postfix_expression[i]>='1')   //�������־�ѹջ
        {
            num = (int)Postfix_expression[i]-'0';   //�õ��������Ͳ����
            Push(&S, num);
            printf("Push number %d\n", num);
        }
        else                        //����ͳ�ջ����������
        {
            Pop(&S, &Op_2);
            Pop(&S, &Op_1);
            Outcome = calculator(Op_1, Op_2, Postfix_expression[i]);    //������
            Push(&S, Outcome);                              //������ѹջ
            printf("%c \n", Postfix_expression[i]);
        }
    }
    Pop(&S, &Outcome);  //�������
    printf("Outcome is %d", Outcome);
    //TraverseStack(S);

    return 0;
}
