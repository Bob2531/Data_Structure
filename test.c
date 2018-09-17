#include<stdio.h>
#define maxsize 100
typedef struct LNode{
    int data;//数据域
    struct LNode *next//指针域
}LNode,*linklist;
void creatlist(linklist* L){
    int i,n,j;//头插法建表(顺序创建链表)
    int x;
    linklist *p;
    (*L)=(linklist)malloc(sizeof(LNode));//建立头节点
    (*L)->next=NULL;//初始表为空
    //带头节点的单链表
    printf("请输入需要创建的元素个数:");
    scanf("%d",&n);
   // printf("44444444444444\n");
    printf("请依次输入元素:");
    //printf("3333333333333\n");
    for(i=n;i>0;--i){
            // printf("11111111111111\n");
        (*p)=(linklist)malloc(sizeof(LNode));//生成新节点
    // printf("222222222222\n");
         scanf("%d",&x);//输入新节点中元素的值
        (*p)->data=x;
        (*p)->next=(*L)->next;
        (*L)->next=(*p);//插入到表头
    }

}
/*void findlist(linklist L){
    int i;
    int j=0;//计数
    printf("请输入需要查找的元素的序号:");
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
    printf("1.创建表\n");
    printf("2.显示\n");
    printf("3.查找\n");
    printf("4.插入\n");
    printf("5.删除\n");
    printf("************************\n");
     printf("请输入需要的操作:");
    while(scanf("%d",&a)!=EOF){
        if(a==1){
            creatlist(&L);
        }
        else if(a==2){
            display(L);
        }
    }
}
