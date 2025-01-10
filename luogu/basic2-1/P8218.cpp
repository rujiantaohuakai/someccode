#include<iostream>
#include<vector>
using namespace std;
int main(){

    int n;
    vector<int> a;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(x);
    }

    vector<int> s(n, 0);
    s[0] = a[0];
    for(int i = 1; i < n; i++){
        s[i] = a[i] + s[i-1];
    }

    // for(auto x : s){
    //     cout << x << " ";
    // }

    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int l, r; cin >> l >> r;
        cout << s[r-1] - (l > 1 ? s[l-2] : 0) << endl;
    }

    return 0;
}