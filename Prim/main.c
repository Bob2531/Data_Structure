#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */

typedef struct
{
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph *G)/* 构件图 */
{
	int i, j;

	/* printf("请输入边数和顶点数:"); */
	G->numEdges=15;
	G->numVertexes=9;

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		for ( j = 0; j < G->numVertexes; j++)
		{
			if (i==j)
				G->arc[i][j]=0;
			else
				G->arc[i][j] = G->arc[j][i] = INFINITY;
		}
	}

	G->arc[0][1]=10;
	G->arc[0][5]=11;
	G->arc[1][2]=18;
	G->arc[1][8]=12;
	G->arc[1][6]=16;
	G->arc[2][8]=8;
	G->arc[2][3]=22;
	G->arc[3][8]=21;
	G->arc[3][6]=24;
	G->arc[3][7]=16;
	G->arc[3][4]=20;
	G->arc[4][7]=7;
	G->arc[4][5]=26;
	G->arc[5][6]=17;
	G->arc[6][7]=19;

	for(i = 0; i < G->numVertexes; i++)
	{
		for(j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] =G->arc[i][j];
		}
	}
}

/* Prim算法生成最小生成树  */
void MiniSpanTree_Prim(MGraph G, int Start_Node_num)
{
    if(Start_Node_num>=G.numVertexes || Start_Node_num<0)
    {
        printf("Illegal Start_Node_num with %d", Start_Node_num);return;
    }

    printf("Prim Algorithm with Start_Node_number is %d\n", Start_Node_num);
	int i, j, min;
	int Mini_Edge_Node_num;     //记录最近顶点的下标
	int Node_Record[G.numVertexes];     //顶点记录表
	int Edge_Record[G.numVertexes];     //权值记录表
	if(Start_Node_num <= G.numVertexes && Start_Node_num >= 0)
	{//初始工作
	    for(i=0; i<G.numVertexes; i++)
        {
            if(i!=Start_Node_num)
            {
                Node_Record[i] = Start_Node_num;     //令初始结点为 0 既从0号结点开始遍历生成最小树
                Edge_Record[i] = G.arc[Start_Node_num][i];//赋初始结点所有的权值
            }
        }
    }
    for(i=0; i<G.numVertexes; i++)
    {
        if(i!=Start_Node_num)
        {//跳过初始结点
            min = INFINITY; //初始最小权值为无限大
            j = 0;          //循环遍历变量
            Mini_Edge_Node_num = Start_Node_num;    //初始最邻近结点位置为Start
            while(j<G.numVertexes)
            {//遍历所有结点
                if(Edge_Record[j]!=0 && Edge_Record[j] < min)   //判断权值不为0且权值小于min
                {
                    min = Edge_Record[j];       //更新权值
                    Mini_Edge_Node_num = j;     //找到最邻近的结点下标
                }
                j++;
            }
            printf("(%d - %d)\n", Node_Record[Mini_Edge_Node_num], Mini_Edge_Node_num);
            Edge_Record[Mini_Edge_Node_num] = 0;    //此结点已完成遍历, mark
            for(j=0; j<G.numVertexes; j++)
            {
                if(j!=Start_Node_num)
                {
                    if(Edge_Record[j]!=0 && G.arc[Mini_Edge_Node_num][j] < Edge_Record[j])
                    {//如果下标为k顶点各边权值小于此前这些顶点未被加入生成树权值
                        Edge_Record[j] = G.arc[Mini_Edge_Node_num][j];
                        Node_Record[j] = Mini_Edge_Node_num;        //找到与最邻近结点有边的结点
                    }
                }
            }
        }
    }
}

int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	MiniSpanTree_Prim(G, 8);

	return 0;
}
