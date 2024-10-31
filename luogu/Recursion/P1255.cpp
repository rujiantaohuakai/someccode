#include<iostream>
#include<vector>
using namespace std;
//无高精度加法
int main(){
    int N;
    int step[5010] = {0};
    cin >> N;
    //一次上一阶或一次上两阶
    //递推求解 step[i] = step[i-1] + step[i-2];
    step[1] = 1;
    step[2] = 2;
    for(int i = 3; i <=N; i++){
        step[i] = step[i-1] + step[i-2];
    }

    cout << step[N] << endl;

    return 0;
}