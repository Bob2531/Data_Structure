#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FAUSE 0

typedef int ElemType;   //自定义数据类型
typedef int Status;		//定义状态类型为整形

typedef struct Node
{
    ElemType data;      //定义数据域
    struct Node *next;  //定义指针域
} Node;
typedef struct Node *LinkList; //定义LinkList*

//初始化链表
void InitLink(LinkList *L)
{
    (*L) = (LinkList)malloc(sizeof(Node));     //为链表L分配空间
    (*L)->next = NULL;     //令头结点指向空
}

//获取L中第i个元素的值 返回e
Status GetElem(LinkList L,int i,ElemType *e)
{
    int position;
    LinkList p;      //声明一个指针p
    p = L->next;     //p指向链表L的第一个结点
    position = 1;
    while(p && position<i)  //当p到末尾之前 并且查找的位置position < i
    {
        p = p->next;    //p指向下一个节点
        position ++;
    }
    if(!p || position>i)    //当p的结点为空 或者查找的位置position > i 则表示查找失败
    {
        printf("\n---------GetElem---------\n");
        printf("---------GetElem Fail---------");
        printf("\n---------GetElem---------\n");
        return ERROR;
    }
    *e = p->data;   //获取被查找到的值
    return OK;
}

//执行插入操作 在第i个位置插入新节点 数值为e
Status ListInsert(LinkList *L,int i, ElemType e)
{
    int position = 1;
    LinkList p, s;     //声明一个节点p, s用于新插入的节点
    p = *L;         //p指向链表的第一个节点
    while(p && position < i)    //当p节点不为空(没有到末尾), 插入的位置小于i
    {
        p = p->next;
        position ++;
    }
    if(!p || position > i)  //当到达链表末尾的时候 || 第i个元素不存在
    {
        printf("\n---------ListInsert---------\n");
        printf("---------ListInsert Fail---------");
        printf("\n---------ListInsert---------\n");
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(Node));  //生成新节点为其分配空间
    s->next = p->next;  //s节点指向p的后一个结点
    p->next = s;        //p结点指向s
    s->data = e;    //数据元素赋值
    //printf("\n---------ListInsert---------\n");
    printf("%d has been inserted\n", e);
    //printf("\n---------ListInsert---------\n");
    return OK;
}

//链表删除 在第i个位置删除节点
Status ListDelete(LinkList *L,int i,ElemType *e)
{
    int position = 1;
    LinkList p, q;      //生成新结点p令其指向链表L q为待删除节点
    p = *L;
    while(p && position<i)
    {
        p = p->next;
        position ++;
    }
    if(!p || position>i)    //p结点到末尾 || position位置非法
    {
        printf("\n---------ListDelete---------\n");
        printf("---------ListDelete Fail---------");
        printf("\n---------ListDelete---------\n");
        return ERROR;
    }
    q = p->next;        //令 p 与 p->next 节点地址等同
    p->next = q->next;  //令p的下一个节点 指向q的下一个节点
    *e = q->data;       //返回e的值
    free(q);            //释放q结点 回收内存
    //printf("\n---------ListInsert---------\n");
    printf("%d has been deleted\n", *e);
    //printf("\n---------ListInsert---------\n");
    return OK;
}

//遍历链表
void TraverseList(LinkList L)
{
    LinkList p = L->next;
    printf("\n---------Traversing---------\n");
    while(p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n---------Traverse End---------\n");
}

//头插法建立链表
void CreateListHead(LinkList *L,int n)
{
    int i;          //循环变量
    LinkList p;     //定义一个指针
    (*L) = (LinkList)malloc(sizeof(Node));  //为头结点分配地址
    (*L)->next = NULL;  //令头结点指针指向空

    for(i=0; i<n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));  //分配地址
        p->data = rand()%100 + 1;           //生成100 内的随机数
        printf("random numb is %d\n", p->data);
        p->next = (*L)->next;               //p的下一个结点指向L的下一个结点
        (*L)->next = p;                     //L的下一个结点指向新节点p
    }
    printf("CreateListHead Compelished\n");
}

//尾插法建立链表
void CreateListTail(LinkList *L,int n)
{
    int i;          //循环变量
    LinkList p, r;     //定义两个指针p,r
    (*L) = (LinkList)malloc(sizeof(Node));  //为头结点分配地址
    r = *L;     //r指向链表L的尾部的节点

    for(i=0; i<n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));  //分配地址
        p->data = rand()%100 + 1;           //生成100 内的随机数
        printf("random numb is %d\n", p->data);
        r->next = p;        //r的下一个结点指向p
        r = p;              //令p为r 执行下一次循环的操作
    }
    r->next = NULL;
    printf("CreateListTial Compelished\n");
}

//清空链表
void ClearList(LinkList *L)
{
    LinkList p, q;
    p = (*L)->next;    //p指向L的第一个结点
    while(p)        //p不为空
    {
        q = p->next;    //令q为p的下一个结点
        printf("deleting data %d and free it...\n", p->data);
        free(p);
        p = q;          //令q 是 p 执行下一次循环
    }
    (*L)->next = NULL;
}

int main()
{
    /*
    int i = 0;
    int delete_num;
    printf("Initial LinkList...\n");
    LinkList *L;
    InitLink(&L);
    printf("\nInserting...\n");
    for(i=1; i<10; i++)
    {
        ListInsert(&L, i, i);
    }
    ListInsert(&L, 7, 111);

    printf("\nList After Instered:\n");
    TraverseList(L);

    printf("\nDeleting...\n");
    for(i=3; i<7; i++)
    {
        ListDelete(&L, i, &delete_num);
    }
    printf("List After Delete:\n");
    */
    LinkList L, Q;
    int num = 6;
    CreateListHead(&L, num);
    CreateListTail(&Q, num);
    TraverseList(L);
    TraverseList(Q);
    ClearList(&L);
    TraverseList(L);
    return 0;
}
