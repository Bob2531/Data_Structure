#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX_SIZE 20 //默认最大值
#define OK 1
#define ERROR 0

typedef int SElemType;
typedef int Status;
/*
Oprations
    InitStack(*S)       初始化栈操作 建立一个空栈
    DestoryStack(*S)    销毁栈操作 (若存在)
    ClearStack(*S)      清空栈
    StackEmpty(S)       栈判空 若为空返回 true 否则 false
    GetTop(S, *e)       若栈非空返回栈顶元素e
    Push(*S, e)         若栈存在, 将e元素压栈
    Pop(*S, *e)         若栈存在, 将e元素出栈
    StackLength(S)      返回栈S中的元素个数
*/

typedef struct StackNode
{
    SElemType data;     //数组数据元素
    struct Stack *next; //栈顶指针
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
}LinkStack;

Status InitLinkStack(LinkStack *S)
{
    printf("Initializing ... ");
    S->top = (LinkStackPtr)malloc(sizeof(StackNode));   //动态申请一个LinkStackPtr类型的大小为StackNode的栈顶
    if(!S->top) //若申请失败: S-top为空
        {printf("malloc fail, check\n");return ERROR;}
    S->top = NULL;
    S->count = 0;
    printf("Done\n");
    return OK;
}

int StackEmpty(LinkStack S)
{
    if (S.count == 0)     //如果栈顶指针为NULL
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
    s->next = S->top;   //令s的下一个节点指向栈S的栈顶指针
    S->top = s;         //栈S的栈顶指针指向s
    S->count++;
    return OK;
}

Status Pop(LinkStack *S, SElemType *e)
{
    LinkStackPtr p;
    if(StackEmpty(*S))
//    if(S->count==0)
        {printf("Stack is empty\n");return ERROR;}
    p = S->top;             //令将栈顶指针赋值给指针p
    *e = S->top->data;      //返回栈顶指针的元素
    S->top = S->top->next;  //将栈顶指针下移一个
    free(p);                //释放
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
    char charactor;      //存储后缀表达式
    LinkStack S;
    InitLinkStack(&S);

    printf("Please input the Postfix_Expression:");
    gets(Postfix_expression);
    printf("Postfix_Expression is %s\n", Postfix_expression);
    Str_len = strlen(Postfix_expression);      //得到栈的长度
    printf("Len Str is %d\n", strlen(Postfix_expression));

    int Op_1, Op_2, Outcome;
    for(i=0; i<Str_len; i++)
    {
        //charactor = Postfix_expression[i]-'0';
        if (Postfix_expression[i]<='9' && Postfix_expression[i]>='1')   //若是数字就压栈
        {
            num = (int)Postfix_expression[i]-'0';   //得到整形类型并输出
            Push(&S, num);
            printf("Push number %d\n", num);
        }
        else                        //否则就出栈两个做运算
        {
            Pop(&S, &Op_2);
            Pop(&S, &Op_1);
            Outcome = calculator(Op_1, Op_2, Postfix_expression[i]);    //计算结果
            Push(&S, Outcome);                              //计算结果压栈
            printf("%c \n", Postfix_expression[i]);
        }
    }
    Pop(&S, &Outcome);  //弹出结果
    printf("Outcome is %d", Outcome);
    //TraverseStack(S);

    return 0;
}
