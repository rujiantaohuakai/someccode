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
	if(S[i]=='#')
		T=NULL;
	else
	{
		T=new BiTNode;
		T->data=S[i];
		CreateBiTree(T->lchild,S,++i);
		CreateBiTree(T->rchild,S,++i);
	}
}
int Height(BiTree T)
{//求平衡二叉树T的高度
    /**************begin************/
	if(T == NULL) return 0;
	int lh = Height(T->lchild);
	int rh = Height(T->rchild);
	return (lh > rh? lh : rh) + 1;
    /**************end************/
}
int main()
{
	char S[100];//如果平衡因子b=-1，会被字符数组割裂成'-'和'1'，故本题输入样例不包含b=-1
	while(cin>>S)
	{
		if(strcmp(S,"#")==0) break;
		int i=-1;
	  	BiTree T;
		CreateBiTree(T,S,++i);
		cout<<Height(T)<<endl;
	}
	return 0;
}