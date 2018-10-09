#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* ��󶥵�����Ӧ���û����� */
#define MAXSIZE 100
#define INFINITY 65535

typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef char VertexType; /* ��������Ӧ���û�����  */
typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */
typedef int Boolean; /*���������� ֵΪ0 || 1 TRUE or FALSE */

typedef struct
{
    VertexType vexs[MAXVEX];        //��������
    EdgeType arc[MAXVEX][MAXVEX];   //�߼�
    int Node_num, Edge_num;         //������ ����
}MGraph;

/* �õ��Ķ��нṹ�뺯��********************************** */

/* ѭ�����е�˳��洢�ṹ */
typedef struct
{
	int data[MAXVEX];
	int front;    	/* ͷָ�� */
	int rear;		/* βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ�� */
}Queue;

/* ��ʼ��һ���ն���Q */
Status InitQueue(Queue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}

/* ������QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
Status QueueEmpty(Queue Q)
{
	if(Q.front==Q.rear) /* ���пյı�־ */
		return TRUE;
	else
		return FALSE;
}

/* ������δ���������Ԫ��eΪQ�µĶ�βԪ�� */
Status EnQueue(Queue *Q,int e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* ���������ж� */
		return ERROR;
	Q->data[Q->rear]=e;			/* ��Ԫ��e��ֵ����β */
	Q->rear=(Q->rear+1)%MAXSIZE;/* rearָ�������һλ�ã� */
								/* ���������ת������ͷ�� */
	return  OK;
}

/* �����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ */
Status DeQueue(Queue *Q,int *e)
{
	if (Q->front == Q->rear)			/* ���пյ��ж� */
		return ERROR;
	*e=Q->data[Q->front];				/* ����ͷԪ�ظ�ֵ��e */
	Q->front=(Q->front+1)%MAXSIZE;	/* frontָ�������һλ�ã� */
									/* ���������ת������ͷ�� */
	return  OK;
}
/* ****************************************************** */

void CreateMGraph(MGraph *G, VertexType *Node_Names, int Node_num, int Edge_num)
{
    int i, j, Edge_one, Edge_tow, Node_weight=1;
    VertexType Node_name;       //����������
    printf("Please input the Node names:");
    //scanf("%d %d", &G->Node_num, &G->Edge_num);
    //VertexType Node_Names[10];     //��ȡ���ڵ������
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
        G->arc[Edge_tow][Edge_one] = G->arc[Edge_one][Edge_tow];     //����ͼ�Գ�
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
                    printf("��\t");
                else
                    printf("%d\t", G.arc[i][j]);
            }
        }
        printf("\n");
    }
}

Boolean visited[MAXVEX];    //������������ ��СΪ��󶥵���

//������ȵݹ��㷨
void DFS(MGraph G, int i)
{
    int j;
    visited[i] = TRUE;      //����Ƿ���
    printf("%c\t", G.vexs[i]);
    for(j=0; j<G.Node_num; j++)
        if(!visited[j] && G.arc[i][j] != INFINITY)
        //����һ����˽ڵ����ڵĽڵ�δ�������� or �����ڵ�ı߲�Ϊ���޴� ��ݹ�ִ��������ȱ���
            DFS(G, j);
}

//������ȱ���
void DFS_Traverse(MGraph G)
{
    int i;
    for(i=0; i<G.Node_num; i++)
        visited[i] = FALSE;     //����־δ������
    for(i=0; i<G.Node_num; i++)
        if(!visited[i])     //�����������еĽڵ�δ�����ʹ� ��ִ��������ȵݹ�
            DFS(G, i);
}

//������ȱ����㷨
void BFS_Traverse(MGraph G)
{
    Queue Q;    //�ڵ��������
    int i, j;

    for(i=0; i<G.Node_num; i++)
        visited[i] = FALSE;     //���δ����
    InitQueue(&Q);      //��ʼ������
    for(i=0; i<G.Node_num; i++)
    {
        if(!visited[i]) //�����δ�����ʹ� ��ִ�����в���
        {
            visited[i] = TRUE;  //��Ƿ��ʱ��
            printf("%c\t", G.vexs[i]);  //��ӡ���
            EnQueue(&Q, i);  //�����ջ
            while(!QueueEmpty(Q))   //�����зǿ�
            {
                DeQueue(&Q, &i);     //���г���
                for(j=0; j<G.Node_num; j++)
                {   //�����δ�����ʹ� ���������ı߲�Ϊ���޴�(���бߴ���)
                    if(G.arc[i][j] != INFINITY && !visited[j])
                    {
                        visited[j] = TRUE;  //��Ƿ���
                        printf("%c\t", G.vexs[j]);
                        EnQueue(&Q, j);     //������
                    }
                }
            }
        }
    }
}

int main()
{

    MGraph G;   //����һ��ͼ
    int Node_num, Edge_num;     //���嶥���� ����
    printf("Please input the number of Node and Edge (%d,%d):");
    //scanf("%d,%d", &Node_num, &Edge_num);
    CreateMGraph(&G, "ABCDEFGHI" , 9, 15);   //��ʼ��ͼ
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
