#include <iostream>
#include<iomanip>
#include<cstring>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;
typedef struct
{//运算符栈
    char *base;
	char *top;
	int stacksize;
}SqStack1;
int InitStack1(SqStack1 &S)
{//运算符栈初始化
	S.base=new char[MAXSIZE];
	if(!S.base) return OVERFLOW;
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return OK;
}
int Push1(SqStack1 &S, char e)
{//运算符栈入栈
	if(S.top-S.base==S.stacksize)  //栈满
		return ERROR;
	*S.top=e;
	S.top++;
	return OK;
}
int Pop1(SqStack1 &S)
{//运算符栈出栈
	if(S.top==S.base)      //栈空
		return ERROR;
	S.top--;
	return OK;
}
char GetTop1(SqStack1 S)
{//运算符栈取栈顶元素
	if(S.top!=S.base)
		return *(S.top-1);
  	return ERROR;
}
typedef struct
{//操作数栈
	double *base;
	double *top;
	int  stacksize;
}SqStack2;
int InitStack2(SqStack2 &S)
{//操作数栈初始化
	S.base=new double[MAXSIZE];
	if(!S.base) return OVERFLOW;
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return OK;
}
int Push2(SqStack2 &S,double e)
{//操作数栈入栈
	if(S.top-S.base==S.stacksize)     //栈满
        return ERROR;
	*S.top=e;
	S.top++;
	return OK;
}
int Pop2(SqStack2 &S)
{//操作数栈出栈
	if(S.top==S.base)           //栈空
		return ERROR;
	S.top--;
	return OK;
}
double GetTop2(SqStack2 S)
{//操作数栈取栈顶元素
	if(S.top!=S.base)
		return *(S.top-1);
  	return ERROR;
}
double Calculate(double a,char op,double b)
{//计算表达式“a op b”的值
    switch(op)
    {
        case '+':return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':return a/b;
    }
}

char Precede(char a,char b)
{//比较运算符a和b的优先级
	if((a=='('&&b==')')||(a=='='&&b=='='))
		return '=';
	else if(a=='('||a=='='||b=='('||(a=='+'||a=='-')&&(b=='*'||b=='/'))
		return '<';
	else
		return '>';
}


double EvaluateExpression(SqStack1 OPTR,SqStack2 OPND,char s[])
{//算术表达式求值的算符优先算法
	/**************begin************/
    char *c = s;
    string number;
    while(*c != '\0'){
        //判断是操作数还是操作符
        if(isdigit(*c) || *c == '.'){
            number += *c;
            c++;
        }
        else{
            //操作数入栈
            if(number.size() > 0)//上一个字符是操作数
                Push2(OPND, stod(number));
            number.clear();
            //操作符入栈
            char top = GetTop1(OPTR);
            //如果栈顶操作符优先级高于当前操作符，弹出两个操作数，用Calculate(x, top, y)计算结果，压入操作数栈
            //如果栈顶操作符优先级等于当前操作符（括号或者等于号）,弹出栈顶运算符
            //如果栈顶操作符优先级低于当前操作符，压入栈顶操作符
            if(Precede(top, *c) == '<'){
                Push1(OPTR, *c);
                c++;
            }
            else if(Precede(top, *c) == '='){
                Pop1(OPTR);
                c++;
            }
            else if(Precede(top, *c) == '>'){//栈顶操作符高于当前操作符
                do{
                    double num1 = GetTop2(OPND);
                    Pop2(OPND);
                    double num2 = GetTop2(OPND);
                    Pop2(OPND);
                    double result = Calculate(num2, top, num1);
                    Push2(OPND, result);
                    Pop1(OPTR);
                    top = GetTop1(OPTR);
                }while(Precede(top, *c) == '>');
            }
        }
    }

    //返回操作数栈顶元素
    return GetTop2(OPND);
		/**************end************/
}


int main()
{//设OPTR和OPND分别为运算符栈和操作数栈
	SqStack1 OPTR;
	InitStack1(OPTR);    //初始化OPND栈
	SqStack2 OPND;
	InitStack2(OPND);    //初始化OPTR栈
	Push1(OPTR,'=');     //将表达式起始符“=”压入OPTR栈        
	char s[100];
	while(cin>>s)
	{//循环读入多组数据
		if(s[0]=='=') 
		   break;    //当表达式只有一个“=”时，输入结束 
		//输出中缀算术表达式的值
		cout<<fixed<<setprecision(2)<<EvaluateExpression(OPTR,OPND,s)<<fixed<<setprecision(2)<<endl;
		
	}
	return 0;
}