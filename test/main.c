#include<stdio.h>
#include<string.h>

#define maxsize 10
/*
typedef struct{
    int data[maxsize];
    int front;//��ͷָ��
    int rear;//��βָ��
}squeue;
void createsqueue(squeue *q){//��ʼ������
    int i;
    int n;
    int count;
    q->front=0;
    q->rear=0;
    printf("��������Ҫ��ӵĸ���:");
    scanf("%d",&count);
    printf("���������Ԫ��:");
    for(i=0;i<=count-1;++i){
        scanf("%d",&n);
        q->rear=q->rear+1;
        q->data[q->rear]=n;
        //printf("%d",q->data[q->rear]);
    }
}
void insertqueue(squeue *q){//����Ԫ��
    int i,e;
    printf("��������Ҫ�����Ԫ��:");
    scanf("%d",&e);
    if((q->rear+1)%maxsize==q->front){//�ж϶����Ƿ�����
        printf("���������޷�����!");
    }
    else{
        q->rear=(q->rear+1)%maxsize;
        q->data[q->rear]=e;

    }
    printf("����ɹ�!");
}

void delectqueue(squeue *q){
    int *e;
    int i;
    if(q->front==q->rear){
        printf("����Ϊ���޷�����!");
    }
    else{
        q->front=(q->front+1)%maxsize;
        *e=&(q->data[q->front]);
        printf("����Ԫ��Ϊ%d\n",e);
        printf("����Ԫ��Ϊ%d\n",*e);
        //free(e);
        printf("��ʱ����Ԫ��Ϊ:");
        for(i=q->front+1;i<=5;i++){
            printf("%d",q->data[i]);
        }
    }
}
void showqueue(squeue q){
    int i;
    int length;
    length=(q.rear-q.front+maxsize)%maxsize;//����г���
    printf("��ʱ���г���Ϊ%d\n",length);
    for(i=q.front;i<=length;i++){
        printf("%d",q.data[i]);
    }
}
int main(){
    squeue q;
    int a;
    printf("****************************************");
    printf("\n1.����һ������");
    printf("\n2.���һ��Ԫ��");
    printf("\n3.ɾ��һ��Ԫ��");
    printf("\n4.��ʾ��ǰ����Ԫ��");
    printf("\n****************************************");
    printf("\n��������Ҫѡ��Ĳ���:");
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
