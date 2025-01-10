#include<iostream>
using namespace std;
typedef struct BiTNode
{
	int data;
	int cnt;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
int sum=0;        //全局变量sum表示排序树当前结点的个数,也为了判断数据是否为输出的最后一个数
void SearchBST(BiTree &T,int x)
{//基于非递归的二叉排序树的结点的查找和插入
    /**************begin************/
    BiTNode *p = T;
    BiTNode *q = NULL;

    while(p != NULL){
        if(p->data == x){
            p->cnt++;
            return;
        }
        else if(p->data > x){
            q = p;
            p = p->lchild;
        }
        else if(p->data < x){
            q = p;
            p = p->rchild;
        }
    }

    if(q == NULL){
        T = new BiTNode;
        T->data = x;
        T->cnt = 0;
        T->lchild = NULL;
        T->rchild = NULL;
    }
    else if(q->data > x){
        p = new BiTNode;
        p->data = x;
        p->cnt = 0;
        p->lchild = NULL;
        p->rchild = NULL;
        q->lchild = p;
    }
    else if(q->data < x){
        p = new BiTNode;
        p->data = x;
        p->cnt = 0;
        p->lchild = NULL;
        p->rchild = NULL;
        q->rchild = p;
    }
    sum++;
    /**************end************/
}
void InOrderTraverse(BiTree T)
{//中序遍历输出二叉树T结点
    if(T==NULL) return;
    else
    {
        InOrderTraverse(T->lchild);
        sum--;
        cout<<T->data;
        if(sum==0)
            cout<<endl;
        else
            cout<<" ";
        InOrderTraverse(T->rchild);
    }
}
void Print_Count(BiTree T,int x)
{//中序遍历输出二叉树T计数
    if(T==NULL) return;
    else
    {
        Print_Count(T->lchild,x);
        sum--;
        cout<<T->cnt;
        if(sum==0)
            cout<<endl;
        else
            cout<<" ";
        Print_Count(T->rchild,x);
    }
}
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0) break;
		int e;        //变量e用于接收输入数据
	  	BiTree T=NULL;
		for(int i=0;i<n;i++)  //基于非递归的二叉排序树的结点的查找和插入
		{
			cin>>e;
			SearchBST(T,e);
		}
		int x;           //查找值为x
		cin>>x;
		SearchBST(T,x);
		if(sum==n+1) n++; //没找到时，x作为一个新结点插入树中，此时排序树的结点数加1
		sum=n;
		InOrderTraverse(T);//中序遍历输出二叉树T结点
		sum=n;
		Print_Count(T,x);   //中序遍历输出二叉树T计数
	}
	return 0;
}