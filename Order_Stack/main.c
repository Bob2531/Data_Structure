#include <stdio.h>
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

typedef struct stack
{
    SElemType data[MAX_SIZE];   //数组数据元素
    int top;                    //栈顶指针
}SqStack;

Status InitStack(SqStack *S)
{
    S->top = -1;
    return OK;
}

Status Push(SqStack *S, SElemType e)
{
    if(S->top == MAX_SIZE-1)    //栈已经是最高位置 不能再压栈
    {
        printf("Stack is already full, can't push anything\n");
        return ERROR;
    }
    S->top ++;
    S->data[S->top] = e;        //插入数据
    return OK;
}

Status Pop(SqStack *S, SElemType *e)
{
    if(S->top == -1)        //栈已经是最底层没有元素 不能出栈
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
    while(S.top != -1)      //栈元素不到底
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
    printf("栈元素个数为S.top+1 : %d ", S.top+1);
    return 0;
}
