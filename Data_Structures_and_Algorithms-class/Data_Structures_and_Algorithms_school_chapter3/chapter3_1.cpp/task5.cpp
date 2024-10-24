#include <iostream>
#include<iomanip>
#include <string>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;
typedef struct
{//数字栈
	double *base;
	double *top;
	int  stacksize;
}SqStack;
int InitStack(SqStack &S)
{//数字栈初始化
	S.base=new double[MAXSIZE];
	if(!S.base) return OVERFLOW;
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return OK;
}
int Push(SqStack &S,double e)
{//数字栈入栈
	if(S.top-S.base==S.stacksize)  //栈满
        return ERROR;
	*S.top=e;
	S.top++;
	return OK;
}
int Pop(SqStack &S)
{//数字栈出栈
	if(S.top==S.base)    //栈空
		return ERROR;
	S.top--;
	return OK;
}
double GetTop(SqStack S)
{//数字栈取栈顶元素
	if(S.top!=S.base)
		return *(S.top-1);
  	return ERROR;
}
double Calculate(double a,char op,double b)
{//算术表达式的求值
    switch(op)
    {
        case '+':return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':return a/b;
    }
}
double EvaluateExpression(SqStack OPND,char s[])
{//后缀算术表达式求值
	/**************begin************/
	char *c = s;
	string num = "";
	while(*c != '='){
		if(isdigit(*c) || *c == '.'){
			num += *c;
			c++;
		}
		else if(*c == ' '){
			Push(OPND, stod(num));
			num.clear();
			c++;
		}
		else{
			if(!num.empty())
				Push(OPND, stod(num));
			char op = *c;
			double num1 = GetTop(OPND);
			Pop(OPND);
			double num2 = GetTop(OPND);
			Pop(OPND);
			double result = Calculate(num2,op,num1);
			Push(OPND, result);
			num.clear();
			c++;
		}
	}
	return GetTop(OPND);


		/**************end************/
}

int main()
{
	char s[100];
	//用字符数组存储表达式，每个数组元素仅存一个字符
	while(1)
	{
		cin.getline(s,100);		//输入一行含空格的后缀表达式
		if(s[0]=='=') 
			break;				//当表达式只有一个"="时，输入结束
		SqStack OPND;
		InitStack(OPND);		//初始化数字栈
		cout<<fixed<<setprecision(2)<<EvaluateExpression(OPND,s)<<fixed<<setprecision(2)<<endl;
	}
	return 0;
}