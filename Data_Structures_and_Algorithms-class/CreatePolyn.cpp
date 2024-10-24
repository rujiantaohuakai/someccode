#include<iostream>
using namespace std;

typedef struct PNode{
    float coef;			//系数
    int expn;			//指数
    struct PNode *next;			//指向下一项
}PNode, *Polynomial;

int CreatePolyn(Polynomial &P, int n)
{//输入n项的系数和指数，建立表示多项式的有序链表P
   P=new PNode; 
   P->next=NULL;			//先建立一个带头结点的单链表 
   for(int i=1;i<=n;++i)		//依次输入n个非零项
   {
      PNode *s=new PNode;			//生成新结点 
      cin>>s->coef>>s->expn;		//输入系数和指数 
      PNode *pre=P;			//pre用于保存q的前驱，初值为头结点 
      PNode *q=P->next;			//q初始化，指向首元结点
      while(q && q->expn<s->expn)	//找到第一个大于输入项指数的项*q
      {
         pre=q; 
         q=q->next; 
      }				//while 
      s->next=q;			//将输入项s插入到q和其前驱结点pre之间 
      pre->next=s; 
   }				//for 
} 

int main()
{
   int n;
   Polynomial P;
   cout<<"Enter the number of terms: ";
   cin>>n;
   CreatePolyn(P,n);
   cout<<"The Polynomial is: ";
   while(P)
   {
      cout<<P->coef<<"x^"<<P->expn<<" + ";
      P=P->next;
   }
   cout<<endl;
   return 0;
}