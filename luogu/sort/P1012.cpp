#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long

using namespace std;

string num[21];

bool cmp(string a, string b){
    ll lena = a.length()-1, lenb = b.length()-1;
    ll tema = lena, temb = lenb;
    while(tema >= 0 && temb >= 0){
        if(a[tema] != b[temb])
            return a[tema] > b[temb];
        tema--;
        temb--;
    }
    if(tema < 0 && temb >= 0){
        //如果a的长度比b短,比较a的第一位和b的lena+1位
        // if(a[lena] >= b[temb]) return true;
        // else return false;
        return a[lena] >= b[temb];
    }
    if(temb < 0 && tema >= 0){
        // if(b[lenb] >= a[tema]) return true;
        // else return false;
        return b[lenb] >= a[tema];
    }
    return lena < lenb;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        reverse(num[i].begin(), num[i].end());  //逆序存储数字
    }
    sort(num, num + n, cmp);
    
    for(int i = 0; i < n; i++){
        reverse(num[i].begin(), num[i].end());  //逆序存储数字
    }
    for(int i = 0; i < n; i++)
        cout << num[i];
    
    return 0;
}