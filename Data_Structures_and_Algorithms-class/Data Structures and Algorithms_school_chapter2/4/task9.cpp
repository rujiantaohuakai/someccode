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
void DeleteMinMax(LinkList &L,int mink,int maxk)
{//删除链表中满足区间值的结点
/**************begin************/
    LNode *p = L->next;
    LNode *prev = L;
    while(p)
    {
        if(p->data <= maxk && p->data >= mink)
        {
            prev->next = p->next;
            delete p;
            p = prev->next;
        }
        else
        {
            p = p->next;
            prev = prev->next;
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
        LinkList L;
        CreateList_R(L,n);
        int mink,maxk;
        cin>>mink>>maxk;
        DeleteMinMax(L,mink,maxk);
        PrintList(L);
    }
    return 0;
}