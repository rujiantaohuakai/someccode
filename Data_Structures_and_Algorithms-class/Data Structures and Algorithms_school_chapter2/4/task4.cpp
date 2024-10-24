#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;
void CreateList_R(LinkList &L,int n)
{//后插法创建单链表
    L=new LNode;
    L->next=NULL;
    LinkList r=L;
    for(int i=0;i<n;i++)
    {
        LinkList p=new LNode;
        cin>>p->data;
        p->next=NULL;
        r->next=p;
        r=p;
    }
}
void PrintList(LinkList &L)
{//打印依次输出链表中的数据
    L=L->next;
    while(L){
        if(L->next!=NULL) cout<<L->data<<" ";
        else cout<<L->data;
        L=L->next;
    }
    cout<<endl;
}
void Intersection(LinkList &LA,LinkList &LB)
{//求基于链表的两个集合的交集
/**************begin************/
    //要求：交集，相同的元素;空间复杂度O(1);链表带头结点
    //思路，查找每个LA结点是否存在于LB中,如果存在，尾插法插入LA
    LNode *pa = LA->next;
    LNode *pb = LB->next;
    LA->next = NULL;
    LNode *atail = LA;
    while(pa)
    {
        pb = LB->next;
        LNode *prevb = LB;  //用于解决方案2
        while(pb)
        {   
            /*  移动旧LA链表中的元素会出现问题《《《未解决问题》》》    不建议用这个思路，不好完善
            if(pa->data == pb->data)    //将旧LA中元素移动到新LA，存在问题，pa在if语句中就会移动，可能导致pa==NULL
            {
                LNode *temp = pa;
                pa = pa->next;
                temp->next = atail->next;   //atail->next 始终为NULL
                atail->next = temp;
                atail = temp;
            }
            pb = pb->next;
            */

            /*  成功解决方案1：有一点优化
                        if(pb->data == pa->data)
            {
                LNode *temp = pb;
                pb = pb->next;

                // LNode *del = LB->next;  //一下七行代码防止 第70行：LB->next = pb; 产生内存泄漏
                // while(del && del != pb)
                // {
                //     LNode *tem = del;
                //     del = del->next;
                //     delete tem;
                // }                     《《《《《有问题，待解决》》》》》

                LB->next = pb;          //直接丢弃当前pb前的所有结点，因为是递增集合，pb之前的结点肯定比
                                        //当前pa和LA之后结点的值要小，所以可以直接丢弃，没有处理应该会造成内存泄漏
                temp->next = atail->next;
                atail->next = temp;
                atail = temp;
                break;
            }
            */

            //解决方案2：   没问题
            if(pb->data == pa->data)
            {
                //将pb连接到新LA中
                prevb->next = pb->next;
                pb->next = atail->next;
                atail->next = pb;
                atail = pb;
                pb = prevb->next;
            }
            else
            {
                prevb = pb;
                pb = pb->next;
            }

        }
        pa = pa->next;
    }

    delete LB;
    /**************end************/
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        LinkList LA,LB;
        CreateList_R(LA,n);
        CreateList_R(LB,m);
        Intersection(LA,LB);
        PrintList(LA);
    }
    return 0;
}