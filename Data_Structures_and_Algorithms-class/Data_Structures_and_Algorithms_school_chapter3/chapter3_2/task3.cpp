#include<iostream>
using namespace std;
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef struct
{
	int *base;
	int front;
  	int rear;
}SqQueue;
int InitQueue(SqQueue &Q)
{//构造一个空队列Q
	Q.base=new int[MAXSIZE];          //为队列分配一个最大容量为MAXSIZE的数组空间
	if(!Q.base) return OVERFLOW;            //存储分配失败
	Q.front=Q.rear=0;                  //头尾指针置零，队列为空
	return OK;
}
bool isEmpty(SqQueue Q){
    if(Q.front == Q.rear) return true;
    else return false;
}

bool isFull(SqQueue Q){

    if((Q.rear+1)%MAXSIZE == Q.front) return true;
    else return false;
}

int EnQueue(SqQueue &Q,int e)
{//插入元素e为Q的新的队尾元素
/**************begin************/
    if(isFull(Q)) return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1) % MAXSIZE;
    return OK;
	/**************end************/
}
int DeQueue(SqQueue &Q)
{//删除Q的队头元素，用e返回其值
/**************begin************/
    int e;
    if(isEmpty(Q)) return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front+1) % MAXSIZE;
    return e;
	/**************end************/
}
int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
		SqQueue Q;
		InitQueue(Q);
		for(int i=0;i<n;i++)
		{
			int x;cin>>x;
			EnQueue(Q,x);
		}
		for(int i=0;i<n-1;i++)
			cout<<DeQueue(Q)<<" ";
		cout<<DeQueue(Q)<<endl;
	}
	return 0;
}