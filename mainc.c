
LNode* FindMidNode(LinkedList *L)
{
    LNode *p,*q;
    p=q=(*L);
    if(p!=NULL&&p->next!=NULL)
    {
      q=q->next;
      p=p->next->next;
    }
    return q;
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
Status IsLoopList(LinkedList L)//判断是否成环
 {
    LinkedList show,fast;
    show=L;
    fast=L;
    while(fast!=NULL&&show!=NULL)
    {
        fast=fast->next->next;
        show=show->next;

            if(fast==show&&show!=NULL)
            {
                printf("成环\n");
                return OK;
            }
    }
    printf("不成环\n");
    return ERROR;

 }
 主函数编码：LNode *q,q=(LNode*)malloc(sizeof(LNode));DeleteList(L,q);break;
Status DeleteList(LNode *p, LNode *q)//删除结点
{
  printf("输入所要删除的数据");
  scanf("%d",&q->data);
  LNode *que,*qur;
  if(p==NULL)
    {
        printf("链表为空");
        return ERROR;
    }
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
