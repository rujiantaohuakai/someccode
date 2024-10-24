#include<iostream>
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
void Decollate(LinkList L,LinkList L1)
{//奇偶链表的分割
/**************begin************/
    //要求: 空间复杂度O(1),时间复杂度O(n)
    //偶链表放在奇链表之后
    //思路：先将奇数位置的结点插入L1,最后将L剩余结点(偶结点)接入L1
    LNode *p = L->next;     //p指向首元结点
    LNode *prev = L;
    LNode *tail = L1;
    while(p->next && p->next->next)
    { //0 1 2 3 4 5 6
        prev->next = p->next;   //连接，防止断链
        prev = prev->next;
        p->next = tail->next;
        tail->next = p;
        tail = p;
        p = prev->next;
    }   //结束后两种可能，p指向最后一个结点，该结点为奇结点;或者p指向最后一个奇结点,p之后还有一个偶结点
    prev->next = p->next;
    p->next = tail->next;
    tail->next = p;
    tail = p;

    tail->next = L->next;

    delete L;

    /**************end************/
}
void PrintList(LinkList &L)
{//依次输出链表中的数据
    LinkList p=L->next;
    while(p)
    {
        if(p->next!=NULL) cout<<p->data<<" ";
        else cout<<p->data;
        p=p->next;
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
        LinkList L1=new LNode;    //申请新链表L1
        L1->next=NULL;
        Decollate(L,L1);      //奇偶链表的分割
        PrintList(L1);
	}
	return 0;
}