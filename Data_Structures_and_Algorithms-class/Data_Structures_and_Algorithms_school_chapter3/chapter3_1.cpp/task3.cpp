#include <iostream>
#include <cstring>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;
typedef struct
{
    char *base;
	char *top;
	int stacksize;
}SqStack;
int InitStack(SqStack &S)
{//栈初始化
	S.base=new char[MAXSIZE];
	if(!S.base) return OVERFLOW;
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return OK;
}
int Push(SqStack &S, char e)
{//入栈
	if(S.top-S.base==S.stacksize)  //栈满
		return ERROR;
	*S.top=e;
	S.top++;
	return OK;
}
int Pop(SqStack &S)
{//出栈返回栈顶元素
	if(S.top==S.base)      //栈空
		return ERROR;
	S.top--;
	return *S.top;
}
int IsPalindrome(SqStack &S,char *t)
{//判断栈的回文字符序列
	/**************begin************/
    char c[100];
    int i = 0;
    char *p = t;

    while(*p != '\0'){
        Push(S, *p);
        p++;
    }

    while(S.top != S.base){
        c[i] = Pop(S);
        i++;
    }
    c[i] = '\0';
    if(strcmp(c, t) == 0) return 1;
    else return 0;

	/**************end************/
}
int main()
{
  	char t[100];
	while(cin>>t&&t[0]!='0')
	{
		SqStack S;
		InitStack(S);
		if(IsPalindrome(S,t)==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}