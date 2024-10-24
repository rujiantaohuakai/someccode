// 请在Begin-End之间添加你的代码，
//实现两个集合的并、交和差运算//
//(1)采用单链表表示集合，假设同一个集合中不存在重复的元素，//
//(2)将其按递增方式排序，构成有序单链表，//
//(3)求两个集合的并、交、差。//
#include <stdio.h>
#include <malloc.h>
#include <iostream>
using namespace std;
typedef char ElemType;
typedef struct LNode 
{
	ElemType data;
	struct LNode *next;		//指向后继结点
} LNode, *LinkList;		 			//单链表结点类型

/********** Begin *********/
//初始化,带头结点
void InitList(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
}

//求表长
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L->next;
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}

//输入有序集合,尾插法
bool Inputlist(LinkList &L)
{
    ElemType e;
    InitList(L);

    LNode *r = L;//尾指针
    while(cin >> e)
    {
        LNode *s = new LNode;//新结点
        //将s插入尾部
        s->data = e;
        s->next = r->next;
        r->next = s;
        r = s;
        if(cin.get() == '\n') break;
    }
    
    return true;
}

//输出
void OutputList(LinkList L)
{
    LNode *p = L->next;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

//集合的并集
LinkList Union(LinkList La, LinkList Lb)
{
    LinkList Lc;
    InitList(Lc);
    LNode *pa = La->next; //用于遍历La
    LNode *pb = Lb->next; //用于遍历Lb
    LNode *ctail = Lc;    //用于插入Lc

    while(pa && pb)
    {
        LNode *s = new LNode;
        if(pa->data < pb->data)
        {
            //判断La的下一个元素是否与上一个元素相同
            if(pa->data == ctail->data)
                {
                    pa = pa->next;
                    continue;
                }
            s->data = pa->data;
            pa = pa->next;
            s->next = NULL;
            ctail->next = s;
            ctail = s;

        }
        else if(pa->data > pb->data)
        {
            //判断Lb的下一个元素是否与上一个元素相同
            if(pb->data == ctail->data)
                {
                    pb = pb->next;
                    continue;
                }
            s->data = pb->data;
            pb = pb->next;
            s->next = NULL;
            ctail->next = s;
            ctail = s;
        }
        else //pa->data == pb->data
        {
            s->data = pa->data;
            pa = pa->next;
            pb = pb->next;
            s->next = NULL;
            ctail->next = s;
            ctail = s;
        }

    }

    while (pa)
    {
        LNode *s = new LNode;
        s->data = pa->data;
        s->next = NULL;
        ctail->next = s;
        ctail = s;
        pa = pa->next;
    }

    while (pb)
    {
        LNode *s = new LNode;
        s->data = pb->data;
        s->next = NULL;
        ctail->next = s;
        ctail = s;
        pb = pb->next;
    }

    return Lc;
}

//集合的交集
LinkList Intersection(LinkList La, LinkList Lb)
{
    LinkList Lc;
    InitList(Lc);
    LNode *pa = La->next; //用于遍历La
    LNode *ctail = Lc;    //用于插入Lc
    while(pa)
    {
        LNode *pb = Lb->next; //用于遍历Lb
        while(pb)
        {
            if(pb->data == pa->data)
            {
                LNode *s = new LNode;
                s->data = pb->data;
                s->next = NULL;
                ctail->next = s;
                ctail = s;
                pb = pb->next;
                break;
            }
            pb = pb->next;
        }
        pa = pa->next;
    }

    return Lc;
}

//集合的差集
LinkList Difference(LinkList La, LinkList Lb)
{
    bool Isrepeat = false;
    LinkList Lc;
    InitList(Lc);
    LNode *pa = La->next; //用于遍历La
    LNode *ctail = Lc;    //用于插入Lc
    while(pa)
    {
        LNode *pb = Lb->next; //用于遍历Lb
        while(pb)
        {
            if(pa->data == pb->data)
            {
                Isrepeat = true;
                break;
            }
            pb = pb->next;
        }
        if(!Isrepeat)
        {
            LNode *s = new LNode;
            s->data = pa->data;
            s->next = NULL;
            ctail->next = s;
            ctail = s;
        }
        else
        {
            Isrepeat = false;
        }
        pa = pa->next;
    }

    return Lc;
}

int main()
{
    LinkList La;
    LinkList Lb;
    LinkList Lc;

    Inputlist(La);
    Inputlist(Lb);

    //cout<<Length(La)<<endl;
    //cout<<Length(Lb)<<endl;

    cout << "有序集合A:";
    OutputList(La);
    cout << "有序集合B:";
    OutputList(Lb);
    
    //输出集合的并、交、差
    cout << "集合的并集:";
    Lc = Union(La, Lb);
    OutputList(Lc);

    cout << "集合的交集:";
    Lc = Intersection(La, Lb);
    OutputList(Lc);

    cout << "集合的差集:";
    Lc = Difference(La, Lb);
    OutputList(Lc);
    

    return 0;
}




/********** End **********/