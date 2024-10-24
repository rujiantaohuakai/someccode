#include<iostream>
using namespace std;
typedef struct QNode
{//队列的链式存储结构
    int data;
    struct QNode *next;
}QNode,*QueuePtr;
typedef struct
{
    QueuePtr rear;    //只设一个队尾指针
}LinkQueue;
int EmptyQueue(LinkQueue Q)
{//判断队列是否为空，空返回1，否则返回0
//队列只有一个头结点，即当头结点的指针域指向自己时，队列为空
/**************begin************/
    if(Q.rear->next == Q.rear) return 1;
    else return 0;
    /**************end************/
}
void EnQueue(LinkQueue &Q,int e)
{//入队，插入元素e为Q的新的队尾元素
/**************begin************/
    QNode *p = new QNode;
    p->data = e;
    p->next = Q.rear->next; //指向头结点
    Q.rear->next = p;   //p插入队尾
    Q.rear = p;         //更新队尾指针
    return;
    /**************end************/
}
void DeQueue(LinkQueue &Q)
{//出队，输出Q的队头元素值，后将其删除
/**************begin************/
    if(EmptyQueue(Q)) return;
    QNode *p = Q.rear->next->next;  //指向首元结点（队头）
    cout << p->data << " ";
    if(p == Q.rear){
        Q.rear = Q.rear->next;
        Q.rear->next = Q.rear;
    }
    else{
        Q.rear->next->next = p->next;
    }
    delete p;
    return;
    /**************end************/
}
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0&&m==0) break;
		LinkQueue Q;        //初始化一个带头结点的循环链表
		Q.rear=new QNode;
        Q.rear->next=Q.rear;
		while(n--)
		{
			int e;cin>>e;
			EnQueue(Q,e);
		}
		while(m--)
			DeQueue(Q);
		if(EmptyQueue(Q))
			cout<<"0"<<endl;
		else
			cout<<"1"<<endl;
	}
	return 0;
}