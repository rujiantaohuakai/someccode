#include<iostream>
#include<stack>
using namespace std;
#define MAXSIZE 100
int Ack(int m,int n)
{//Ackermann函数的非递归求值
/**************begin************/
stack<pair<int, int>> s; // 用栈来保存状态
    s.push(make_pair(m, n)); // 将初始参数压入栈

    while (!s.empty()) {
        m = s.top().first;
        n = s.top().second;
        s.pop();

        if (m == 0) {
            n += 1; // 如果 m = 0，返回 n + 1
        } else if (m == 1) {
            n += 1; // 如果 m = 1，返回 n + 1
        } else if (m == 2) {
            n = 2 * n + 3; // 如果 m = 2，返回 2n + 3
        } else {
            // m >= 3, 压入状态以处理; Ack(m - 1, Ack(m, n - 1))
            // 先压入 (m - 1, -1) 状态，表示将要返回 Ack(m - 1, ...)
            s.push(make_pair(m - 1, -1));

            // 然后压入 (m, n - 1) 状态，以便计算 Ack(m, n - 1)
            s.push(make_pair(m, n - 1));
            continue;
        }

        // 当 m 大于 0，且栈为空时直接返回结果
        if (s.empty() && m > 0) {
            return n;
        }
    }
    return n; // 返回结果
    /**************end************/
}
int main()
{
	int m,n;
	while(cin>>m>>n)
    {
        if(m==0&&n==0) break;
        cout<<Ack(m,n)<<endl;
    }
	return 0;
}