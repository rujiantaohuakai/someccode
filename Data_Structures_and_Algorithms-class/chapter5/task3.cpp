#include<iostream>
#include<cstring>
using namespace std;
typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void CreateBiTree(BiTree &T,char S[],int &i)
{//先序建立二叉树
	T = new BiTNode;
    T->data = S[i++];
    if(T->data != '0')
    {
        CreateBiTree(T->lchild,S,i);
        CreateBiTree(T->rchild,S,i);
    }
    return;
}
void ChangeRL(BiTree &T)
{//二叉树所有结点的左右孩子的交换
    if(T->lchild->data != '0')//如果有左孩子
        ChangeRL(T->lchild);
    if(T->rchild->data != '0')//如果有右孩子
        ChangeRL(T->rchild);
    BiTNode *temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;
    return;
}
void PreOrderTraverse(BiTree T)
{//先序遍历
	cout << T->data;
    if(T->lchild->data != '0') PreOrderTraverse(T->lchild);
    if(T->rchild->data != '0') PreOrderTraverse(T->rchild);
}

int main(){
    char S[100];
    while(cin>>S){
        if(strcmp(S,"0") == 0) break;
        int i = -1;
        BiTree T;
        CreateBiTree(T,S,++i);
        ChangeRL(T);
        PreOrderTraverse(T);
        cout << endl;
    }
    return 0;
}