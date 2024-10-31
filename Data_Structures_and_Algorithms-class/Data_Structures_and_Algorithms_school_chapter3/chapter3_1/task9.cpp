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
int GetMax(LinkList L)
{//递归求解单链表中的最大值
    /**************begin************/
    if(L == NULL) return -1;
    int maxelem = max(L->data, GetMax(L->next));
    return maxelem;
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
        L=L->next;    //指向首元结点
        cout<<GetMax(L)<<endl;
    }
    return 0;
}