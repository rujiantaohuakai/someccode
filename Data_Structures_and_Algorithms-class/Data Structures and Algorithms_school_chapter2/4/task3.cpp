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
void MergeList(LinkList &LA,LinkList &LB,LinkList &LC)
{//求基于链表的两个非递减有序序列的合并     输入非递减，输出非递增
/**************begin************/
//思路：先将pa反转再头插法，找到第一个小于或者等于就插入; 要求：空间复杂度O(1)
    LNode *pa = LA->next;
    LA->next = NULL;
    while(pa)   //将LA反转为非递增  9 7 6 5 4 3 1
    {           //            设LB 2 7 8 13 13 22
        LNode *temp = pa;
        pa = pa->next;
        temp->next = LA->next;
        LA->next = temp;
    }

    LNode *pb = LB->next;
    while(LB->next != NULL)
    {
        pa = LA->next;
        LNode *preva = LA;
        while(pa && pa->data > pb->data)
        {
            preva = pa;
            pa = pa->next;
        }   //找到第一个小于或者等于LB首元结点data值的LA的结点
        LB->next = pb->next;
        preva->next = pb;
        pb->next = pa;
        preva = pb;     //注意重置preva的位置
        pb = LB->next;  //注意重置pb回到LB中
    }

    delete LB;

    LC = LA;

    /**************end************/
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        LinkList LA,LB,LC;
        CreateList_R(LA,n);
        CreateList_R(LB,m);
        MergeList(LA,LB,LC);
        PrintList(LC);
    }
    return 0;
}