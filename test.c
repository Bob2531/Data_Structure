#include<stdio.h>
#define maxsize 100
typedef struct LNode{
    int data;//������
    struct LNode *next//ָ����
}LNode,*linklist;
void creatlist(linklist* L){
    int i,n,j;//ͷ�巨����(˳�򴴽�����)
    int x;
    linklist *p;
    (*L)=(linklist)malloc(sizeof(LNode));//����ͷ�ڵ�
    (*L)->next=NULL;//��ʼ��Ϊ��
    //��ͷ�ڵ�ĵ�����
    printf("��������Ҫ������Ԫ�ظ���:");
    scanf("%d",&n);
   // printf("44444444444444\n");
    printf("����������Ԫ��:");
    //printf("3333333333333\n");
    for(i=n;i>0;--i){
            // printf("11111111111111\n");
        (*p)=(linklist)malloc(sizeof(LNode));//�����½ڵ�
    // printf("222222222222\n");
         scanf("%d",&x);//�����½ڵ���Ԫ�ص�ֵ
        (*p)->data=x;
        (*p)->next=(*L)->next;
        (*L)->next=(*p);//���뵽��ͷ
    }

}
/*void findlist(linklist L){
    int i;
    int j=0;//����
    printf("��������Ҫ���ҵ�Ԫ�ص����:");
    scanf("%d",i);
    linklist p=L->next;
    while(j<=i){
        p=p->next;
        j++;
    }
    printf("%d",p);
}*/
void display(linklist L){

    linklist p;
    p=L->next;
    while(p!=NULL){
       printf("%d",p->data);
       p = p->next;
    }
}
int main(){
    int a;
    linklist L;
   // creatlist(&L);
    printf("************************\n");
    printf("1.������\n");
    printf("2.��ʾ\n");
    printf("3.����\n");
    printf("4.����\n");
    printf("5.ɾ��\n");
    printf("************************\n");
     printf("��������Ҫ�Ĳ���:");
    while(scanf("%d",&a)!=EOF){
        if(a==1){
            creatlist(&L);
        }
        else if(a==2){
            display(L);
        }
    }
}
