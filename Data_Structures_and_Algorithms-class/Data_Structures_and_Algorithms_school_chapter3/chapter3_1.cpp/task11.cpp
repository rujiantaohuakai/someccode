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
double GetAverage(LinkList L,int n)
{//递归求解单链表中的平均值
    /**************begin************/
    double N = n;
    if(L == NULL) return 0;
    return L->data/N + GetAverage(L->next, n);
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
        L=L->next;//L指向首元结点
        printf("%.2f\n",GetAverage(L,n));//输出保留两位小数
    }
    return 0;
}