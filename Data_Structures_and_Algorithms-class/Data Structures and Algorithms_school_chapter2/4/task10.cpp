#include<iostream>
using namespace std;
typedef struct DuLNode
{
	int data;
	struct DuLNode *next;
	struct DuLNode *prior;
}DuLNode,*DuLinkList;
void CreateList(DuLinkList &L,int n)
{//建立双向循环链表

    L=new DuLNode;    //初始化链表L的头结点
	L->prior=L;
	L->next=L;
	DuLinkList r=L;     //工作指针r初始化指向头结点
	while(n--)
	{
		DuLinkList p=new DuLNode;
		cin>>p->data;
		p->next=r->next;
		r->next=p;
		p->prior=r;
		p->next->prior=p;
		r=p;
	}
}
void Exchange(DuLinkList &L,int loc)
{//双向循环链表中结点的交换
/**************begin************/
    DuLNode *p = L;
    while(loc--)
    {
        p = p->next;
    }

    //交换
    DuLNode *prev = p->prior;
    //断开p
    prev->next = p->next;
    p->next->prior = p->prior;
    //插入p
    prev->prior->next = p;
    p->next = prev;
    p->prior = prev->prior;
    prev->prior = p;

    /**************end************/
}
void PrintList(DuLinkList &L)
{//依次输出链表中的数据
    DuLinkList p=L->next;
	while(p->next&&p->next!=L)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<p->data<<endl;
}
int main()
{
	int n;
	while(cin>>n)
	{
	 	if(n==0) break;
	 	DuLinkList L;
	 	CreateList(L,n);
	 	int loc;
		cin>>loc;
		if(n==1)          //链表仅有一个元素时输出其自身
		{
			cout<<L->next->data<<endl;
			continue;
		}
		Exchange(L,loc);
		PrintList(L);
	}
	return 0;
}