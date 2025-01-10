#include<bits/stdc++.h>
using namespace std;
int num;

void res(int n){

    //cout << n << " ";
    for(int i = n/2; i >= 1; i--){
        res(i);
    }
    num++;
}

int main(){
    for(int i = 1; i <= 1000; i++)
    {
        res(i);
        cout << num << ",";
        num = 0;
    }
    return 0;
}