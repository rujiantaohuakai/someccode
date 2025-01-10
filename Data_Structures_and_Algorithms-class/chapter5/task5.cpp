 #include <iostream>
#include <string.h>
using namespace std;

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTree CreateBiTree(int &pos, char *str)
{// 先序建立二叉树
   
}

int Width(BiTree T)
{// 求二叉树T最大宽度
   
}

int main(){
    char str[1000];
    while(cin >> str){
        if(strcmp(str, "0") == 0) break;
        int pos = 0;
        BiTree root = CreateBiTree(pos, str);
        cout << Width(root) << endl;
    }
    return 0;
}

