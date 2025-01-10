#include<iostream>
using namespace std;
typedef struct DuLNode
{
	int data;
	struct DuLNode *prior,*next;
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
void DuplexSort(DuLinkList L)
{//对存储在带头结点的双向链表L中的元素进行双向冒泡排序
/**************begin************/

	DuLNode *pr = L->prior;
	while(pr != L->next){
		DuLNode *p1 = L->next;
		DuLNode *p2 = p1->next;
		while(p1 != pr){
			if(p1->data > p2->data){
				int temp = p1->data;
				p1->data = p2->data;
				p2->data = temp;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		pr = pr->prior;
	}

    /**************end************/
}
void PrintList(DuLinkList L)
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
		DuplexSort(L);      //双向冒泡排序
		PrintList(L);
	}
	return 0;
}