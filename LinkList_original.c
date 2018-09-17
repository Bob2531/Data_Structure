#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FAUSE 0

typedef int ElemType;
typedef int Status;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node, *LinkList;

/*获取第i个元素操作
链表存在的条件 1<= i <= ListLength
e 返回查找到i元素的值
*/
Status GetElem(LinkList L, int i, ElemType *e)
{
	int j;
	LinkList p;
	p = L->next;		//p指向链表的第一个结点
	j = 1;				//j 设置为计数器

	while(p && j < i)	//当指向的下一个节点不为空 并且 在查找元素之前
	{
		p = p->next;
		j++;			//p 指向下一个节点 计数器++
	}

	if(!p && j > i)		//若p指向的下一个节点是空值(到队尾) 且 查找位置非法
		printf("Node 'i' not find\n");return ERROR;

	//查找到的 第i个元素:
	*e = p->data;
	return OK;
}

/*
在第i个位置上插入一个新元素e
*/
Status ListInsert(LinkList *L, int i, ElemType e)
{
	int j = 1;			//j 设置为计数器
	LinkList p, s;		//定义头指针p 指向L链表, s为插入的节点
	p = *L;

	while(p && j < i)
	{
		p = p->next;
		j++;
	}

	if (!p && j > i)
	{
		printf("Illegal location number inputed\n");
		return ERROR;
	}

	s = (LinkList)malloc(sizeof(Node));	//动态分配内存
	s->data = e;		//新节点赋值
	s->next = p->next; p->next = s;		//插入新节点
	return OK;
}

/*
在第i个位置上删除一个元素e
*/
Status ListDelete(LinkList *L, int i, ElemType *e)
{
	int j = 1;			//j 设置为计数器
	LinkList p, q;		//定义头指针p 指向L链表, s为插入的节点
	p = *L;

	while(p->next && j < i)
	{
		p = p->next;
		j++;
	}

	if (!p->next && j > i)
	{
		printf("Illegal location number inputed\n");
		return ERROR;
	}

	q = p->next;		//将欲删除的结点赋值给q
	*e = q->data;
	p->next = q->next;
	free(q);			//释放q

	return OK;
}

/*头插法创建链表*/
Status CreateListHead(LinkList *L, int n)
{
	LinkList p;
	int i;
	srand(time(0));		//初始化随机种子
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100 + 1;	//随机生成100以内的随机数
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

/*尾插法创建链表*/
Status CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0));		//初始化随机种子
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100 + 1;	//随机生成100以内的随机数
		r->next = p;
		r = p;			//头指针下移
	}
	r->next = NULL;
}

/*
清空链表
*/
Status ClearList(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next;		//p指向第一个结点
	while(p)			//p的下一个节点不为空
	{
		q = p->next;
		p = q;			//结点下移
		free(q);
	}

	(*L)->next = NULL;	//头指针为空
	return OK;
}

/*
遍历链表
*/
void Visit(LinkList L)
{
	LinkList p = L->next;
	while(p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

/*
得到链表长度
*/
Status ListLength(LinkList L)
{
	int i = 1;
	LinkList p = L->next;
	while(p)
	{
		i++;
		p = p->next;
	}
	return i;
}


int main()
{
	LinkList L;
	int i;
	CreateListHead(&L, 5);
	for (i = 0; i < 10;i++)
	{
		ListInsert(&L, 1, i);
	}
	ListInsert(&L, 9, 11111);
	ListInsert(&L, 1, 100);
	Visit(L);

	printf("LinkList's length is : %d \n", ListLength(L));
	int j = 1;
	for (i = 1;i < ListLength(L) - 4; i++,j++)
	{
		ListDelete(&L, i, &j);
	}
	Visit(L);
	printf("LinkList's length is : %d \n", ListLength(L));
	return 0;
}











