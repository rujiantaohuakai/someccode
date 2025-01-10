#include<iostream>
using namespace std;
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;
LinkList H[13];   //链地址法，13个单链表
void Hash(int e)
{//基于链地址法的散列表的插入
	int index=e%13;       //计算散列地址
	LinkList p=H[index];   //工作指针p指向链表的头结点
	while(p->next)         //移至表尾
		p=p->next;
	LinkList q=new LNode;    //生成新结点*q
	q->data=e;               //将新结点*q的数据域置为e
	q->next=NULL;            //将新结点*q插入在尾结点*p之后
	p->next=q;
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
void Delete(int e)
{//基于链地址法的散列表的删除
    /**************begin************/
	int index = e % 13;
    LNode *p = H[index]->next;
    LNode *prev = H[index];
    while(p){
        if(p->data == e){
            prev->next = p->next;
            delete p;
            break;
        }
        prev = p;
        p = p->next;
    }
    /**************end************/
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
		int k;
		cin>>k;
		Delete(k);  //需要删除的关键字k
		Output();  //输出数据
	}
	return 0;
}