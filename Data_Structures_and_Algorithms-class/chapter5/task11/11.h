 #include<iostream>
#define MAXSIZE 100
using namespace std;
typedef struct BiTNode
{//二叉树的双链表存储表示
	char data;          //结点数据域
	bool ischaracter;      //判断结点是否为字符
	struct BiTNode *lchild,*rchild;    //左右孩子指针
}BiTNode,*BiTree;
typedef struct
{//字符栈的存储结构
	char *base;     //栈底指针
	char *top;       //栈顶指针
	int stacksize;   //栈可用的最大容量
}SqStack1;
typedef struct
{//结点栈的存储结构
	BiTree *base;
	BiTree *top;
	int stacksize;
}SqStack2;
void InitStack1(SqStack1 &s)
{//字符栈的初始化
	s.base = new char[MAXSIZE];
    s.top = s.base;
    s.stacksize = MAXSIZE;
}
void InitStack2(SqStack2 &s)
{//结点栈的初始化
	s.base = new BiTree[MAXSIZE];
    s.top = s.base;
    s.stacksize = MAXSIZE;
}
void Push1(SqStack1 &s,char ch)
{//字符入栈操作
    if(s.top - s.base >= s.stacksize)
        return;
	*s.top = ch;
    s.top++;
}
void Push2(SqStack2 &s,BiTree t)
{//结点入栈操作
	if(s.top - s.base >= s.stacksize)
        return;
	*s.top = t;
    s.top++;
}
void Pop1(SqStack1 &s,char &ch)
{//字符出栈操作
	if(s.top == s.base)
        return;
	ch = *--s.top;
}
void Pop2(SqStack2 &s,BiTree &t)
{//结点出栈操作
	if(s.top+1 == s.base)
        return;
	t = *--s.top;
}
char GetTop(SqStack1 s)
{//取字符栈的栈顶元素
	return *(s.top - 1);
}
bool EmptyStack(SqStack1 s)
{//栈的判空操作
	return s.top == s.base;
}
char Precede(char a,char b)
{//判断符号的优先级
	if ((a == '(' && b == ')') || (a == '=' && b == '='))
		return '=';
	else if (a == '(' || a == '=' || b == '(' || (a == '+' || a == '-') && (b == '*' || b == '/'))
		return '<';		//a<b
	else
		return '>';
}
double Operate(double a,char ch,double b)
{//运算操作，返回相应的数值结果
    if(ch == '+')
        return a + b;
    else if(ch == '-')
        return a - b;
    else if(ch == '*')
        return a * b;
    else if(ch == '/')
        return a / b;
    else
        return 0;
}
bool IsCharacter(char ch)
{//判断ch是否为+、-、*、/、(、)、= 这类的字符，是则返回true
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '=')
		return true;
	else
		return false;
}
void CreatExpTree(BiTree &T,BiTree a, BiTree b, char c){
    //创建表达式树
    T = new BiTNode;
    T->data = c;
    T->ischaracter = true;
    if(a != NULL && b != NULL){
        T->lchild = a;
        T->rchild = b;
        T->lchild->ischaracter = false;
        T->rchild->ischaracter = false;
    }
    else{
        T->lchild = NULL;
        T->rchild = NULL;
    }
}
double InOrder(BiTree T)
{//中序遍历二叉树并求表达式的值
	double lvalue = 0;
    double rvalue = 0;
    if(T->lchild == NULL && T->rchild == NULL){
        return T->data - '0';
    }
    else{
        lvalue = InOrder(T->lchild);
        rvalue = InOrder(T->rchild);
        return Operate(lvalue, T->data, rvalue);
    }
}
void CreateBT(char ch[],BiTree &t,SqStack1 optr,SqStack2 expt)
{//创建二叉树
    char *s = &ch[0];
    while(*s != '=' || GetTop(optr)!= '='){
        if(!IsCharacter(*s)){
            BiTree t;
            CreatExpTree(t, NULL, NULL, *s);
            s++;
            Push2(expt,t);
        }
        else{//是运算符
            switch(Precede(GetTop(optr), *s)){
                case '<':
                    Push1(optr, *s);
                    s++;
                    break;
                case '>':
                    char op1;
                    Pop1(optr, op1);
                    BiTree t1,t2,t;
                    Pop2(expt, t2);
                    Pop2(expt, t1);
                    CreatExpTree(t, t1, t2, op1);
                    Push2(expt, t);
                    break;
                case '=':
                    char oprater;
                    Pop1(optr, oprater);
                    s++;
                    break;
            }
        }
        t = expt.base[0];
    }
}
