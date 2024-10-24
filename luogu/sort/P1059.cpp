#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;

int main(){
    ll n, m;
    vector<ll> num;
    ll number;
    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> number;
        num.push_back(number);
    }

    sort(num.begin(), num.end());

    num.erase(unique(num.begin(), num.end()), num.end());
    m = num.size();
    cout << m << endl;
    for(auto x: num)
        cout << x << " ";

    return 0;
}