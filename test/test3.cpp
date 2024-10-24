#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> sum(4, vector<int>(3, 1));
        for(int i = 0; i < sum.size(); i++){
            sum[i].push_back(0);
    }
    for(int i = 0; i < sum.size(); i++){
        for(int j =0; j < sum[i].size(); j++){
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}