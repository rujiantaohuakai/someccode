#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int n, sum = 0;
    // cin >> n;
    // int num[10001];
    // for(int i = 0; i < n; i++){
    //     cin >> num[i];
    //     sum += num[i];
    // }

    // int minn = sum, sumr = 0;
    // for(int i = 0; i < n; i++){
    //     sumr += num[i];
    //     minn = min(minn, abs(sumr - (sum - sumr)));
    // }

    // cout << minn << endl;

    deque<int> dq;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        dq.push_back(x);
    }
    int suml = 0, sumr = 0;
    suml = dq.front();
    dq.pop_front();
    sumr = dq.back();
    dq.pop_back();
    while(!dq.empty()){
        if(suml > sumr){
            sumr += dq.back();
            dq.pop_back();
        }
        else if(suml < sumr){
            suml += dq.front();
            dq.pop_front();
        }
        if(suml == sumr){
            sumr += dq.back();
            dq.pop_back(); 
        }
    }

    int minn = abs(suml - sumr);
    cout << minn << endl;
    return 0;
}