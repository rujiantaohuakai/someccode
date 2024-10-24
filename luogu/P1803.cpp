#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll sum;
struct Match{
    ll bt;
    ll et;
}M[1000003];

bool compare(Match a, Match b)
{
    return a.et < b.et; //按照结束时间递增排序
}

int main(){
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> M[i].bt >> M[i].et;
    }

//思路：按照结束时间递增排序，遍历结构体数组，
//找到下一个开始时间大于等于当前结束时间的元素，
//参加的sum加1，更新结束时间为当前元素的结束时间，
//直到遍历完所有元素。

    sort(M, M + n, compare);
    ll nowend = M[0].et;
    sum++;
    for(ll i = 1; i < n; i++){
        if(M[i].bt >= nowend){
            nowend = M[i].et;
            sum++;
        }
    }

    cout << sum << endl;

    return 0;
}