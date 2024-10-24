#include<iostream>
using namespace std;
#define  MAXSIZE  100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define Status int
typedef struct
{
	char *base;
	char *top;
	int stacksize;
}SqStack;
Status InitStack(SqStack &S)
{//初始化栈
	S.base=new char[MAXSIZE];
	if(!S.base) return OVERFLOW;
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return OK;
}
Status Push(SqStack &S, char e)
{//入栈
	if(S.top-S.base==S.stacksize)  //栈满
		return ERROR;
	*S.top=e;
	S.top++;
	return OK;
}
Status Pop(SqStack &S)
{//出栈
	if(S.top==S.base)   //栈空
		return ERROR;
	S.top--;
	return OK;
}
char GetTop(SqStack S)
{//取栈顶元素
  	if(S.top!=S.base)
		return *(S.top-1);
  	return ERROR;
}
char Precede(char a,char b)
{//比较符号优先级
	if((a=='('&&b==')')||(a=='='&&b=='='))
		return '=';
	else if(a=='='||a=='('||b=='('||((a=='+'||a=='-')&&(b=='*'||b=='/')))
		return '<';
	else
		return '>';
}

int StackEmpty(SqStack &S) { // 检查栈是否为空
    return S.top == S.base; // 如果栈空，top指针和base指针相等
}

void InfixToSuffix(SqStack op,char s[])
{//将中缀表达式转化为后缀表达式并输出 
    /**************begin************/
	char p[100];  // 存放后缀表达式
    int j = 0;

    for (int i = 0; s[i]!= '\0'; i++) {
        // 遇到数字和小数点直接输出
        while (isdigit(s[i]) || s[i] == '.') {
            p[j++] = s[i++];
        }

        // 遇到左括号直接入栈
        if (s[i] == '(') {
            Push(op, s[i]);
        }

        // 遇到右括号直接出栈，直到栈顶为左括号
        if (s[i] == ')') {
            while (!StackEmpty(op) && GetTop(op) != '(') {
                p[j++] = GetTop(op);
                Pop(op);
            }
            Pop(op); // 左括号出栈但不输出
        }

        // 遇到运算符
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%') {
            while (!StackEmpty(op) && Precede(GetTop(op), s[i]) == '>') {
                p[j++] = GetTop(op);
                Pop(op);
            }
            Push(op, s[i]);
        }
    }

    // 中缀表达式遍历完成，检查栈中是否有未输出字符
    while (!StackEmpty(op)) {
        p[j++] = GetTop(op);
        Pop(op);
    }
    p[--j] = '\0'; // 结束字符串

    cout << "后缀表达式: " << p << endl; // 输出后缀表达式

    
    /**************end************/
}

int main()
{
	SqStack op;
	InitStack(op);      //初始化字符栈op
	Push(op,'=');		//先在栈底放入'='便于以后比较符号优先级	
	char s[100];
	while(cin>>s)
	{
		if(s[0]=='=')
			break;    	//当表达式只有一个“=”时，输入结束 
		else
			InfixToSuffix(op,s); 	//将中缀表达式转化为后缀表达式并输出	
	}
	return 0;
}