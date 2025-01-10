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
void PrintList(LinkList L)
{//打印依次输出链表中的数据
    LinkList p=L->next;
    while(p){
        if(p->next!=NULL) cout<<p->data<<" ";
        else cout<<p->data;
        p=p->next;
    }
    cout<<endl;
}
void SelectSort(LinkList &L)
{//基于单链表的简单选择排序
/**************begin************/
    LNode *p = L->next;
    while(p){
        LNode *q = p->next;
        if(q == NULL) break;
        LNode *min = q;
        while(q){
            if(q->data < min->data) min = q;
            q = q->next;
        }
        if(min->data < p->data){
            int temp = p->data;
            p->data = min->data;
            min->data = temp;
        }
        p = p->next;
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
		CreateList_R(L,n);        //后插法创建单链表
		SelectSort(L);           //基于单链表的简单选择排序
		PrintList(L);           //打印依次输出链表中的数据
	}
	return 0;
}