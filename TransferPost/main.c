#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX_SIZE 20 //Ĭ�����ֵ
#define OK 1
#define ERROR 0

typedef char SElemType;
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

char GetTop(LinkStack S)
{
    if(StackEmpty(S))
        {printf("Empty Stack\n");return;}
    else
        return S.top->data;
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
    //printf("Pop :%c\n", *e);
    return OK;
}

void TraverseStack(LinkStack S)
{
    LinkStackPtr p;
    p = S.top;
    printf("\n-------Traverse-------\n");
    while(p)
    {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n-------Traverse-------\n");
}

int main()
{
    int i, j, Str_len, num, PostLen;

    char Nomal_expression[30];      //�������ʽ
    char Postfix_expression[30];    //��׺���ʽ
    char charactor;
    LinkStack S;
    InitLinkStack(&S);

    printf("Please input the Nomal_Expression: ");
    gets(Nomal_expression);
    Str_len = strlen(Nomal_expression);      //�õ�ջ�ĳ���
    printf("Len Str is %d\n", strlen(Nomal_expression));

    for(i=0; i<Str_len; i++)
    {
        //��Ϊ���� ��ֱ�����
        if(Nomal_expression[i]>='0' && Nomal_expression[i]<='9')
        {
            Postfix_expression[i] = (char)Nomal_expression[i]-'0';//��ֵ����׺���ʽ int��
            printf("%d ", Postfix_expression[i]);
        }
        //��Ϊ������ ��ִ�����²���:
        else
        {
            if(StackEmpty(S) || Nomal_expression[i] == '(') //��ջΪ��, �����ѹջ
                Push(&S, Nomal_expression[i]);
            //�ж����ȼ�
            //charactor = GetTop(S);      //�õ�ջ��Ԫ��
            else if(Nomal_expression[i] == ')')     //��Ϊ���������Դ˳�ջֱ��ƥ�䵽������Ϊֹ
            {
                do
                {
                    Pop(&S, &charactor);    //��ջԪ��
                    printf("%c ", charactor);
                }
                while(charactor == '(');    //ֱ������������
                Pop(&S, &charactor);    //��ջ������
            }
            else    //�������������
            {
                //��Ϊ + -
                if(Nomal_expression[i]=='+' || Nomal_expression[i]=='-')
                {
                    charactor = GetTop(S);      //ȡջ��
                    if (charactor=='+'|| charactor=='-')    //���ȼ����
                        Push(&S, Nomal_expression[i]);
                    else    //���ȼ����ڵ�ǰ
                    {
                        while(charactor=='+'|| charactor=='-');  //���ȼ����
                        {
                            Pop(&S, &charactor);
                            printf("%c ", charactor);
                        }
                        Push(&S, Nomal_expression[i]);      //��ǰ����ѹջ
                    }
                }
                else if(Nomal_expression[i]=='*' || Nomal_expression[i]=='/')
                {
                    charactor = GetTop(S);      //ȡջ��
                    while(charactor=='*' || charactor=='/') //��ջ��Ԫ��Ϊ* or /
                    {
                        Push(&S, Nomal_expression[i]);  //����ѹջ
                    }
                }
            }
                //printf("%c ", Nomal_expression[i]);
        }
    }

//    PostLen = strlen(Postfix_expression);
//    for(i=0; i<PostLen; i++)
//        printf("\nPostfix_Expression is %c ", Postfix_expression[i]);
//    puts(&Postfix_expression);
    TraverseStack(S);
    return 0;
}
