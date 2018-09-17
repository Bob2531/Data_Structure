#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FAUSE 0

typedef int ElemType;   //�Զ�����������
typedef int Status;		//����״̬����Ϊ����

typedef struct Node
{
    ElemType data;      //����������
    struct Node *next;  //����ָ����
} Node;
typedef struct Node *LinkList; //����LinkList*

//��ʼ������
void InitLink(LinkList *L)
{
    (*L) = (LinkList)malloc(sizeof(Node));     //Ϊ����L����ռ�
    (*L)->next = NULL;     //��ͷ���ָ���
}

//��ȡL�е�i��Ԫ�ص�ֵ ����e
Status GetElem(LinkList L,int i,ElemType *e)
{
    int position;
    LinkList p;      //����һ��ָ��p
    p = L->next;     //pָ������L�ĵ�һ�����
    position = 1;
    while(p && position<i)  //��p��ĩβ֮ǰ ���Ҳ��ҵ�λ��position < i
    {
        p = p->next;    //pָ����һ���ڵ�
        position ++;
    }
    if(!p || position>i)    //��p�Ľ��Ϊ�� ���߲��ҵ�λ��position > i ���ʾ����ʧ��
    {
        printf("\n---------GetElem---------\n");
        printf("---------GetElem Fail---------");
        printf("\n---------GetElem---------\n");
        return ERROR;
    }
    *e = p->data;   //��ȡ�����ҵ���ֵ
    return OK;
}

//ִ�в������ �ڵ�i��λ�ò����½ڵ� ��ֵΪe
Status ListInsert(LinkList *L,int i, ElemType e)
{
    int position = 1;
    LinkList p, s;     //����һ���ڵ�p, s�����²���Ľڵ�
    p = *L;         //pָ������ĵ�һ���ڵ�
    while(p && position < i)    //��p�ڵ㲻Ϊ��(û�е�ĩβ), �����λ��С��i
    {
        p = p->next;
        position ++;
    }
    if(!p || position > i)  //����������ĩβ��ʱ�� || ��i��Ԫ�ز�����
    {
        printf("\n---------ListInsert---------\n");
        printf("---------ListInsert Fail---------");
        printf("\n---------ListInsert---------\n");
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(Node));  //�����½ڵ�Ϊ�����ռ�
    s->next = p->next;  //s�ڵ�ָ��p�ĺ�һ�����
    p->next = s;        //p���ָ��s
    s->data = e;    //����Ԫ�ظ�ֵ
    //printf("\n---------ListInsert---------\n");
    printf("%d has been inserted\n", e);
    //printf("\n---------ListInsert---------\n");
    return OK;
}

//����ɾ�� �ڵ�i��λ��ɾ���ڵ�
Status ListDelete(LinkList *L,int i,ElemType *e)
{
    int position = 1;
    LinkList p, q;      //�����½��p����ָ������L qΪ��ɾ���ڵ�
    p = *L;
    while(p && position<i)
    {
        p = p->next;
        position ++;
    }
    if(!p || position>i)    //p��㵽ĩβ || positionλ�÷Ƿ�
    {
        printf("\n---------ListDelete---------\n");
        printf("---------ListDelete Fail---------");
        printf("\n---------ListDelete---------\n");
        return ERROR;
    }
    q = p->next;        //�� p �� p->next �ڵ��ַ��ͬ
    p->next = q->next;  //��p����һ���ڵ� ָ��q����һ���ڵ�
    *e = q->data;       //����e��ֵ
    free(q);            //�ͷ�q��� �����ڴ�
    //printf("\n---------ListInsert---------\n");
    printf("%d has been deleted\n", *e);
    //printf("\n---------ListInsert---------\n");
    return OK;
}

//��������
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

//ͷ�巨��������
void CreateListHead(LinkList *L,int n)
{
    int i;          //ѭ������
    LinkList p;     //����һ��ָ��
    (*L) = (LinkList)malloc(sizeof(Node));  //Ϊͷ�������ַ
    (*L)->next = NULL;  //��ͷ���ָ��ָ���

    for(i=0; i<n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));  //�����ַ
        p->data = rand()%100 + 1;           //����100 �ڵ������
        printf("random numb is %d\n", p->data);
        p->next = (*L)->next;               //p����һ�����ָ��L����һ�����
        (*L)->next = p;                     //L����һ�����ָ���½ڵ�p
    }
    printf("CreateListHead Compelished\n");
}

//β�巨��������
void CreateListTail(LinkList *L,int n)
{
    int i;          //ѭ������
    LinkList p, r;     //��������ָ��p,r
    (*L) = (LinkList)malloc(sizeof(Node));  //Ϊͷ�������ַ
    r = *L;     //rָ������L��β���Ľڵ�

    for(i=0; i<n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));  //�����ַ
        p->data = rand()%100 + 1;           //����100 �ڵ������
        printf("random numb is %d\n", p->data);
        r->next = p;        //r����һ�����ָ��p
        r = p;              //��pΪr ִ����һ��ѭ���Ĳ���
    }
    r->next = NULL;
    printf("CreateListTial Compelished\n");
}

//�������
void ClearList(LinkList *L)
{
    LinkList p, q;
    p = (*L)->next;    //pָ��L�ĵ�һ�����
    while(p)        //p��Ϊ��
    {
        q = p->next;    //��qΪp����һ�����
        printf("deleting data %d and free it...\n", p->data);
        free(p);
        p = q;          //��q �� p ִ����һ��ѭ��
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
