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
int Abs(int x)
{//绝对值函数
	return x>0?x:-x;
}
void DeleteEqualNode(LinkList &L,int n)
{//删除链表中绝对值相等的结点
/**************begin************/
    //时间复杂度O(n),空间复杂度无要求
    bool hash[101] = {false};
    LNode *p = L->next;
    LNode *prev = L;
    while(p)
    {
        int abs = Abs(p->data);
        if(!hash[abs])
        {
            hash[abs] = true;
            p = p->next;
            prev = prev->next;
        }
        else
        {
            prev->next = p->next;
            delete p;
            p = prev->next;
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
        DeleteEqualNode(L,n);
        PrintList(L);
    }
    return 0;
}