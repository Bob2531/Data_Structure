#include<stdio.h>
#include<string.h>

#define maxsize 10
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
