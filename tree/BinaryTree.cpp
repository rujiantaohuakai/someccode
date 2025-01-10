#include<iostream>
#include<queue>
#define TElemType char
using namespace std;

typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild, *rchild;
    int ltag, rtag; //左右线索标志
}BiTNode,*BiTree;


//构造空二叉树T
void InitBiTree(BiTree &T){
    T = NULL;
}

//销毁二叉树T
void DestoryBiTree(BiTree &T){
    if(T == NULL) return;

    if(T->lchild != NULL){
        DestoryBiTree(T->lchild);
        T->lchild = NULL;
    }
    if(T->rchild != NULL){
        DestoryBiTree(T->rchild);
        T->rchild = NULL;
    }
    //没有左右孩子，说明是叶子结点，可以释放结点
    if(T != NULL){
        delete T;
        T = NULL;
    }
}

//按照先序遍历创建二叉树
void PreOrderCreateBiTree(BiTree &T){

    T = new BiTNode;
    char ch;
    cin >> ch;
    if(ch == '#'){
        T = NULL;
    }
    else{
        T->data = ch;
        T->ltag = 0; T->rtag = 0;
        PreOrderCreateBiTree(T->lchild);
        PreOrderCreateBiTree(T->rchild);
    }

}

// //清空二叉树T
// void ClearBiTree(BiTree &T){

// }

//判断二叉树T是否为空
bool BiTreeEmpty(const BiTree &T){
    if(T == NULL) return true;
    else return false;
}

//返回T的深度
int BiTreeDepth(const BiTree &T){
    if(T == NULL) return 0;
    int left_depth = BiTreeDepth(T->lchild) + 1;
    int right_depth = BiTreeDepth(T->rchild) + 1;
    return left_depth > right_depth? left_depth : right_depth;
}

// //返回结点e的值
// TElemType BiTreeValue(const BiTree &T, BiTNode *e){
    
// }

// //给结点e赋值value
// void BiTreeAssign(BiTree &T, BiTNode *e, int value){

// }

// //返回非根节点e的双亲,否侧返回空
// BiTNode* BiTreeParent(const BiTree &T, BiTNode *e){

// }

// //返回e的左孩子，无左孩子返回空
// BiTNode* BiTreeLeftChild(const BiTree &T, BiTNode *e){

// }

// //返回e的右孩子，无右孩子返回空
// BiTNode* BiTreeRightChild(const BiTree &T, BiTNode *e){

// }

// //返回e的左兄弟，无左兄弟返回空
// BiTNode* BiTreeLeftSibling(const BiTree &T, BiTNode *e){

// }

// //返回e的右兄弟，无右兄弟返回空
// BiTNode* BiTreeRightSibling(const BiTree &T, BiTNode *e){

// }

// //根据LR为0 or 1,删除T中p所指结点的左或右子树
// void BiTreeDelete(BiTree &T, BiTNode *p, int LR){

// }

//指针e指向先序遍历第k个结点
void BiTreeKnode(const BiTree &T, int k, BiTNode *&e){
    if(T == NULL) return;
    static int count = 1;//根结点是第一个结点
    if(count == k){
        e = T;
        return;
    }
    count++;
    if(T->lchild != NULL && T->ltag == 0 && e == NULL)
        BiTreeKnode(T->lchild, k, e);
    if(T->rchild != NULL && T->rtag == 0 && e == NULL)
        BiTreeKnode(T->rchild, k, e);
}

//先序遍历二叉树T，每个节点访问一次
void PreOrderTraverse(const BiTree &T){
    if(T){
        cout << T->data << " ";
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}


//中序遍历二叉树T，每个节点访问一次
void InOrderTraverse(const BiTree &T){
    if(T == NULL) return;
    InOrderTraverse(T->lchild);
    cout << T->data << " ";
    InOrderTraverse(T->rchild);
}

//后序遍历二叉树T，每个节点访问一次
void PostOrderTraverse(const BiTree &T){
    if(T == NULL) return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    cout << T->data << " ";
}

//层序遍历二叉树T，每个节点访问一次
void LevelOrderTraverse(const BiTree &T, queue<BiTNode*> &q){
    if(T == NULL) return;
    q.push(T);
    while(!q.empty()){
        BiTNode *p = q.front();
        q.pop();
        cout << p->data << " ";
        if(p->lchild != NULL) q.push(p->lchild);
        if(p->rchild != NULL) q.push(p->rchild);
    }
}

//先序遍历输出线索二叉树T，每个节点访问一次
void PreOrderTraverse_Thread(const BiTree &T){
    if(T){
        cout << T->ltag << " " << T->data << " " << T->rtag << endl;
        if(T->ltag == 0)
            PreOrderTraverse_Thread(T->lchild);
        if(T->rtag == 0)
            PreOrderTraverse_Thread(T->rchild);
    }
}

// //查找值为value的结点，返回其指针，找不到返回空
// BiTNode* BiTreeSearch(const BiTree &T, TElemType value){

// }

/*
先序创建 A B D # # E # # C # F # #
        A
       / \
      B   C
     / \   \
    D   E   F

先序遍历: A B D E C F
中序遍历: D B E A C F
后序遍历: D E B F C A
*/
//中序线索化二叉树,最后一个结点指向NULL
void InOrderThread(BiTree T, BiTNode *&pre){
    if(T != NULL){    //非空二叉树
        InOrderThread(T->lchild, pre);

        if(T->lchild == NULL){
            //左子树为空，线索化，指向直接前驱
            T->lchild = pre;
            T->ltag = 1;
        }
        if(pre != NULL && pre->rchild == NULL){
            //前驱没有右孩子，线索化，指向当前结点
            pre->rchild = T;
            pre->rtag = 1;
        }

        // //输出前驱结点线索化结果
        // if(pre != NULL)
        //     cout << pre->ltag << " " << pre->data << " " << pre->rtag << endl;
        pre = T;
        
        InOrderThread(T->rchild, pre);
        
    }
}

//层序遍历线索二叉树T，每个节点访问一次
void LevelOrderTraverse_Thread(const BiTree &T, queue<BiTNode*> &q){
    if(T == NULL) return;
    q.push(T);
    while(!q.empty()){
        BiTNode *p = q.front();
        q.pop();
        cout << p->data << " ";
        if(p->ltag == 0 && p->lchild != NULL) q.push(p->lchild);
        if(p->rtag == 0 && p->rchild != NULL) q.push(p->rchild);
    }
}
/*
先序创建 A B D # # E # # C # F # #
        A
       / \
      B   C
     / \   \
    D   E   F

先序遍历: A B D E C F
中序遍历: D B E A C F
后序遍历: D E B F C A
*/
// //从线索二叉树中e指向的结点开始，输出Tree1中序遍历的后继结点
// void Successor(const BiTree T, BiTNode *e){

// }

//中序遍历线索二叉树T，每个节点访问一次
void InOrderThread_Thread_1(const BiTree T){
    BiTNode *p = T;
    while(p != NULL){
        while(p->ltag == 0) p = p->lchild;  //找到左子树的最左结点
        cout << p->data << " ";
        while(p->rtag == 1 && p->rchild != NULL){
            p = p->rchild;
            cout << p->data << " ";
        }
        p = p->rchild;  //转向p的右子树
    }
}



int main(){

    BiTree Tree1;
    InitBiTree(Tree1);
    BiTree Tree2;
    InitBiTree(Tree2);
    cout << "请输入先序遍历创建二叉树：" << endl;
    PreOrderCreateBiTree(Tree1);
    cout << "先序遍历二叉树：" << endl;
    PreOrderTraverse(Tree1);
    cout << endl;
    cout << "中序遍历二叉树：" << endl;
    InOrderTraverse(Tree1);
    cout << endl;
    cout << "后序遍历二叉树：" << endl;
    PostOrderTraverse(Tree1);
    cout << endl;


    if(BiTreeEmpty(Tree1)) cout << "Tree1 二叉树为空" << endl;
    else cout << "Tree1 二叉树不为空" << endl;
    if(BiTreeEmpty(Tree2)) cout << "Tree2 二叉树为空" << endl;
    else cout << "Tree2 二叉树不为空" << endl;

    cout << "Tree 1 的深度为：" << BiTreeDepth(Tree1) << endl;
    cout << "Tree 2 的深度为：" << BiTreeDepth(Tree2) << endl;

    //层序遍历二叉树
    cout << "层序遍历二叉树Tree1:" << endl;
    queue<BiTNode*> q1;
    LevelOrderTraverse(Tree1, q1);
    cout << endl;

    //销毁Tree1
    DestoryBiTree(Tree1);
    cout << "Tree1 销毁完毕" << endl;
    cout << "Tree 1 的深度为：" << BiTreeDepth(Tree1) << endl;

    cout << "请输入先序遍历创建二叉树Tree1:" << endl;
    PreOrderCreateBiTree(Tree1);

    //中序线索化二叉树
    BiTNode *pre = NULL;
    InOrderThread(Tree1, pre);

    //先序输出线索化后的二叉树
    cout << "先序输出线索化后的二叉树：" << endl;
    PreOrderTraverse_Thread(Tree1);
    cout << endl;

    //层序遍历线索二叉树
    cout << "层序遍历线索二叉树Tree1:" << endl;
    queue<BiTNode*> q2;
    LevelOrderTraverse_Thread(Tree1, q2);
    cout << endl;

    cout << "Tree1 的第2个结点的值为:";
    BiTNode *e = NULL;
    BiTreeKnode(Tree1, 2, e);
    cout << e->data << endl;

    //从Tree1的e指向的结点开始，层序遍历线索二叉树
    cout << "层序遍历线索二叉树Tree1的第2个结点开始:" << endl;
    LevelOrderTraverse_Thread(e, q2);
    cout << endl;

    //从Tree1第2个结点开始，输出Tree1中序遍历的后继结点
    // cout << "Tree1 从第2个结点开始,输出Tree1中序遍历的后继结点:" << endl;
    // Successor(Tree1, e);
    // cout << endl;

    //中序遍历线索二叉树
    cout << "中序遍历线索二叉树Tree1：" << endl;
    InOrderThread_Thread_1(Tree1);
    cout << endl;





    
    

    return 0;
}

/*
先序创建 A B D # # E # # C # F # #
        A
       / \
      B   C
     / \   \
    D   E   F

先序遍历: A B D E C F
中序遍历: D B E A C F
后序遍历: D E B F C A


*/






















