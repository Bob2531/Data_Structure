#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FAUSE 0
#define MAXSIZE 100

typedef int ElemType;   //自定义数据类型
typedef int Status;		//定义状态类型为整形

typedef struct Node
{
    ElemType data;      //定义数据域
    int cur             //游标(Cursor) 为0时表示无指向
} Component, StaticLinkList[MAXSIZE]

//初始化静态链表
Status InitList(StaticLinkList space)
{
    int i;      //i为下标
    for (i=0; i<MAXSIZE-1; i++)
        space[i].cur = i+1;     //以此赋下标
    space[MAXSIZE-1].cur = 0;   //处理最后一个元素的游标为0
    return OK;
}

//实现类malloc函数分配空间
int Malloc_SLL(StaticLinkList space)
{
    int i = space[i].cur        //当前数组第一个元素的cur值 返回第一个元素备用空闲下标
    if(space[i])
        space[0].cur = space[i].cur;    //将下一个分量用作备用赋值给第一个元素的cur
    return i;       //返回找到的备用下标的值
}

