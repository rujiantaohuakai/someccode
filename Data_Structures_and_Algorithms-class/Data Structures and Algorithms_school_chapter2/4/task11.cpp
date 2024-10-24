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
void Search_k(LinkList L,int k)
{
    /**************begin************/
    //要求时间复杂度为O(n)空间复杂度为O(1)
    //思路：先求长度再遍历找到第len-k+1个元素,就是倒数第k个元素
    int len = 0;
    LNode *p = L->next;
    while(p)
    {
        len++;
        p = p->next;
    }

    p = L;
    len = len-k+1;
    while(len--)
    {
        p = p->next;
    }

    cout << p->data << endl;

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
        int k;
        cin>>k;
        Search_k(L,k);
    }
    return 0;
}