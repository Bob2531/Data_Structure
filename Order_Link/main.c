#include<stdio.h>
#define MAXSIZE 20 //定义线性表的最大长度
#define InitSize 100 //表长度的初始定义
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;

typedef struct //定义顺序表结构体
{
    ElemType data[MAXSIZE]; //顺序表元素
    int length;             //顺序表长度
}SqList;

//初始化顺序表
Status InitList(SqList *L)
{
    L->length = 0;   //将顺序表的长度赋值为0
    return OK;
}

//取顺序表中第i个元素的值
Status GetLlem(SqList L,int i, ElemType *e)
{
    //先作判断:
    //如果表长为0 || 位置小于1 || 位置大于表长
    //则获取失败
    if (L.length<0 || i<1 || i>L.length)
        return ERROR;
    //获取第i个位置的值,对应数组中就是i-1的位置
    *e = L.data[i-1];
    return OK;
}

//插入操作
Status ListInsert(SqList *L, int i, ElemType e)
{
    int position;   //定义插入位置
//  插入时先进行判断
//  若顺序表长度==MAXSIZE 表示线性表已满 不能插入
    if(L->length==MAXSIZE)
    {
        printf("List full, insert fail\n");
        return ERROR;
    }
//  若插入位置   i<0 位置非法
//               i>length+1 位置越界    不能插入
    if(i<1 || i>L->length+1)
    {
        printf("Illegal position i\n");
        return ERROR;
    }
//  若i<length 表示插入元素不在表尾
    if(i<L->length)
    {
        //顺位后移
        for(position=L->length-1; position>i-1; position--)
            L->data[position+1] = L->data[position];  //数据后移
    }
    L->data[i-1] = e;   //数据传入数组第i-1的位置
    L->length++;            //顺序表长度加一
    printf("Data %d has been Inserted\n", e);
    return OK;
}

//顺序表删除操作
Status ListDelete(SqList *L, int i, ElemType *e)
{
    int position;
    //判断顺序表是否为空
    if(L->length == 0)
    {
        printf("List is empty, delete fail\n");
        return ERROR;
    }
    //判断i的位置是否合法
        //若i<0 || i>length+1 非法
    if(i<1 || i>L->length)
    {
        printf("Illegal position i\n");
        return ERROR;
    }
    //返回位置i的数据
    *e = L->data[i-1];

    if(i<L->length)
    {
        for(position=i; position<L->length; position++)
            L->data[position-1] = L->data[position];//顺序前移动
//        for(position=L->length; position<i; position--)
//            L->data[position-2] = L->data[position-1];//顺序前移动
    }
    L->length--;
    return OK;
}

//顺序表的显示
void ListShow(SqList L)
{
    int position;
    printf("\n---------Display List---------\n");
    for(position=0; position<L.length; position++)
        printf("%d  ", L.data[position]);
    printf("\n---------Display Done---------\n");
}

//得到位置i的元素
Status GetElem(SqList L, int i)
{
    //判断i的位置是否合法
    if(i<1 || i>L.length)
    {
        printf("Illegal position i\n");
        return ERROR;
    }
    else
    {
        printf("\n---------GetElem---------");
        printf("\nGet Data[%d] is %d\n", i, L.data[i-1]);
        printf("---------GetElem---------\n");
    }
    return OK;
}

//定位顺序表中的元素
Status LocateElem(SqList L, int e)
{
    printf("\n---------LocatElem---------\n");
    int position;
    for(position=0; position<L.length;position++)
    {
        if(e == L.data[position])
        {
            printf("data[%d]'s location is %d\n", L.data[position], position);
            printf("---------LocatElem---------\n");
            return OK;
        }
    }
    printf("Missing Data\n");
    printf("---------LocatElem---------\n");
    return ERROR;
}

//顺序表长度
ElemType ListLength(SqList L)
{
    return L.length;
}

int main()
{
    SqList L;   //初始化顺序表
    InitList(&L);   //顺序表长度赋值为0
    int length;

    int i;
    int del_num; //定义被删除变量
    for(i=1; i<13; i++)
    {
        ListInsert(&L, i, i);
    }
    for(i=8; i>4; i--)
    {
        ListDelete(&L, i, &del_num);
        printf("\ndata %d has been deleted", del_num);
    }
    GetElem(L, 5);
    LocateElem(L, 10);
    ListShow(L);

    length = ListLength(L);
    printf("\nList length is %d\n", length);
    return 0;
}
