#include<iostream>
#include<string.h>
using namespace std;
typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void CreateBiTree(BiTree &T,char S[],int &i)
{//先序建立二叉树
	T = new BiTNode;
    if(S[i] == '0'){
        T = NULL;
        i++;
    }
    else{
        T->data = S[i++];
        CreateBiTree(T->lchild,S,i);
        CreateBiTree(T->rchild,S,i);
    }
    return;
}
void PreOrderTraverse(BiTree T)
{//二叉树的先序遍历
    if(T != NULL){
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
void InOrderTraverse(BiTree T)
{//二叉树的中序遍历
    if(T != NULL){
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }
}
void PostOrderTraverse(BiTree T)
{//二叉树的后序遍历
    if(T != NULL){
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data;
    }
}

int flag;

int main(){
    char S[100];
    while(cin >> S){
        if(strcmp(S,"0") == 0) break;
        BiTree T;
        int i = -1;
        CreateBiTree(T,S,++i);
        PreOrderTraverse(T);
        cout << endl;
        InOrderTraverse(T);
        cout << endl;
        PostOrderTraverse(T);
        cout << endl;
    }
    return 0;
}
