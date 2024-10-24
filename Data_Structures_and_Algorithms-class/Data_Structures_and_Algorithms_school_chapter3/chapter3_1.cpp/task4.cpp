#include<iostream>
using namespace std;
#define  MAXSIZE  100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef struct
{
	int *base;
	int *top;
	int stacksize;
}SqStack;
int InitSqStack(SqStack &S)
{//栈的初始化
	S.base=new int[MAXSIZE];
	if(!S.base) return OVERFLOW;
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return OK;
}
int Push(SqStack &S,int e)
{//入栈
	if(S.top-S.base==S.stacksize)  //栈满
		return ERROR;
	*S.top=e;
	S.top++;
	return OK;
}
int Pop(SqStack &S)
{//出栈
	if(S.top==S.base)  //栈空
		return ERROR;
	S.top--;
	return OK;
}
int GetTop(SqStack S)
{//取栈顶元素
	if(S.top==S.base)  //栈空
		return ERROR;
  	return *(S.top-1);
}
void InOutS(SqStack &S,int a[],int n)
{//入栈和出栈的基本操作
	/**************begin************/
    for(int i = 0; i < n; i++){
        if(a[i] != -1){
            Push(S, a[i]);
        }
        else{
            if(S.top == S.base){
                cout << "POP ERROR" << endl;
                break;
            }
            else{
                int x = GetTop(S);
                Pop(S);
                cout << x << endl;
            }
        }
    }
	
		/**************end************/
}
int main()
{
	int n;
	while(cin>>n)
	{
      	if(n==0) break;
      	SqStack S;
		InitSqStack(S);
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];  //整数序列
		InOutS(S,a,n);
	}
	return 0;
}