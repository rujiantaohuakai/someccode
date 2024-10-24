#include<bits/stdc++.h>
#define int long long
using namespace std;
//求正方形和长方形个数Square and rectangle
signed main(){
    int n, m;
    cin >> n >> m;
    int square = 0, rectangle = 0;
    int count = 0;

    /*
        //长度从1开始
    for(int i = 1; i <= n; i++){
        //长度可以循环n-i+1次
        for(int j = 1; j <= n-i+1; j++){
            //宽度从1开始
            for(int k = 1; k <= m; k++){
                //宽度可以循环m-k+1次
                for(int l = 1; l <= m-k+1; l++){
                    count++;
                    //判断是否是正方形
                    if(i == k) square++;
                    else rectangle++;
                }
            }
        }
    }
    */
    //count = ((m+1)*m - (1+m)*m/2) * ((n+1)*n - (1+n)*n/2);上面四个循环化简结果
    count = (m+1)*m/2 * (n+1)*n/2;      //一定是整数，不用四个循环
    //求总正方形数量
    while(n && m){
        square += m * n;
        m--;
        n--;
    }
    //求总长方形数量
    rectangle = count - square;
    cout << square << " " << rectangle << endl;

    return 0;
}