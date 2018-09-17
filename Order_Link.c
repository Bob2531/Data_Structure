#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAXSIZE 10      //存储空间分配量
#define OK 1
#define ERROR 0
#define TRUE 1
#define FAUSE 0
typedef int Status;
typedef int ElemType;

typedef struct //定义顺序表结构体
{
    ElemType data[MAXSIZE]; //顺序表元素
    int length;             //顺序表长度
}SqList;

/*
typedef struct
{
    ElemType *data;          //顺序表元素
    int length;             //顺序表长度
}SeqList;
*/

//初始化顺序表
Status InitList(SqList *L)
{
    L->length = 0;   //将顺序表的长度赋值为0
    return OK;
}

//取顺序表中第i个元素的值
Status GetLlem(SqList L,int i, ElemType *e)
{
    //先作判断:
    //如果表长为0 || 位置小于1 || 位置大于表长
    //则获取失败
    if (L.length<0 || i<1 || i>L.length)
        return ERROR;
    //获取第i个位置的值,对应数组中就是i-1的位置
    *e = L.data[i-1];
    return OK;
}

//插入操作
Status ListInsert(SqList *L, int i, ElemType e)
{
    int position;   //定义插入位置
//  插入时先进行判断
//  若顺序表长度==MAXSIZE 表示线性表已满 不能插入
    if(L->length==MAXSIZE)
    {
        printf("List full, insert fail\n");
        return ERROR;
    }
//  若插入位置   i<0 位置非法
//               i>length+1 位置越界    不能插入
    if(i<1 || i>L->length+1)
    {
        printf("Illegal position i\n");
        return ERROR;
    }
//  若i<length 表示插入元素不在表尾
    if(i<L->length)
    {
        //顺位后移
        for(position=L->length-1; position>i-1; position--)
            L->data[position+1] = L->data[position];  //数据后移
    }
    L->data[position] = e;   //数据传入数组第i-1的位置
    L->length++;            //顺序表长度加一
    printf("Data %d has been Inserted\n", e);
    return OK;
}

int main()
{
    SqList L;   //初始化顺序表
    InitList(&L);   //顺序表长度赋值为0

    int i;
    for(i=1; i<10; i++)
    {
        ListInsert(&L, i, i);
    }
    return 0;
}
