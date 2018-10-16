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

typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */

typedef struct
{
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph *G)/* ����ͼ */
{
	int i, j;

	/* printf("����������Ͷ�����:"); */
	G->numEdges=15;
	G->numVertexes=9;

	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
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

/* Prim�㷨������С������  */
void MiniSpanTree_Prim(MGraph G, int Start_Node_num)
{
    if(Start_Node_num>=G.numVertexes || Start_Node_num<0)
    {
        printf("Illegal Start_Node_num with %d", Start_Node_num);return;
    }

    printf("Prim Algorithm with Start_Node_number is %d\n", Start_Node_num);
	int i, j, min;
	int Mini_Edge_Node_num;     //��¼���������±�
	int Node_Record[G.numVertexes];     //�����¼��
	int Edge_Record[G.numVertexes];     //Ȩֵ��¼��
	if(Start_Node_num <= G.numVertexes && Start_Node_num >= 0)
	{//��ʼ����
	    for(i=0; i<G.numVertexes; i++)
        {
            if(i!=Start_Node_num)
            {
                Node_Record[i] = Start_Node_num;     //���ʼ���Ϊ 0 �ȴ�0�Ž�㿪ʼ����������С��
                Edge_Record[i] = G.arc[Start_Node_num][i];//����ʼ������е�Ȩֵ
            }
        }
    }
    for(i=0; i<G.numVertexes; i++)
    {
        if(i!=Start_Node_num)
        {//������ʼ���
            min = INFINITY; //��ʼ��СȨֵΪ���޴�
            j = 0;          //ѭ����������
            Mini_Edge_Node_num = Start_Node_num;    //��ʼ���ڽ����λ��ΪStart
            while(j<G.numVertexes)
            {//�������н��
                if(Edge_Record[j]!=0 && Edge_Record[j] < min)   //�ж�Ȩֵ��Ϊ0��ȨֵС��min
                {
                    min = Edge_Record[j];       //����Ȩֵ
                    Mini_Edge_Node_num = j;     //�ҵ����ڽ��Ľ���±�
                }
                j++;
            }
            printf("(%d - %d)\n", Node_Record[Mini_Edge_Node_num], Mini_Edge_Node_num);
            Edge_Record[Mini_Edge_Node_num] = 0;    //�˽������ɱ���, mark
            for(j=0; j<G.numVertexes; j++)
            {
                if(j!=Start_Node_num)
                {
                    if(Edge_Record[j]!=0 && G.arc[Mini_Edge_Node_num][j] < Edge_Record[j])
                    {//����±�Ϊk�������ȨֵС�ڴ�ǰ��Щ����δ������������Ȩֵ
                        Edge_Record[j] = G.arc[Mini_Edge_Node_num][j];
                        Node_Record[j] = Mini_Edge_Node_num;        //�ҵ������ڽ�����бߵĽ��
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
