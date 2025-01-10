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
	if(S[i] == '0'){
        T = NULL;
        i++;
    }
    else{
        T = new BiTNode;
        T->data = S[i];
        i++;
        CreateBiTree(T->lchild, S, i);
        CreateBiTree(T->rchild, S, i);
    }
}
void Count(BiTree T,int &a,int &b,int &c)
{//二叉树结点个数的统计度分别为0，1，2的结点个数
	if(T == NULL) return;
    if(T->lchild != NULL && T->rchild != NULL)
        c++;
    else if(T->lchild != NULL || T->rchild != NULL)
        b++;
    else if(T->rchild == NULL && T->lchild == NULL)
        a++;
    Count(T->lchild, a, b, c);
    Count(T->rchild, a, b, c);
}

int main(){
    char S[100];
    while(cin >> S){
        if(strcmp(S,"0") == 0) break;
        int a = 0, b = 0, c = 0;
        int i = -1;
        BiTree T;
        CreateBiTree(T, S, ++i);
        Count(T, a, b, c);
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}