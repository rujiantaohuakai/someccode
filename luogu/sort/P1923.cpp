#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> num;
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        num.push_back(x);
    }

    sort(num.begin(), num.end());

    cout << num[k] << endl;

    return 0;
}