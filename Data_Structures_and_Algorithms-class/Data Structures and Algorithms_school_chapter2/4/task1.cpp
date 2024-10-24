#include <iostream>
#include <string>
using namespace std;
typedef struct LNode
{
    int coe;    //系数coe
    int exp;    //指数exp
    struct LNode *next;
}LNode,*LinkList;
void CreatePolynomial(LinkList &L,int n)
{//按指数exp从大到小存多项式,指数相同的项合并
    L=new LNode;
    L->next=NULL;
    for(int i=0;i<n;i++)
    {
        LinkList p=new LNode;
        cin>>p->coe>>p->exp;
        LinkList pre=L,cur=L->next;      //pre和cur是多项式链表的工作指针，分别初始化为头结点和首元结点
		while(cur && p->exp < cur->exp)    //若待插入项的指数小于当前结点的指数，指针pre指向当前结点，当前结点的指针cur后移
		{
			pre=cur;
			cur=cur->next;
		}       //循环结束后：p的指数大于cur的指数或者p的指数等于cur的指数,或者cur为NULL
        if(cur && p->exp == cur->exp)    //指数相等时，系数相加
        {
            cur->coe += p->coe;
            delete p;
        }
        else    //指数不等时，插入到pre和cur之间
        {
            p->next=cur;
            pre->next=p;
        }
	}
}
void OutputPolynomial(LinkList L)
{//输出多项式
	if(!L||!L->next) cout<<0;
	LinkList p=L->next;     //p是多项式链表的工作指针,初始化为首元结点
	while(p)
	{
		if(p == L->next)     //p指向首元结点时，根据指数的情况输出多项式
        {
			if (p->exp != 0)
				cout<<p->coe<<"x^"<<p->exp;
			else
				cout<<p->coe;
		}
		else      //p指向其他结点时，根据系数的正负和指数的情况输出多项式
        {
			if(p->coe > 0) cout << "+";
			if(p->exp != 0)
				cout<<p->coe<<"x^"<<p->exp;
			else
				cout<<p->coe;
		}
		p=p->next;
	}
	cout<<endl;
}
LinkList Add(LinkList LA,LinkList LB)
{//多项式的加法运算
/**************begin************/
    //思路：从LB中找到比LA当前结点指数大的结点，将其插入到LA中，删除LB中相应结点
    //如果系数相等，系数相加，删除LB中相应结点，如果系数相加后为零，则删除LA中相应结点
	//cout<<LA->next->coe<<endl;
    LNode *pa=LA->next;
    LNode *pb=LB->next;
    LNode *preva = LA;
    LNode *prevb = LB;
    while(pa&&pb)
    {
        if(pa->exp > pb->exp)   //如果当前pa的指数大于当前pb的指数，pa指针向后移动
        {
           pa = pa->next;
           preva = preva->next;   
        }
        else if(pa->exp < pb->exp)
        {
            prevb->next = pb->next;     //将pb结点从LB链表中删除
            preva->next = pb;           //将pb结点插入到LA链表中
            pb->next = pa;
            preva = pb;
            pb = prevb->next;
        }
        else    //指数相等时，系数相加
        {
            pa->coe += pb->coe;
            prevb->next = pb->next;     //将pb结点从LB链表中删除
            delete pb;
            pb = prevb->next;
            if(pa->coe==0)              //如果系数为零，则删除LA中该结点
            {
                preva->next = pa->next;
                delete pa;
                pa = preva->next;
            }
            else
            {
                preva = pa;
                pa = pa->next;
            }
        }
    }
    if(!pa)
    {
        preva->next = pb;
    }
    delete LB;
    return LA;

    /**************end************/
}
void Minus(LinkList LA,LinkList LB)
{//多项式的减法
/**************begin************/
    //其实LB只在头结点和首元结点处操作即可，不用新建*pb和*prevb指针
    //不过新建*pb和*prevb可以更好的理解算法的过程
	LNode *pa=LA->next;
    LNode *preva = LA;
    while(pa&&LB->next)     //LA不为空同时LB不为空
    {
        if(pa->exp > LB->next->exp)
        {
            pa = pa->next;
            preva = preva->next;
        }
        else if(pa->exp < LB->next->exp)
        {
             if(LB->next->coe < 0)
                 LB->next->coe *= -1;    //负数转化为正数再加入到LA链表中
            preva->next = LB->next;      //将LB首元结点链接到LA链表中
            LB->next = LB->next->next;   //删除LB中相应结点
            preva->next->next = pa;
            preva = preva->next;
        }
        else    //指数相等时，系数相减
        {
            pa->coe -= LB->next->coe;
            LB->next = LB->next->next;   //删除LB中相应结点(首元结点)
            if(pa->coe == 0)
            {
                preva->next = pa->next;
                delete pa;
                pa = preva->next;
            }
            else
            {
                preva = pa;
                pa = pa->next;
            }
        }
    }
    if(!pa)     //将LB链表中剩余结点链接到LA链表中
    {   
        LNode *p = LB->next;
        while(p)    //将LB链表中的负数转化为正数再加入到LA链表中
        {
            if(p->coe < 0)
                p->coe *= -1;
            p = p->next;
        }
        preva->next = LB->next;      
    }
    delete LB;
    OutputPolynomial(LA);

    /**************end************/
}
void Mul(LinkList LA,LinkList LB)
{//多项式的乘法
/**************begin************/
    //思路：定义mul链表，将LA每一项与LB相乘的到一个链表，与mul链表相加，最后输出mul链表
    LNode *pa = LA->next;
    LinkList mul = new LNode;
    mul->next = NULL;
    while(pa)
    {
        LinkList p = new LNode;     //p用于存储LA当前项与LB所有项乘积的结果
        p->next = NULL;
        LNode *ptail = p;
        LNode *pb = LB->next;
        while(pb)         //LB本来就是有序的，LB每一项一次乘相同的LA项，结果也是有序的
        {
            LNode *q = new LNode;
            q->exp = pa->exp + pb->exp;
            q->coe = pa->coe *pb->coe;
            if(q->coe == 0)     //如果系数乘积为零，则删除该结点    
                delete q;
            else
            {
                //尾插法将q插入p链表中
                ptail->next = q;
                ptail = q;
            }
            pb = pb->next;
        }
        //将p链表与mul链表相加,相加之后p链表已经被删除
        if(mul->next == NULL)
            mul->next = p->next;
        else
            Add(mul, p);
        pa = pa->next;
    }
    OutputPolynomial(mul);

    /**************end************/
}
void Diff(LinkList L)
{//多项式的求导运算
	LinkList p=L->next;  //p是链表L的工作指针，初始化为首元结点
	LinkList r=NULL;  //r是删除操作的辅助指针
	while(p)
	{
		p->coe*=p->exp;
		p->exp--;
		if(p->exp<0)  //所有数据的指数大于等于0
        {
			r=p;
			p=p->next;
			delete r;
		}
		else
		{
			p=p->next;
		}
	}
	OutputPolynomial(L);
}
void Opt(LinkList &LA,LinkList &LB,string s)
{//依据字符选择多项式的加法、减法、乘法和求导运算
    if(s=="+") OutputPolynomial(Add(LA, LB));
    if(s=="-") Minus(LA, LB);
    if(s=="*") Mul(LA, LB);
    if(s=="'")
    {
        Diff(LA);
        Diff(LB);
    }
}
int main()
{
    int n;    //总计有n组数据
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        LinkList LA,LB;
        CreatePolynomial(LA,a);
        CreatePolynomial(LB,b);
        string s;
        cin>>s;
        Opt(LA,LB,s);
    }
    return 0;
}