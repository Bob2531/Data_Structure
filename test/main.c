////#include<stdio.h>
//#include<string.h>
//
//#define maxsize 10
/*
typedef struct{
    int data[maxsize];
    int front;//队头指针
    int rear;//队尾指针
}squeue;
void createsqueue(squeue *q){//初始化队列
    int i;
    int n;
    int count;
    q->front=0;
    q->rear=0;
    printf("请输入需要入队的个数:");
    scanf("%d",&count);
    printf("请输入入队元素:");
    for(i=0;i<=count-1;++i){
        scanf("%d",&n);
        q->rear=q->rear+1;
        q->data[q->rear]=n;
        //printf("%d",q->data[q->rear]);
    }
}
void insertqueue(squeue *q){//插入元素
    int i,e;
    printf("请输入需要插入的元素:");
    scanf("%d",&e);
    if((q->rear+1)%maxsize==q->front){//判断队列是否已满
        printf("队列已满无法操作!");
    }
    else{
        q->rear=(q->rear+1)%maxsize;
        q->data[q->rear]=e;

    }
    printf("插入成功!");
}

void delectqueue(squeue *q){
    int *e;
    int i;
    if(q->front==q->rear){
        printf("队列为空无法操作!");
    }
    else{
        q->front=(q->front+1)%maxsize;
        *e=&(q->data[q->front]);
        printf("出队元素为%d\n",e);
        printf("出队元素为%d\n",*e);
        //free(e);
        printf("此时队中元素为:");
        for(i=q->front+1;i<=5;i++){
            printf("%d",q->data[i]);
        }
    }
}
void showqueue(squeue q){
    int i;
    int length;
    length=(q.rear-q.front+maxsize)%maxsize;//求队列长度
    printf("此时队列长度为%d\n",length);
    for(i=q.front;i<=length;i++){
        printf("%d",q.data[i]);
    }
}
int main(){
    squeue q;
    int a;
    printf("****************************************");
    printf("\n1.创建一个队列");
    printf("\n2.添加一个元素");
    printf("\n3.删除一个元素");
    printf("\n4.显示当前队列元素");
    printf("\n****************************************");
    printf("\n请输入您要选择的操作:");
    while(scanf("%d",&a)!=EOF){
        switch(a){
            case 1:
                createsqueue(&q);
                break;
            case 2:
                insertqueue(&q);
                break;
            case 3:
                delectqueue(&q);
                break;
            case 4:
                showqueue(q);
        }
    }
    */
/*
void a(char*ch)
{
    int i = 0, len=0;
    char *str =ch;
    while(*str)
    {
        str++;
        len++;
    }
    printf("%c", *str);
}
int main()
{
    int arr[3][4], num;
    int i, j, q;
    for(i=0; i<3; i++)
            for(q=0; q<4; q++)
    {
        arr[i][q] = q;
    }

    for(i=0; i<3; i++)
        for(q=0; q<5; q++)
            printf("%d\t", arr[i][q]);
        printf("\n");
    printf("\n");

    return 0;
}
*/
/*
#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
/*
#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535

typedef struct
{
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;   /* 对边集数组Edge结构的定义 */

/* 构件图 */
//
//void CreateMGraph(MGraph *G)
//{
//	int i, j;
//
//	/* printf("请输入边数和顶点数:"); */
//	G->numEdges=15;
//	G->numVertexes=9;
//
//	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
//	{
//		for ( j = 0; j < G->numVertexes; j++)
//		{
//			if (i==j)
//				G->arc[i][j]=0;
//			else
//				G->arc[i][j] = G->arc[j][i] = INFINITY;
//		}
//	}
//
//	G->arc[0][1]=10;
//	G->arc[0][5]=11;
//	G->arc[1][2]=18;
//	G->arc[1][8]=12;
//	G->arc[1][6]=16;
//	G->arc[2][8]=8;
//	G->arc[2][3]=22;
//	G->arc[3][8]=21;
//	G->arc[3][6]=24;
//	G->arc[3][7]=16;
//	G->arc[3][4]=20;
//	G->arc[4][7]=7;
//	G->arc[4][5]=26;
//	G->arc[5][6]=17;
//	G->arc[6][7]=19;
//
//	for(i = 0; i < G->numVertexes; i++)
//	{
//		for(j = i; j < G->numVertexes; j++)
//		{
//			G->arc[j][i] =G->arc[i][j];
//		}
//	}
//
//}
//
///* 交换权值 以及头和尾 */
//void Swapn(Edge *edges,int i, int j)
//{
//	int temp;
//	temp = edges[i].begin;
//	edges[i].begin = edges[j].begin;
//	edges[j].begin = temp;
//	temp = edges[i].end;
//	edges[i].end = edges[j].end;
//	edges[j].end = temp;
//	temp = edges[i].weight;
//	edges[i].weight = edges[j].weight;
//	edges[j].weight = temp;
//}
//
///* 对权值进行排序 */
//void sort(Edge edges[],MGraph *G)
//{
//	int i, j;
//	for ( i = 0; i < G->numEdges; i++)
//	{
//		for ( j = i + 1; j < G->numEdges; j++)
//		{
//			if (edges[i].weight > edges[j].weight)
//			{
//				Swapn(edges, i, j);
//			}
//		}
//	}
//	printf("权排序之后的为:\n");
//	for (i = 0; i < G->numEdges; i++)
//	{
//		printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
//	}
//
//}
//
///* 查找连线顶点的尾部下标 */
//int Find(int *parent, int f)
//{
//	while ( parent[f] > 0)
//	{
//		f = parent[f];
//		printf("inter while %d\n", f);
//	}
//	return f;
//}
//
///* 生成最小生成树 */
//void MiniSpanTree_Kruskal(MGraph G)
//{
//	int i, j, n, m;
//	int k = 0;
//	int parent[MAXVEX];/* 定义一数组用来判断边与边是否形成环路 */
//
//	Edge edges[MAXEDGE];/* 定义边集数组,edge的结构为begin,end,weight,均为整型 */
//
//	/* 用来构建边集数组并排序********************* */
//	for ( i = 0; i < G.numVertexes-1; i++)
//	{
//		for (j = i + 1; j < G.numVertexes; j++)
//		{
//			if (G.arc[i][j]<INFINITY)
//			{
//				edges[k].begin = i;
//				edges[k].end = j;
//				edges[k].weight = G.arc[i][j];
//				k++;
//			}
//		}
//	}
//	sort(edges, &G);
//	/* ******************************************* */
//
//
//	for (i = 0; i < G.numVertexes; i++)
//		parent[i] = 0;	/* 初始化数组值为0 */
//
//	printf("打印最小生成树：\n");
//	for (i = 0; i < G.numEdges; i++)	/* 循环每一条边 */
//	{
//		n = Find(parent,edges[i].begin);
//		m = Find(parent,edges[i].end);
//		if (n != m) /* 假如n与m不等，说明此边没有与现有的生成树形成环路 */
//		{
//			parent[n] = m;	/* 将此边的结尾顶点放入下标为起点的parent中。 */
//							/* 表示此顶点已经在生成树集合中 */
//			printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
//			printf("\t\t");
//			for(j=0;j<9;j++)
//                printf("%d\t", parent[j]);
//            printf("\n");
//		}
//	}
//}
//
//void print(int *arr, int max)
//{
//    int i=0;
//    while(i<max)
//        printf("%d\t", arr[i++]);
//    printf("\n");
//}
//
//int main(void)
//{
//	MGraph G;
//	CreateMGraph(&G);
//	MiniSpanTree_Kruskal(G);
//	return 0;
//}
//

#include<stdio.h>
#define maxsize 50//
//#define maxsize1 50//顺序栈最大容量
#define ERROR 1//错误标记

typedef struct binode{//二叉树的结构体定义
    char data;
    struct binode *lchild,*rchild;
}bitnode,*bitree;
typedef struct{//栈的结构体定义
    bitree data[maxsize];
    int top;
}sqstack;
void initstack(sqstack *s){//初始化栈
    s->top=-1;
}

bitree push(sqstack *s,bitree result){//进栈
//    if(s->top==maxsize){
//        return ERROR;
//    }
//    else{
        s->top++;
        s->data[s->top]=result;
        //printf("************%c***********\n",result);
    //}
}

bitree pop(sqstack *s){//出栈
//    if(s->top==-1){
//        return ERROR;
//    }
//    else{
        bitree result1;
        result1=s->data[s->top];
        //printf("------------%c-----------\n",result1);
        s->top--;
       // printf("&c",result1);
        return result1;
//    }
}
void createbitree(bitree *t){
    char ch;
    scanf("%c",&ch);
    if(ch=='#'){
        *t==NULL;
    }
    else{
        *t=(bitree)malloc(sizeof(bitnode));
        if(!*t){
            printf("distribute storage failed");
        }
        else{
            (*t)->data=ch;
            createbitree(&(*t)->lchild);
            createbitree(&(*t)->rchild);
        }
    }
}
//void visit(bitree *t){
//    if((*t)->rchild->data!=NULL){
//        (*t)=(*t)->rchild->data;
//    }
//    if((*t)->lchild->data!=NULL){
//        (*t)=(*t)->lchild->data;
//    }
void preordertraverse(bitree *t){
    sqstack s;
    bitree *p;
    //p(*t;
//    bitree a;
//    bitree b;
    bitree c;
    initstack(&s);
    if(*t!=NULL){
       //printf("********%c*******",(*t)->data);
       push(&s,*t);//根结点入栈
       while(s.top!=-1){
         c = pop(&s);
          printf("%c\t",c->data);
          if(c->rchild!=NULL){
             push(&s,c->rchild);

          }
          if(c->lchild!=NULL){
             push(&s,c->lchild);

          }
    }
    }
}
int main(){
    int op;
    sqstack s;
    bitree t;
    //initstack(&s);
    createbitree(&t);
    printf("\n******option******");
    printf("\n1.output preorder");
    printf("\n2.output inorder");
    printf("\n3.output postorder");
    while(scanf("%d",&op)!=EOF){
        switch(op){
            case 1:
                preordertraverse(&t);
                break;
            case 2:
                //inordertraverse(t);
                break;
            case 3:
                //postordertraverse(t);
                break;
        }
    }
}
