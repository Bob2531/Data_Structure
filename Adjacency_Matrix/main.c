#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* 最大顶点数，应由用户定义 */
#define MAXSIZE 100
#define INFINITY 65535

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef char VertexType; /* 顶点类型应由用户定义  */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */
typedef int Boolean; /*布尔型数组 值为0 || 1 TRUE or FALSE */

typedef struct
{
    VertexType vexs[MAXVEX];        //顶点数组
    EdgeType arc[MAXVEX][MAXVEX];   //边集
    int Node_num, Edge_num;         //顶点数 边数
}MGraph;

/* 用到的队列结构与函数********************************** */

/* 循环队列的顺序存储结构 */
typedef struct
{
	int data[MAXVEX];
	int front;    	/* 头指针 */
	int rear;		/* 尾指针，若队列不空，指向队列尾元素的下一个位置 */
}Queue;

/* 初始化一个空队列Q */
Status InitQueue(Queue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}

/* 若队列Q为空队列,则返回TRUE,否则返回FALSE */
Status QueueEmpty(Queue Q)
{
	if(Q.front==Q.rear) /* 队列空的标志 */
		return TRUE;
	else
		return FALSE;
}

/* 若队列未满，则插入元素e为Q新的队尾元素 */
Status EnQueue(Queue *Q,int e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* 队列满的判断 */
		return ERROR;
	Q->data[Q->rear]=e;			/* 将元素e赋值给队尾 */
	Q->rear=(Q->rear+1)%MAXSIZE;/* rear指针向后移一位置， */
								/* 若到最后则转到数组头部 */
	return  OK;
}

/* 若队列不空，则删除Q中队头元素，用e返回其值 */
Status DeQueue(Queue *Q,int *e)
{
	if (Q->front == Q->rear)			/* 队列空的判断 */
		return ERROR;
	*e=Q->data[Q->front];				/* 将队头元素赋值给e */
	Q->front=(Q->front+1)%MAXSIZE;	/* front指针向后移一位置， */
									/* 若到最后则转到数组头部 */
	return  OK;
}
/* ****************************************************** */

void CreateMGraph(MGraph *G, VertexType *Node_Names, int Node_num, int Edge_num)
{
    int i, j, Edge_one, Edge_tow, Node_weight=1;
    VertexType Node_name;       //定义结点名称
    printf("Please input the Node names:");
    //scanf("%d %d", &G->Node_num, &G->Edge_num);
    //VertexType Node_Names[10];     //存取各节点的名称
    //gets(Node_Names);
    G->Node_num = Node_num;
    G->Edge_num = Edge_num;

    printf("\nPlease input Node's name (%d times): \n", G->Node_num);
    for(i=0; i<G->Node_num; i++)
        {G->vexs[i] = Node_Names[i];}

    for(i=0; i<G->Node_num; i++)
        for(j=0; j<G->Node_num; j++)
            if(i == j)
                G->arc[i][j] = 0;
            else
                G->arc[i][j] = INFINITY;

    printf("Please input Node's Edge and its Weight (like: 3-5-weight):\n");
    for(i=0; i<G->Edge_num; i++)
    {
        scanf("%d-%d-%d", &Edge_one, &Edge_tow, &Node_weight);
        G->arc[Edge_one][Edge_tow] = Node_weight;
        G->arc[Edge_tow][Edge_one] = G->arc[Edge_one][Edge_tow];     //无向图对称
    }
}
void DisplayGraph(MGraph G)
{
    int i, j;
    for(i=-1; i<G.Node_num; i++)
    {
        for(j=-1; j<G.Node_num; j++)
        {
            if(i==-1 && j==-1)
                printf("0\t");
            else if(i==-1)
                printf("%c\t", G.vexs[j]);
            else if(j==-1)
                printf("%c\t", G.vexs[i]);
            else
            {
                if(G.arc[i][j] == INFINITY)
                    printf("∞\t");
                else
                    printf("%d\t", G.arc[i][j]);
            }
        }
        printf("\n");
    }
}

Boolean visited[MAXVEX];    //建立遍历数组 大小为最大顶点数

//深度优先递归算法
void DFS(MGraph G, int i)
{
    int j;
    visited[i] = TRUE;      //结点标记访问
    printf("%c\t", G.vexs[i]);
    for(j=0; j<G.Node_num; j++)
        if(!visited[j] && G.arc[i][j] != INFINITY)
        //若下一个与此节点相邻的节点未被遍历过 or 两个节点的边不为无限大 则递归执行深度优先遍历
            DFS(G, j);
}

//深度优先遍历
void DFS_Traverse(MGraph G)
{
    int i;
    for(i=0; i<G.Node_num; i++)
        visited[i] = FALSE;     //结点标志未被遍历
    for(i=0; i<G.Node_num; i++)
        if(!visited[i])     //若遍历数组中的节点未被访问过 则执行深度优先递归
            DFS(G, i);
}

//广度优先遍历算法
void BFS_Traverse(MGraph G)
{
    Queue Q;    //节点遍历队列
    int i, j;

    for(i=0; i<G.Node_num; i++)
        visited[i] = FALSE;     //标记未访问
    InitQueue(&Q);      //初始化队列
    for(i=0; i<G.Node_num; i++)
    {
        if(!visited[i]) //若结点未被访问过 则执行下列操作
        {
            visited[i] = TRUE;  //标记访问标记
            printf("%c\t", G.vexs[i]);  //打印结点
            EnQueue(&Q, i);  //结点入栈
            while(!QueueEmpty(Q))   //若队列非空
            {
                DeQueue(&Q, &i);     //队列出队
                for(j=0; j<G.Node_num; j++)
                {   //若结点未被访问过 并且两结点的边不为无限大(既有边存在)
                    if(G.arc[i][j] != INFINITY && !visited[j])
                    {
                        visited[j] = TRUE;  //标记访问
                        printf("%c\t", G.vexs[j]);
                        EnQueue(&Q, j);     //结点入队
                    }
                }
            }
        }
    }
}

int main()
{

    MGraph G;   //定义一个图
    int Node_num, Edge_num;     //定义顶点数 边数
    printf("Please input the number of Node and Edge (%d,%d):");
    //scanf("%d,%d", &Node_num, &Edge_num);
    CreateMGraph(&G, "ABCDEFGHI" , 9, 15);   //初始化图
    DisplayGraph(G);

    printf("DFS Traverse:\n");
    DFS_Traverse(G);
    printf("\n");

    printf("BFS Traverse:\n");
    BFS_Traverse(G);
    printf("\n");
    //BFSTraverse(G);
    //MiniSpanTree_Prim(G);
    printf("\n");
    //printf("Hello world!\n");
    return 0;
}
/*
9,14

0-1-10
0-5-11
1-2-18
1-8-12
1-6-16
2-3-22
2-8-8
3-4-20
3-7-16
3-8-21
3-6-24
4-7-7
4-5-26
5-6-17
6-7-19
*/
