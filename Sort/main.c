#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

typedef struct
{
    int r[MAXSIZE+1];   //r[0] �����ڱ� ����ʱ����
    int length;
}SqList;

void swap(SqList *L, int i, int j)
{
    int temp=L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

void Init_Arr(SqList *L, int d[])
{
    int i;
    for(i=0; i<L->length; i++)
        L->r[i+1] = d[i];
    printf("Initialize Done\n");
}

void show(char *Str, SqList L)
{
    int i;
    puts(Str);
    for(i=1; i<=L.length; i++)
        printf("%d\t", L.r[i]);
    printf("\n\n");
}

//��˳�����н������� ð������
void BubbleSort0(SqList *L)
{
    int i, j;
    for(i=1; i<L->length; i++)
    {
        for(j=i+1; j<=L->length; j++)
            if(L->r[i] > L->r[j])
                swap(L, i, j);
    }
}

void BubbleSort1(SqList *L)//
{
    int i, j;
    for(i=1; i<L->length; i++)
    {
        for(j=L->length-1; j>=i;j--)
            //printf("%d, %d\n", j, j+1);
        {
            if(L->r[j]>L->r[j+1])
                swap(L, j, j+1);
        }
    }
}

void BubbleSort2(SqList *L)
{
    int i, j;
    Status flag=TRUE;
    for(i=1; i<L->length && flag; i++)
    {
        flag = FALSE;
        for(j=L->length-1; j>=i; j--)
            if(L->r[j] > L->r[j+1])
            {
                swap(L, j, j+1);
                flag = TRUE;
            }
    }
}

//��ѡ������
void SelectSort(SqList *L)
{
    int i, j, min;  //minΪ��С�ؼ��ֵ��±�
    for(i=1; i<L->length;i++)
    {
        min = i;
        for(j=i+1; j<=L->length; j++)
        {
            if(L->r[min] > L->r[j])     //˵����һ����min�ؼ���С ����
                min = j;    //�ҵ���С�ؼ����±� ����
        }
        if(i != min)    //���ҵ�����С�ؼ����±� ���ʼ�±겻һ�� �򽻻� ���򱣳ּ���
            swap(L, i, min);
    }
}

//ֱ�Ӳ�������
void InsertSort(SqList *L)
{
    int i, j;
    for(i=2; i<=L->length; i++)
    {
        if(L->r[i] < L->r[i-1])     //��������ʼ
        {
            L->r[0] = L->r[i];       //�����ڱ�
            for(j=i-1; L->r[j]>L->r[0]; j--)//������ǰ��Ĺؼ��ֱȲ���ֵ�� ��������
                L->r[j+1] = L->r[j]; //˳�����
            L->r[j+1] = L->r[0];    //ֵ����
        }
    }
}

void ShellSort(SqList *L)
{
    int temp, gap, i;
    for(gap=L->length/2; gap>0; gap/=2)
    {
        for(i=gap; i<=L->length; i++)
        {
            printf("%d\t", i);
            L->r[0] = L->r[i];     //�����ڱ� ����ÿһ�����ֵĹؼ���
            int j;
            for(j=i; j>=gap && L->r[j-gap]>L->r[0]; j-=gap)
                L->r[j] = L->r[j-gap];//�����ֹؼ��ֱȵ�ǰС �򽻻�Ԫ��
            L->r[j] = L->r[0];
        }
        printf("\n");
    }
}


int main()
{
    SqList L;
    int d[9]={9,1,5,8,3,7,4,6,2};
    Init_Arr(&L, d);

    show("Origin Array", L);

//    BubbleSort0(&L);
//    show("BubbleSort_0", L);
//    BubbleSort(&L);
//    show("BubbleSort", L);
//    BubbleSort2(&L);
//    show("BubbleSort2", L);

//    SelectSort(&L);
//    show("SelectSort", L);

//    InsertSort(&L);
//    show("InsertSort", L);
    ShellSort(&L);
    show("ShellSort", L);

    return 0;
}
