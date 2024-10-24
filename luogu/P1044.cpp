//求栈的输出序列个数
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;   //n个数进栈
    // int dp[20][20] = {{0}};     //dp[i][j]表示栈里还有i个元素，队列有j个元素时，有多少种输出序列 dp[0][n]即为答案
    // //dp[i][j] = dp[]
    // //队列内没有数的时候，输出序列只有一种
    // for(int i = 0; i <= n; i++){
    //     dp[i][0] = 1;
    // }
    // //要推dp[0][n]
    // //dp[1][1] = dp[0][1] + dp[2][0] = 1 + 1 = 2
    // //dp[2][1] = dp[1][1] + dp[3][0] = 2 + 1 = 3
    // //dp[3][1] = dp[2][1] + dp[4][0] = 3 + 1 = 4
    // for(int j = 1; j <= n; j++) //队列有j个元素
    //     for(int i = 0; i <=n; i++){ //栈里有i个元素
    //         if(i >= 1){
    //             //栈中还有元素
    //             dp[i][j] = dp[i-1][j] + dp[i+1][j-1]; //出栈和入栈两种情况
    //         }
    //         if(i == 0){
    //             //栈内没有元素
    //             dp[i][j] = dp[i+1][j-1]; //入栈一种情况
    //         }
    //     }

    // cout << dp[0][n] << endl;
    cout << fixed << setprecision(0);
    double sum = 0;
    double cup = 1;
    for(double i = 2*n; i > n; i--){
        cup *= i;
    }
    cout << cup << endl;
    double cdown = 1;
    for(double i = n; i > 1; i--){
        cdown *= i;
    }
    cout << cdown << endl;
    //sum = 1/(n+1)*C(n,2n);
    sum = 1.0/(n+1)*cup/cdown;
    cout << sum << endl;
    return 0;
}

