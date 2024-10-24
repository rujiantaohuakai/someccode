#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;

void CreateList_R(LinkList &L,int n)
{
    L->next=NULL;
    LinkList r=new LNode;
    r=L;
    for(int i=0;i<n;i++)
    {
        LinkList p=new LNode;
        cin>>p->data;
        p->next=NULL;
        r->next=p;
        r=p;
    }
}

int MaxData(LinkList L)
{//确定单链表中值最大的结点
/**************begin************/
    int maxdata = L->next->data;
    LNode *p = L->next->next;
    while(p)
    {
        if(p->data > maxdata)
            maxdata = p->data;
        p = p->next;
    }
    
    return maxdata;
    /**************end************/
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        LinkList L=new LNode;
        CreateList_R(L,n);
        cout<<MaxData(L)<<endl;
    }
    return 0;
}