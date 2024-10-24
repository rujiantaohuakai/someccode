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
{//依次输出链表中的数据和该集合的元素个数
    L=L->next;
    int s=0;
    while(L)
    {
        if(L->next!=NULL) cout<<L->data<<" ";
        else cout<<L->data;
        L=L->next;
        s++;
    }
    cout<<endl<<s<<endl;
}
void Difference(LinkList &LA,LinkList &LB)
{//求基于链表的两个集合的差集
/**************begin************/
   //要求：求递增整数集合AB的差集，仅出现在A中不出现在B中的元素;时间复杂度为O(1)
   //思路：遍历LA，每一个元素与LB中的元素比较，LB遍历完后无相等，则尾插法插入LC,最后LA=LC
   //思路二：直接删除LA中相等的元素
    LinkList LC = new LNode;
    LC->next = NULL;
    LNode *ctail = LC;
    LNode *pa = LA->next;
    LNode *preva = LA;
    //最好不要再内层操作外层循环条件
    bool isequal = false;
    while(pa)
    {
        LNode *pb = LB->next;
        while(pb)
        {
            if(pa->data == pb->data)
            {
                isequal = true;
                break;
            }
            pb = pb->next;
        }

        if(!isequal)
        {
            preva->next = pa->next;
            pa->next = ctail->next; //=NULL
            ctail->next = pa;
            ctail = pa;
            pa = preva->next;   //pa相当于往后移动了一位
        }
        else    //如果相等pa向后移动
        {
            isequal = false;
            pa = pa->next;
        }
    }

    delete LB;
    LA = LC;

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
        Difference(LA,LB);
        PrintList(LA);
    }
    return 0;
}