#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAXSIZE 10      //存储空间分配量
#define OK 1
#define ERROR 0
#define TRUE 1
#define FAUSE 0

typedef int ElemType;   //自定义数据类型
typedef int Status;		//定义状态类型为整形

typedef struct
{
    ElemType data[MAXSIZE];		//存储数据元素 最大值为MAXSIZE
    int length;					//线性表当前长度
}SqList;

//获取元素操作
Status GetElem(SqList L, int i, ElemType *e)
{
	if(L.length == 0 || i < 1 || i > L.length)
		return ERROR;
	*e = L.data[i-1];
	return OK;
}

//插入元素操作
Status InsertList(SqList *L, int i, ElemType e)
{
	int k;
	if (L->length == MAXSIZE)	//代表线性表已满
	{
		printf("list is full\n");
		return ERROR;
	}
	if (i < 1 || i > L->length+1) //插入位置i 非法 i<1判断是否在对头以前, i>length+1 判断是否在队尾以后
	{
		printf("i is iligal\n");
		return ERROR;
	}
	if (i <= L->length)			//若插入位置i不在队尾
	{
		for (k=L->length-1; k>=i-1; k--)	//执行位置i-1 之后的数据 向后移动一位
	//		L->data[k] = L->data[k-1];
			L->data[k+1] = L->data[k];
	//		printf("L->data[%d] --> L->data[%d]\n", L->data[k-1], L->data[k]);
	}
	L->data[i-1] = e;
	L->length ++;
	return OK;
}

//删除元素
Status DeleteList(SqList *L, int i, ElemType *e)
{
	int k;
	if (L->length == 0)			//线性表已空
		return ERROR;
	if (i < 1 || i > L->length)	//删除位置i非法
		return ERROR;
	*e = L->data[i-1];
	if  (i < L->length)
	{
		for(k=i; k<L->length; k++)
			L->data[k-1] = L->data[k];	//执行位置i以后的数据向前移动一位
	}
	L->length--;
	return OK;
}

//定位表中的元素
Status LocateElem(SqList L, ElemType e)
{
	int i;
	for (i=0; i<L.length; i++)
	{
		if (e == L.data[i])
			return i+1;
	}
	return ERROR;
}

//返回线性表长度
Status ListLength(SqList L)
{
	if (L.length != 0)
		return L.length;
}

//清空线性表
void ClearList(SqList *L)
{
	L->length = 0;
}

//初始化线性表
Status InitList(SqList *sq)
{
	sq->length = 0;
	return TRUE;
}

//遍历线性表
void TraversalList(SqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		printf("- ");
	}printf("\n");
	for (i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	printf("\n");
	for (i = 0; i < L.length; i++)
	{
		printf("- ");
	}

}

int main()
{
	SqList sq;
    InitList(&sq);

	int i;
	for (i = 1; i < 9; i++)
	{
		InsertList(&sq, 1, i);
		
	}

	sq.length = 0;

	for (i = 1; i < 9; i++)
	{
		InsertList(&sq, i, i);
		
	}
	
	

	InsertList(&sq, 9, 111);
	TraversalList(sq);
	printf("\n");

	printf("111 is in : %d", LocateElem(sq, 111));
	printf("\n");

	printf("ListLength is %d\n", ListLength(sq));
	printf("\nlength is :%d\n", sq.length);

	return 0;
}







