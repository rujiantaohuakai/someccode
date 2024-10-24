#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
 main()
{
    ll n;
    ll height;
    ll sum;
    vector<ll>num;
    cin >> n;
    for(ll i = 1; i <= n; i++)
    {
        cin >> height;
        num.push_back(height);
    }

    for(ll i = 1; i < n; i++)
    {
        sort(num.rbegin(), num.rend());
        num[n-i-1] += num[n-i];
        //cout << num[n-i-1] << endl;
        num.pop_back();
        sum += num[n-i-1];
    }
    if(num.empty())
        cout << "num is empty" << endl;
    cout << sum << endl;
    return 0;
}