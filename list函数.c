#include <stdio.h>
#include <stdlib.h>

void start()//��ʾ�û�����Ĳ�����Ϣ
{
    printf("               a.�ж϶����Ƿ�Ϊ��\n\
               b.������\n\
               c.ɾ�����\n\
               d.��������\n\
               e.�ж��Ƿ�ɻ�\n\
               f.��ӡ��ǰ����\n\
               g.��������\n\
               i.��������\n\
               j.��ת����\n");
}
Status InitList(LinkedList *L)//����ͷָ��
{
   (*L)=(LinkedList)malloc(sizeof(LNode));
   (*L)->next=NULL;
   printf("������ʼ���ɹ�\n");
   return OK;
}
Status IsListNull (LinkedList *L)//�ж������Ƿ�Ϊ��
{
    if((*L)->next==NULL)
    {
        printf("��ǰ����Ϊ��\n");
    }
    else
    {
        printf("��ǰ����Ϊ��\n");
    }
    return OK;
}



Status DeleteList(LNode *p, LNode *q)//ɾ�����
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
    printf("ɾ���ɹ�\n");
    return OK;
  }
  else
  {
    printf("ɾ��ʧ��\n");
    return ERROR;
  }


}
 Status InsertList(LinkedList L,ElemType e,int i)//������
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
         printf("���벻�ɹ�\n");
         return ERROR;
     }
     q=(LinkedList)malloc(sizeof(LNode));
     q->data=e;
     q->next=p->next;
     p->next=q;
     printf("����ɹ�");
     return OK;



 }
 Status SearchList(LinkedList L, ElemType e)//��������
 {
    LinkedList k;
    k=L;
    int i;
    i=1;
    if(L==NULL)
    {
        printf("��ǰ����������\n");
        return ERROR;
    }
    while(k!=NULL&&k->data!=e)
    {
        k=k->next;
        i++;
    }
    if(k==NULL)
    {
        printf("û���ҵ�����\n");
        return ERROR;
    }
    else
    {
        printf("�ҵ�����%d,���Ϊ%d\n",e,i);
        return OK;
    }
 }
 Status IsLoopList(LinkedList L)//�ж��Ƿ�ɻ�
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
                printf("�ɻ�\n");
                return OK;
            }
    }
    printf("���ɻ�\n");
    return ERROR;

 }
 Status ReverseList(LinkedList *L)//��ת����
 {
     LinkedList q,p,s,w;
     q=p=(LinkedList)malloc(sizeof(LNode));
     if((*L)->next==NULL)
     {
         printf("��ǰ����Ϊ�գ��޷���ת");
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
     printf("��ת�ɹ�");
     return OK;


 }
void DestroyList(LinkedList *L)//��������
 {
     LinkedList p,q;
     p=(*L);
     while(p!=NULL)
     {
         q=p->next;
         free(p);
         p=q;

     }
     printf("���ٳɹ�\n");

 }

 void TraverseList(LinkedList L)//��ӡ��ǰ����
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
     printf("����������\n");
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
    if(q==NULL) printf("û���м���");
    if(p==NULL&&q!=NULL) return q;
    if(p!=NULL&&q!=NULL)
    {
      q=(*L)->next;
      p=(*L)->next->next;
    }
    return q;

}
