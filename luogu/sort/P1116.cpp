#include<bits/stdc++.h>
#define ll long long
using namespace std;
//4321 4312 4132 1432 1423 1243 1234
//42315 42135 41235 14235 12435 12345
int main(){
    vector<ll> carriges;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        ll id;
        cin >> id;
        carriges.push_back(id);
    }
    ll movetims = 0;
    int moveid = 1;
    while(moveid <= n){
        auto it = find(carriges.begin(), carriges.end(), moveid);   //指向当前移动的车厢的下标的迭代器
        movetims += it - carriges.begin() - moveid + 1;
        //将当前车厢移动到前面
        while(it != carriges.begin() + moveid - 1){
            swap(*it, *(it-1));
            it--;
        }
        moveid++;
    }

    cout << movetims << endl;

    return 0;
}