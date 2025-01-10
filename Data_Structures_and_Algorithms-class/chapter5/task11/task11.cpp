#include<iostream>
#include "11.h"
using namespace std;

int main(){
    char ch[MAXSIZE];
    while(cin >> ch){
        if(ch[0] == '=') break;
        BiTree t;
        SqStack1 optr;
        SqStack2 expt;
        InitStack1(optr);
        InitStack2(expt);
        Push1(optr, '=');
        CreateBT(ch, t, optr, expt);
        double answer = InOrder(t);
        cout << answer << endl;
    }

    return 0;
}