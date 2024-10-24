#include <iostream>
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
{//初始化栈
	S.base=new char[MAXSIZE];
	if(!S.base) return OVERFLOW;
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return OK;
}
int Push(SqStack &S)
{//入栈
	S.top++;
	return OK;
}
int Pop(SqStack &S)
{//出栈
	S.top--;
	return OK;
}
int IsEmpty(SqStack S)
{//判断栈是否为空，空返回1，否则返回0
	return S.top==S.base;
}
bool Judge(char a[],SqStack &S)
{//栈的可操作判断
	/**************begin************/
	char *elem = a;
	while(*elem != '\0'){
		if(*elem == 'I'){
			Push(S);
			elem++;
		}
		else if(*elem == 'O'){
			if(IsEmpty(S)){
				return false;
			}
			else{
				Pop(S);
				elem++;
			}
		}
	}

	if(!IsEmpty(S)) return false;
	else return true;
	/**************end************/
}
int main()
{
    char a[100];
    while(cin>>a)
    {
        if(a[0]=='0') break;
        SqStack op;
        InitStack(op);
        if(Judge(a,op)) cout<<"TRUE"<<endl;
        else cout<<"FALSE"<<endl;
    }
    return 0;
}