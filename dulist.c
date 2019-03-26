#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct DuLNode {
	ElemType data;
  	struct DuLNode *prior,  *next;
} DuLNode, *DuLinkedList;

typedef enum Status {
	ERROR,
	OK,
} Status;
void start()
{
    printf("a.创建链表\nb.前插结点\nc.后插结点\nd.删除结点\ne.打印当前链表\nf.销毁链表\ng.退出程序\n");
}
Status InitList_DuL(DuLinkedList *L)
{
   (*L)=(DuLinkedList)malloc(sizeof(DuLNode));
   (*L)->next=NULL;
   (*L)->prior=NULL;
   printf("链表初始化成功\n");
   return OK;
}

void DestroyList_DuL(DuLinkedList *L)//销毁链表
 {
     DuLinkedList p,q;
     p=((*L)->next);
     while(p!=NULL)
     {
         q=p->next;
         free(p);
         p=q;

     }
     (*L)->next=NULL;
     printf("销毁成功\n");

 }

Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)//前插结点
{

    printf("请输入需要前插的结点位置以及所插入的数据");
    ElemType local;
    scanf("%d,%d",&local,&q->data);
    int i=1,j=0;
    DuLNode *t;
    t=p->next;
    while(t)
    {
        t=t->next;
        j++;
    }
    if(local>j)
    {
        printf("该前插结点不存在的");
        return ERROR;
    }
    t=p->next;
    for(;t!=NULL&&i<local;i++)
    {
       t=t->next;
    }
    q->next=t;
    q->prior=t->prior;
    t->prior->next=q;
    t->prior=q;
    printf("插入成功");
    return OK;
}
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)//后插结点
{
    printf("请输入需要后插的结点位置以及所插入的数据");
    ElemType local;
    scanf("%d,%d",&local,&q->data);
    int i=1,j=0;
    DuLNode *t;
    t=p->next;
    while(t)
    {
        t=t->next;
        j++;
    }
    if(local>j)
    {
        printf("该后插结点不存在的");
        return ERROR;
    }
    t=p->next;
    for(;t!=NULL&&i<local;i++)
    {
       t=t->next;
    }
    q->next=t->next;
    q->prior=t;
    if(local<j)
    {
      t->next->prior=q;
    }
    t->next=q;
    printf("插入成功");
    return OK;
}
Status DeleteList_DuL(DuLNode *p, ElemType *e)//删除结点
{
  DuLNode *que,*qur;
  que=p;
  while(que->next!=NULL&&(*e)!=que->data)
  {
      qur=que;
      que=que->next;
  }
  if((*e)==que->data)
  {
    if(que->next==NULL)
    {
        qur->next=NULL;
    }
    else
    {qur->next=que->next;
    que->next->prior=qur;}
    free(que);
    printf("删除成功\n");
    return OK;
  }
  else
  {
    printf("删除失败\n");
    return ERROR;
  }
}

void TraverseList(DuLinkedList L)//打印当前链表
 {
    DuLinkedList p;
    p=(DuLinkedList)malloc(sizeof(DuLNode));
    p=L->next;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
 }
 void creat_list(DuLinkedList L,ElemType n)//创建链表
 {
   DuLNode *p,*q;
   int i;
   p=L;
   for(i=0;i<n;i++)
   {
     q=(DuLNode*)malloc(sizeof(DuLNode));
     p->next=q;
     printf("请输入数据\n");
     scanf("%d",&q->data);
     q->prior=p;
     q->next=NULL;
     p=q;
   }
 }
int main()
{
    int p;
    p=1;
    DuLinkedList L;
    InitList_DuL(&L);
    while(p)
    {

        start();
        printf("请输入操作");
        char operate;
        scanf("%c",&operate);
        switch(operate)
        {
            case'a':{printf("请输入数据的个数");ElemType e;scanf("%d",&e);creat_list(L,e);break;}
            case'b':{DuLNode *q;q=(DuLNode *)malloc(sizeof(DuLNode));InsertBeforeList_DuL(L,q);break;}
            case'c':{DuLNode *q;q=(DuLNode *)malloc(sizeof(DuLNode));InsertAfterList_DuL(L,q);break;}
            case'd':{ElemType e;printf("请输入要删除的数据");scanf("%d",&e);DeleteList_DuL(L,&e);break;}
            case'e':TraverseList(L);break;
            case'f':DestroyList_DuL(&L);break;
            case'g':p=0;break;
            default:printf("输入不正确\n");
        }
        fflush(stdin);
    }
    return 0;
}

