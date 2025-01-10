#include<iostream>
using namespace std;
typedef struct BSTNode
{//二叉排序树的二叉链表存储表示
	int data;
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;
int sum;////设一个全局变量sum,为了判断该数据是否为输出的最后一个数
void InsertBST(BSTree &T,int e)
{//当二叉排序树T中不存在关键字等于e的数据元素时，则插入该元素
    /**************begin************/
	if(T == NULL){
        T = new BSTNode;
        T->data = e;
        T->lchild = NULL;
        T->rchild = NULL;
    }
    else if(e < T->data) InsertBST(T->lchild,e);
    else if(e > T->data) InsertBST(T->rchild,e);

    /**************end************/
}
BSTree CreateBSTree(int n)
{//构建二叉排序树
    BSTree T=NULL;
    int e;
    for(int i=0;i<n;i++)
    {
        cin>>e;
        InsertBST(T,e);
    }
    return T;
}
void InOrderTraverse(BSTree T,int x)
{//中序遍历二叉树T的递归算法
    if(T==NULL) return;   //空树
    else
    {
        InOrderTraverse(T->lchild,x);//递归遍历左子树
        sum--;         //每次遍历时sum减1
        if(T->data>=x)
        {                               //输出二叉排序树中所有数值大于等于x的结点的数据
            cout<<T->data;              //先输出数据
            if(sum==0) cout<<endl;    //如果是最后一个元素，换行
            else cout<<" ";           //非末位元素，输出空格
        }
        InOrderTraverse(T->rchild,x);//递归遍历右子树
    }
}
int main()
{
	int n,x;        //二叉排序树的结点数n，数字x
	while(cin>>n)
	{
		if(n==0) break;
		BSTree T=NULL;
		T=CreateBSTree(n);
		cin>>x;          //输入数字x
		sum=n;          //结点数n赋给sum
		InOrderTraverse(T,x);
	}
	return 0;
}