#include<iostream>
#include <string.h>
using namespace std;
typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void CreateBiTree(BiTree &T,char S[],int &i)
{//先序建立二叉树
	if(S[i]=='#') T=NULL;
	else
	{
		T=new BiTNode;
		T->data=S[i];
		CreateBiTree(T->lchild,S,++i);
		CreateBiTree(T->rchild,S,++i);
	}
}
BiTree pre=NULL;   //前驱指针
void JudgeBST(BiTree T,int &flag)
{//判断二叉树T是否为二叉排序树，flag初值为1
    /**************begin************/
    if(T == NULL) return;

    if(T->lchild != NULL && T->lchild->data >= T->data) flag = 0;
    if(T->rchild != NULL && T->rchild->data <= T->data) flag = 0;

    JudgeBST(T->lchild,flag);
    JudgeBST(T->rchild,flag);
    /**************end************/
}
int main()
{
	char S[100];
	while(cin>>S)
	{
		if(strcmp(S,"#")==0) break;
		int i=-1;
		int flag=1;
	  	BiTree T;
		CreateBiTree(T,S,++i);
		JudgeBST(T,flag);
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}