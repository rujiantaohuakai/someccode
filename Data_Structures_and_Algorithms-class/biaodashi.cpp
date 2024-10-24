#include<iostream>
#include<string>
#include<cstdlib>
#include<iomanip>
#define LSElemType string

using namespace std;	//如果出现cout不明确的警告，将using namespace std;重新写一遍

typedef struct LStackNode {
	LSElemType date;
	LStackNode* next;
}LStackNode, * LinkStack;

//链栈初始化
bool InitLStack(LinkStack& S)
{
	S = NULL;
	return true;
}

//链栈入栈
bool LStackPush(LinkStack& S, LSElemType& e)
{
	LStackNode* p = new LStackNode;
	p->date = e;
	p->next = S;
	S = p;			//S为栈顶指针
	return true;
}

//链栈出栈
bool LStackPop(LinkStack& S, LSElemType& e)
{
	if (S == NULL) return false;
	LStackNode* p = S;
	S = S->next;	//栈顶指针下移
	e = p->date;
	delete p;
	return true;
}

//取栈顶元素
LSElemType LSGetTopElem(LinkStack S)
{
	if (S != NULL)		//栈非空
		return S->date;
	return "0";
}

//输入栈
void InputLStack(LinkStack& S)
{
	LSElemType elem;
	while (cin >> elem)
	{
		LStackPush(S, elem);
		if (cin.get() == '\n') break;
	}
}

//输出栈
void OutputLStack(LinkStack& S)
{
	LSElemType elem;
	while (S != NULL)
	{
		LStackPop(S, elem);
		cout << elem << " ";
	}
	cout << endl;
}

//判断输入的是否是运算符
bool IsOperator(LSElemType c)
{
	//if (c.compare("+") == 0 || c.compare("-") == 0 || c.compare("*") == 0 || c.compare("/") == 0)
	//	return true;
	//return false;
	return c == "+" || c == "-" || c == "*" || c == "/" || c == "(" || c == ")" || c == "#";
}

//比较运算符优先级
string Precede(string theta1, string theta2)	//theta1为栈顶元素,theta2为输入的元素
{
	if ((theta1 == "(" && theta2 == ")") || (theta1 == "#" && theta2 == "#"))
		return "=";
	else if (theta1 == "(" || theta1 == "#" || theta2 == "(" || (theta1 == "+" || theta1 == "-") && (theta2 == "*" || theta2 == "/"))
		return "<";		//theat1<theat2
	else
		return ">";
}

double Operate(double a, string theta, double b)
{
	if (theta.compare("+") == 0)
		return a + b;
	else if (theta.compare("-") == 0)
		return a - b;
	else if (theta.compare("*") == 0)
		return a * b;
	else
		return a / b;
	
}

int main()
{	
	//测试数据，注意：要用空格分开每个字符串(string)
	//"1 * 3 + 4 / 2 * 2 - 10 + 13 #"				result = 10
	//"1 * 3 + 4 / 2 * 2 * ( 13 - 10 ) #"			result = 15
	//"3 * ( 18 - 2 ) / 4 #"						result = 12
	//( 15 - 5 ) / 5 * 3 - 4 #
	//3 * ( 15 - 5 ) / 2 + 4 #

	int T = 1; //输入三次
	while (T <= 3)
	{

		cout << "测试 " << T << " 请输入表达式：";
		T++;


		LinkStack Operator;			//用于存储操作符
		LinkStack Operand;			//用于存储操作数
		InitLStack(Operator);
		InitLStack(Operand);		//初始化
		LSElemType c = "#";
		LStackPush(Operator, c);	//操作符栈中先压入 #
		while (cin >> c)			//输入
		{

			if (!IsOperator(c))			//如果c是操作数
			{
				LStackPush(Operand, c);		//压入操作数栈
				cout << c;
			}
			else
			{
				string topelem = LSGetTopElem(Operator);	//取出操作符栈的尾元素
				string precedence = Precede(topelem, c);	//比较优先级
				if (precedence == "<")
					//如果尾元素优先级小于新的操作符，将新的操作符压入操作符栈，比如已输入1 + 2，再输入*时，*压入操作符栈，因为*优先级更高
				{
					LStackPush(Operator, c);
					cout << c;
				}
				else if (precedence == ">")
					//如果尾元素优先级大于新的操作符，先计算现有的数据，再将新的操作符压入操作符栈，如已输入1 + 2，在输入+时候，先计算1+2，将结果3压入操作数栈，再将+压入操作符栈;
					//注意：可能之前还有比新操作符优先级高的操作符，需要继续进行计算
				{
					do
					{
						string a, b, theta;
						LStackPop(Operator, theta);
						LStackPop(Operand, b);
						LStackPop(Operand, a);
						double num = Operate(stod(a), theta, stod(b));
						string strnum = to_string(num);
						LStackPush(Operand, strnum);
						//cout << strnum << endl;

						topelem = LSGetTopElem(Operator);
						precedence = Precede(topelem, c);
					} while (precedence == ">");	//如果之前还有运算等级高的运算符，就接着运算、
					//while (Operator->date != "#"); 这行代码不行，因为之前可能会出现括号( ),导致无法跳出循环
					if (precedence == "=")	//括号配对
					{
						LStackPop(Operator, c);
					}
					else   //将新操作符压入操作符栈
					{
						LStackPush(Operator, c);
						cout << c;
					}
				}
				else     //如果precedence == "=" 括号配对
				{
					LStackPop(Operator, c);
					cout << c;
				}
			}
			if (cin.get() == '\n') break;	//输入回车终止表达式的输入
		}
		LSElemType str_result;
		LStackPop(Operand, str_result);
		double result = stod(str_result, 0);
		cout << fixed << setprecision(2);		//取出最后一个操作数（结果），并转为double类型，保留两位小数
		cout << " = " << result << endl;




	}
	

	return 0;
}