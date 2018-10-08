#include <stdio.h>
#include <malloc.h>
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
