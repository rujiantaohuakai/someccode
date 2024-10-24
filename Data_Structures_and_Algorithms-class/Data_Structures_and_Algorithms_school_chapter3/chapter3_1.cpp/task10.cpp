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
int GetLength(LinkList L)
{//递归求解单链表中的结点个数
/**************begin************/
    if(L == NULL) return 0;
    return 1 + GetLength(L->next);

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
        L=L->next;    //L指向首元结点
        cout<<GetLength(L)<<endl;
    }
    return 0;
}