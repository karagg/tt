#include <stdio.h>
#include <stdlib.h>

void start()//提示用户输入的操作信息
{
    printf("               a.判断队列是否为空\n\
               b.插入结点\n\
               c.删除结点\n\
               d.查找数据\n\
               e.判断是否成环\n\
               f.打印当前链表\n\
               g.销毁链表\n\
               i.创建链表\n\
               j.反转链表\n");
}
Status InitList(LinkedList *L)//创建头指针
{
   (*L)=(LinkedList)malloc(sizeof(LNode));
   (*L)->next=NULL;
   printf("函数初始化成功\n");
   return OK;
}
Status IsListNull (LinkedList *L)//判断链表是否为空
{
    if((*L)->next==NULL)
    {
        printf("当前链表为空\n");
    }
    else
    {
        printf("当前链表不为空\n");
    }
    return OK;
}



Status DeleteList(LNode *p, LNode *q)//删除结点
{
  LNode *que,*qur;
  if(p==NULL)
    return ERROR;
  que=p;
  while(que->next!=NULL&&q->data!=que->data)
  {
      qur=que;
      que=que->next;
  }
  if(q->data==que->data)
  {

    qur->next=que->next;
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
 Status InsertList(LinkedList L,ElemType e,int i)//插入结点
 {

     int j;
     LinkedList p,q;
     p=L;
     j=1;
     while(p&&j<i)
     {
         p=p->next;
         j++;
     }
     if(!p||j>i)
     {
         printf("插入不成功\n");
         return ERROR;
     }
     q=(LinkedList)malloc(sizeof(LNode));
     q->data=e;
     q->next=p->next;
     p->next=q;
     printf("插入成功");
     return OK;



 }
 Status SearchList(LinkedList L, ElemType e)//查找数据
 {
    LinkedList k;
    k=L;
    int i;
    i=1;
    if(L==NULL)
    {
        printf("当前链表无数据\n");
        return ERROR;
    }
    while(k!=NULL&&k->data!=e)
    {
        k=k->next;
        i++;
    }
    if(k==NULL)
    {
        printf("没有找到数据\n");
        return ERROR;
    }
    else
    {
        printf("找到数据%d,结点为%d\n",e,i);
        return OK;
    }
 }
 Status IsLoopList(LinkedList L)//判断是否成环
 {
    LinkedList show,fast;
    show=L->next;
    fast=L->next->next;
    while(fast!=NULL&&show!=NULL)
    {
        fast=fast->next->next;
        show=show->next;

            if(fast==show)
            {
                printf("成环\n");
                return OK;
            }
    }
    printf("不成环\n");
    return ERROR;

 }
 Status ReverseList(LinkedList *L)//反转链表
 {
     LinkedList q,p,s,w;
     q=p=(LinkedList)malloc(sizeof(LNode));
     if((*L)->next==NULL)
     {
         printf("当前链表为空，无法反转");
         return ERROR;
     }
     w=*L;
     q=w->next;
     p=q->next;
     s=q;
     while(q!=NULL&&p!=NULL)
     {

        if((*L)->next==q)
        {

            q->next=w;
            w->next=NULL;
        }
        else
        {
           s=q;
           q=p;
           p=p->next;
           q->next=s;
        }
     }
     p=(LinkedList)malloc(sizeof(LNode));
     p->next=q;
     (*L)=p;
     printf("反转成功");
     return OK;


 }
void DestroyList(LinkedList *L)//销毁链表
 {
     LinkedList p,q;
     p=(*L);
     while(p!=NULL)
     {
         q=p->next;
         free(p);
         p=q;

     }
     printf("销毁成功\n");

 }

 void TraverseList(LinkedList L)//打印当前链表
 {
    LinkedList p;
    p=(LinkedList)malloc(sizeof(LNode));
    p=L->next;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
 }
 void creat_list(LinkedList L,ElemType n)
 {
   LNode *p,*q;
   int i;
   p=L;
   for(i=0;i<n;i++)
   {
     q=(LNode*)malloc(sizeof(LNode));
     printf("请输入数据\n");
     scanf("%d",&q->data);
     q->next=NULL;
     p->next=q;
     p=q;
   }
 }
LNode* FindMidNode(LinkedList *L)
{
    LNode *p,*q;
    q=p=(LinkedList)malloc(sizeof(LNode));
    q=(*L)->next;
    p=(*L)->next->next;
    if(q==NULL) printf("没有中间结点");
    if(p==NULL&&q!=NULL) return q;
    if(p!=NULL&&q!=NULL)
    {
      q=(*L)->next;
      p=(*L)->next->next;
    }
    return q;

}
