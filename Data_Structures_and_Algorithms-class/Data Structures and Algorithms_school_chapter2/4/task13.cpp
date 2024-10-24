#include <iostream>
using namespace std;
typedef struct LNode
{
    char data;
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
void FindSuffix(LinkList str1, LinkList str2,int n,int m)
{//查找两个单词链表共同后缀的起始结点

/**************begin************/
    //思路：找到第一个相等的字母,判断该字母后面的的字母是否相等
    //比如using sing 找到s 判断之后的ing相等,所以共用sing,输出s
    //特殊,比如usiiiing sing, 需要找到iiiing最后一个i,所以找到相同字母后,需要判断之后还有没有相同的字母
    //直到找到最后一个相同的字母
    LNode *p1 = str1->next;
    while(p1)
    {
        LNode *p2 = str2->next;
        while(p2)
        {
            if(p1->data == p2->data)
            {
                LNode *ans = p1;
                LNode *eq1 = p1->next;
                LNode *eq2 = p2->next;
                while(eq1 && eq2 && eq1->data == eq2->data)
                {
                    eq1 = eq1->next;
                    eq2 = eq2->next;
                }
                if(!eq1 && !eq2)
                {
                    cout << ans->data <<endl;
                    return;
                }
                else
                    p2 = p2->next;
            }
            else
                p2 = p2->next;
        }
        p1 = p1->next;
    }

   /**************end************/
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        LinkList str1,str2,p;
        CreateList_R(str1,n);
        CreateList_R(str2,m);
        FindSuffix(str1,str2,n,m);
    }
    return 0;
}