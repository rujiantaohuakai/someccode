/*
数字三角形
写一个程序来查找从最高点到底部任意处结束的路径，使路径经过数字的和最大。
每一步可以走到左下方的点也可以到达右下方的点。

输入格式
第一个行一个正整数 
r
r ,表示行的数目。

后面每行为这个数字金字塔特定行包含的整数。

输出格式
单独的一行,包含那个可能得到的最大的和。

输入：
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5 
输出：
30
【数据范围】
1≤r≤1000，所有输入在 [0,100] 范围内。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int r;
    cin >> r;
    vector<vector<int>> triangle(r);
    for(int i=0;i<r;i++){
        for(int j=0;j<=i;j++){
            int num;
            cin >> num;
            triangle[i].push_back(num);
        }
    }

    // //输出triangle
    // for(auto row:triangle){
    //     for(auto num:row){
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }

    vector<vector<int>> dp(r,vector<int>(r,0));
    //dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j]
    dp[0][0] = triangle[0][0];
    for(int i = 1; i < r; i++){
        for(int j = 0; j <= i; j++){
                if(j == 0) dp[i][j] = dp[i-1][j] + triangle[i][j];
                else if(j == i) dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                else dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
        }
    }
    cout << *max_element(dp[r-1].begin(), dp[r-1].end());
    return 0;
}


