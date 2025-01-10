 #include<iostream>
using namespace std;
char path[100];

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
        return;
    }
	T = new BiTNode;
    T->data = S[i++];
    CreateBiTree(T->lchild,S,i);
    CreateBiTree(T->rchild,S,i);
}
void AllPath(BiTree T,char path[],int pathlen)
{//二叉树叶子结点到根结点的路径的求解
    if(T->lchild == NULL && T->rchild == NULL){
        cout << T->data;
        for(int i = pathlen - 1; i >= 0; i--){
            cout << path[i];
        }
        cout << endl;
        return;
    }

    if(T->lchild!= NULL){
        path[pathlen] = T->data;
        AllPath(T->lchild,path,pathlen+1);
    }

    if(T->rchild!= NULL){
        path[pathlen] = T->data;
        AllPath(T->rchild,path,pathlen+1);
    }
}

int main(){

    char S[100];
    while(cin >> S && S[0] != '0'){
        int i = -1;
        BiTree T;
        CreateBiTree(T,S,++i);
        int pathlen = 0;
        AllPath(T,path,pathlen);
    }
    
    return 0;
}

