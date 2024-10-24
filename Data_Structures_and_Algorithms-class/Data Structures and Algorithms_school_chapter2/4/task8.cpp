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

void Inverse(LinkList &L)
{//逆置带头结点的单链表L
/**************begin************/
    LinkList inverse = new LNode;
    inverse->next = NULL;
    LNode *p = L->next;
    while(p)
    {
        L->next = p->next;
        p->next = inverse->next;
        inverse->next = p;
        p = L->next;
    }

    delete L;
    L = inverse;
    /**************end************/
}

void PrintList(LinkList &L)
{
    L=L->next;
    while(L){
        if(L->next!=NULL) cout<<L->data<<" ";
        else cout<<L->data;
        L=L->next;
    }
    cout<<endl;
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        LinkList L=new LNode;
        CreateList_R(L,n);
        Inverse(L);
        PrintList(L);
    }
    return 0;
}