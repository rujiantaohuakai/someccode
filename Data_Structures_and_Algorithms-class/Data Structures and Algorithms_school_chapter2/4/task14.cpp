#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;
void CreateCirList(LinkList &L,int m)
{//后插法创建单向循环链表
    L=new LNode;
    L->next=NULL;
    L->data=1;
    LinkList r=L;
    for(int i=2;i<=m;i++)
    {
        LinkList p=new LNode;
        p->data=i;
        p->next=NULL;
        r->next=p;
        r=p;
    }
    r->next=L;                                   //尾结点的指针指向首元结点,单向循环链表建成
    L=r;                                          //L需要指向尾结点，以防n=1时第一个需要删除的是首元结点，不易得到前驱结点
}
void MonkeyKing(LinkList &L,int n)
{//猴子选大王（约瑟夫问题）
/**************begin************/
    //单循环链表！无头结点！！！
    int count = 1;
    LNode *p = L->next;
    LNode *prev = L;        //指向首元结点前一个
    while(p->next != p)
    {   
        if(count == n)
        {
            cout << p->data << " ";
            prev->next = p->next;
            p = prev->next;
            count = 1;
        }
        else
        {
            p = p->next;
            prev = prev->next;
            count++;
        }
    }
    cout << p->data << endl;
    /**************end************/
}
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        if(n==0&&m==0) break;
        LinkList L;
        CreateCirList(L,m);
        MonkeyKing(L,n);
    }
    return 0;
}