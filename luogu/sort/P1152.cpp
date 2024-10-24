#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<ll> num;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        num.push_back(x);
    }

    vector<ll> absval;
    for(int i = 0; i < n - 1; i++){
        absval.push_back(abs(num[i] - num[i+1]));
    }

    // for(int i = 0; i < n - 1; i++){
    //     cout << absval[i] << " ";
    // }
    // cout << endl;

    sort(absval.begin(), absval.end());
    
    // for(int i = 0; i < n - 1; i++){
    //     cout << absval[i] << " ";
    // }
    // cout << endl;

    auto it = unique(absval.begin(), absval.end());

    // for(auto x : absval){
    //     cout << x << " ";
    // }
    // cout << endl;

    absval.erase(it, absval.end());

    //     for(auto x : absval){
    //     cout << x << " ";
    // }
    // cout << endl;
    //absval.erase(unique(absval.begin(), absval.end()), absval.end());

    if(absval.size() != n - 1){
        cout << "Not jolly" << endl;
        return 0;
    }
    else{
        int check = 1;
        for(auto it = absval.begin(); it != absval.end(); it++){
            if( check == *it){
                check++;
            }
            else{
                cout << "Not jolly" << endl;
                return 0;
            }
        }
    }

    cout << "Jolly" << endl;
    // int check = 1;
    // for(auto it = absval.begin(); it != absval.end(); it++){
    //     if( check == *it){
    //         check++;
    //     }
    //     else{
    //         Isjolly = false;
    //         break;
    //     }
    // }





    return 0;
}