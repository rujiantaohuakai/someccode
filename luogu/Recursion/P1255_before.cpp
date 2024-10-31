//数楼梯问题，高精度加法法，之前的代码
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
//#define int long long
using namespace std;
int method_w[5003][5000],len=1;
void high_precision_add_method(int k)
{
	//method_w[k]表示第k个楼梯有多少种方法，i是方法数数字的第i位
	for(int i=1;i<=len;i++)
		method_w[k][i] = method_w[k - 1][i] + method_w[k - 2][i];	//每一位相加
	for (int i = 1; i <= len; i++)	//进位
	{
		if (method_w[k][i] >= 10)
		{
			method_w[k][i + 1] += method_w[k][i] / 10;
			method_w[k][i] %= 10;
			if(method_w[k][len+1]) len++;
		}
		//while (method_w[k][len] == 0) len--;
	}
}
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	int n;
	cin >> n;
	method_w[1][1] = 1;
	method_w[2][1] = 2;	//初始化
	for (int i = 3; i <= n; i++)	
		high_precision_add_method(i);
	for (int i = len; i >= 1; i--) printf("%d", method_w[n][i]); // cout << method_w[n][i];
	return 0;
}

