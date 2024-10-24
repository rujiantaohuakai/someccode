#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;
void CreateList_R(LinkList &L,int n)
{//后插法创建单链表
    L=new LNode;
    L->next=NULL;
    LinkList r=L;
    for(int i=0;i<n;i++)
    {
        LinkList p=new LNode;
        cin>>p->data;
        p->next=NULL;
        r->next=p;
        r=p;
    }
}
void PrintList(LinkList &L)
{//打印依次输出链表中的数据
    L=L->next;
    while(L){
        if(L->next!=NULL) cout<<L->data<<" ";
        else cout<<L->data;
        L=L->next;
    }
    cout<<endl;
}
void Decompose(LinkList &LA,LinkList &LB,LinkList &LC)
{//链表的分解
/**************begin************/
  LB = new LNode;
  LC = new LNode;
  LB->next = NULL;
  LC->next = NULL;
  LNode *pa = LA->next;
  LNode *preva = LA;
  LNode *btail = LB;
  LNode *ctail = LC;
  while(pa)
  {
    if(pa->data < 0)
    {
        preva->next = pa->next;
        pa->next = btail->next;
        btail->next = pa;
        btail = pa;
        pa = preva->next;
    }
    else
    {
        preva->next = pa->next;
        pa->next = ctail->next;
        ctail->next = pa;
        ctail = pa;
        pa = preva->next;
    }
  }
    /**************end************/
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        LinkList LA,LB,LC;
        CreateList_R(LA,n);
        Decompose(LA,LB,LC);
        PrintList(LB);
        PrintList(LC);
    }
    return 0;
}