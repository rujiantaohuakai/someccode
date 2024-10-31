#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    while(cin >> str){
        if(str == "0") break;
        cout << str << endl;
    }
    return 0;
}