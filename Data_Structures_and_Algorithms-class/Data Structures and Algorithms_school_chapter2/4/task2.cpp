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
void MergeList(LinkList &LA,LinkList &LB)
{//求基于链表的两个递增有序序列的合并,要求空间复杂度为O(1)
/**************begin************/
    LNode *pb = LB->next;
    LNode *prevb = LB;
    while(pb != NULL)
    {
        LNode *pa = LA->next;
        LNode *preva = LA;
        //找到第一个大于pb的LA结点，将pb插入这个结点之前
        while(pa && pa->data < pb->data)
        {
            preva = pa;
            pa = pa->next;      //pa向后移动
        }//最终两种可能，找到了第一个大于pb的结点，或者pa已经到链表尾部
        if(pa == NULL)
        {
            preva->next = pb;
            delete LB;
            return;
        }
        else if(pa->data == pb->data)
        {
            prevb->next = pb->next;
            delete pb;
            pb = prevb->next;
        }
        else
        {
            preva->next = pb;
            prevb->next = pb->next;
            pb->next = pa;
            preva = pb;
            pb = prevb->next;
        }
    }

    /**************end************/
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        LinkList LA,LB;
        CreateList_R(LA,n);
        CreateList_R(LB,m);
        MergeList(LA,LB);
        PrintList(LA);
    }
    return 0;
}