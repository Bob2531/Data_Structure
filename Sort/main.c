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
    int r[MAXSIZE+1];   //r[0] 设置哨兵 或临时变量
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

//对顺序表进行交换排序 冒泡排序
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

//简单选择排序
void SelectSort(SqList *L)
{
    int i, j, min;  //min为最小关键字的下标
    for(i=1; i<L->length;i++)
    {
        min = i;
        for(j=i+1; j<=L->length; j++)
        {
            if(L->r[min] > L->r[j])     //说明下一个比min关键字小 交换
                min = j;    //找到最小关键字下标 更新
        }
        if(i != min)    //若找到的最小关键字下标 与初始下标不一样 则交换 否则保持即可
            swap(L, i, min);
    }
}

//直接插入排序
void InsertSort(SqList *L)
{
    int i, j;
    for(i=2; i<=L->length; i++)
    {
        if(L->r[i] < L->r[i-1])     //插入排序开始
        {
            L->r[0] = L->r[i];       //设置哨兵
            for(j=i-1; L->r[j]>L->r[0]; j--)//若发现前面的关键字比插入值大 则发生交换
                L->r[j+1] = L->r[j]; //顺序后移
            L->r[j+1] = L->r[0];    //值插入
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
            L->r[0] = L->r[i];     //设置哨兵 储存每一个部分的关键字
            int j;
            for(j=i; j>=gap && L->r[j-gap]>L->r[0]; j-=gap)
                L->r[j] = L->r[j-gap];//若发现关键字比当前小 则交换元素
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
