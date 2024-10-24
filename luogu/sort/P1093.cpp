#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

struct student{
    int id;
    int chinese;
    int math;
    int english;
    int total;
}S[305];

bool cmp(student a, student b)
{
    if(a.total != b.total)
        return a.total > b.total;
    else if(a.chinese != b.chinese)
        return a.chinese > b.chinese;
    else
        return a.id < b.id;
}

int main(){

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> S[i].chinese >> S[i].math >> S[i].english;
        S[i].id = i+1;
        S[i].total = S[i].chinese + S[i].math + S[i].english;
    }
    
    sort(S, S+n, cmp);

    for(int i = 0; i < 5; i++)
        cout << S[i].id << " " << S[i].total << endl;



    return 0;
}