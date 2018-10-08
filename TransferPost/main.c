#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX_SIZE 20 //默认最大值
#define OK 1
#define ERROR 0

typedef char SElemType;
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

char GetTop(LinkStack S)
{
    if(StackEmpty(S))
        {printf("Empty Stack\n");return;}
    else
        return S.top->data;
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

    char Nomal_expression[30];      //正常表达式
    char Postfix_expression[30];    //后缀表达式
    char charactor;
    LinkStack S;
    InitLinkStack(&S);

    printf("Please input the Nomal_Expression: ");
    gets(Nomal_expression);
    Str_len = strlen(Nomal_expression);      //得到栈的长度
    printf("Len Str is %d\n", strlen(Nomal_expression));

    for(i=0; i<Str_len; i++)
    {
        //若为数字 则直接输出
        if(Nomal_expression[i]>='0' && Nomal_expression[i]<='9')
        {
            Postfix_expression[i] = (char)Nomal_expression[i]-'0';//赋值给后缀表达式 int型
            printf("%d ", Postfix_expression[i]);
        }
        //若为操作符 则执行以下操作:
        else
        {
            if(StackEmpty(S) || Nomal_expression[i] == '(') //若栈为空, 则符号压栈
                Push(&S, Nomal_expression[i]);
            //判断优先级
            //charactor = GetTop(S);      //得到栈顶元素
            else if(Nomal_expression[i] == ')')     //若为右括号则以此出栈直到匹配到左括号为止
            {
                do
                {
                    Pop(&S, &charactor);    //出栈元素
                    printf("%c ", charactor);
                }
                while(charactor == '(');    //直到遇到左括号
                Pop(&S, &charactor);    //出栈左括号
            }
            else    //遇到其他运算符
            {
                //若为 + -
                if(Nomal_expression[i]=='+' || Nomal_expression[i]=='-')
                {
                    charactor = GetTop(S);      //取栈顶
                    if (charactor=='+'|| charactor=='-')    //优先级相等
                        Push(&S, Nomal_expression[i]);
                    else    //优先级低于当前
                    {
                        while(charactor=='+'|| charactor=='-');  //优先级相等
                        {
                            Pop(&S, &charactor);
                            printf("%c ", charactor);
                        }
                        Push(&S, Nomal_expression[i]);      //当前符号压栈
                    }
                }
                else if(Nomal_expression[i]=='*' || Nomal_expression[i]=='/')
                {
                    charactor = GetTop(S);      //取栈顶
                    while(charactor=='*' || charactor=='/') //当栈顶元素为* or /
                    {
                        Push(&S, Nomal_expression[i]);  //符号压栈
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
