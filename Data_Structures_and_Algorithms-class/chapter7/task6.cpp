#include<iostream>
using namespace std;
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;
LinkList H[13];    //链地址法，13个单链表
void Hash(int e)
{//基于链地址法的散列表的插入
    /**************begin************/
    //头插法
	// LNode *p = H[e%13]->next;
    // LNode *q = new LNode;
    // q->data = e;
    // q->next = p;
    // H[e%13]->next = q;
    
    //尾插法
    LNode *p = new LNode;
    p->data = e;
    p->next = NULL;
    LNode *q = H[e%13]->next;
    if(q == NULL) H[e%13]->next = p;
    else{
        while(q->next){
            q = q->next;
        }
        q->next = p;
    }
    /**************end************/
}
void Input(int n)
{//输入数据
	for(int i=0;i<13;i++)     //建立13个带有头结点的单链表
	{
		H[i]=new LNode;
		H[i]->next=NULL;
	}
	while(n--)          //输入n个关键字,构造散列表
	{
		int e;
		cin>>e;
		Hash(e);
	}
}
void Output()
{//输出数据
	for(int i=0;i<13;i++)
	{
		cout<<i;                 //输出散列地址
		LinkList p=H[i]->next;   //p初始化为链表的首元结点
		while(p)
		{
			cout<<" "<<p->data;
			p=p->next;
		}
		cout<<endl;
	}
}
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0) break;
		Input(n);     //输入数据
		int k;      //需要插入的关键字k
		cin>>k;
		Hash(k);
		Output();  //输出数据
	}
	return 0;
}