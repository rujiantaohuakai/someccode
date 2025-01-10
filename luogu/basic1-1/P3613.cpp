#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,q,tag,i,j,k;
    cin >> n >> q;
    map<int, map<int, int>> mp;
    for(int t = 0; t < q; t++){
        cin >> tag;
        if(tag == 1){
            cin >> i >> j >> k;
            mp[i][j] = k;
        }
        else{
            cin >> i >> j;
            cout << mp[i][j] << endl;
        }
    }
    
    return 0;
}