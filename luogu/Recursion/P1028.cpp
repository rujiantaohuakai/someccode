#include<iostream>
#define int long long
using namespace std;
int sum = 1;

void recursion(int n){
    for(int i = n/2; i >= 1; i--){
        sum++;
        recursion(i);
    }
}
signed main(){

    int n;
    cin >> n;
    recursion(n);
    cout << sum << endl;
    return 0;
}