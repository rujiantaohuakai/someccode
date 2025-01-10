#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    
    for(int i = 0; i < m; i++){
        int index;
        cin >> index;
        cout << a[index-1] << endl;
    }

    return 0;
}