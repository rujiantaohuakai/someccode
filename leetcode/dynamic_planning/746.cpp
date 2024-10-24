#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //动态规划 n_cost = min(n-1_cost, n-2_cost) + cost[n];
        int len = cost.size();
        cost.push_back(0);
        cost.push_back(0);
        int lowcost[1001] = {0};    //从lowcost下标往上走所需要的最小花费
        lowcost[0] = cost[0];
        lowcost[1] = cost[1];
        for(int i = 2; i <= len+1; i++){
            lowcost[i] = min(lowcost[i-1], lowcost[i-2]) + cost[i]; 
        }
        return min(lowcost[len], lowcost[len+1]);
    }
};

int main(){
    Solution sol;
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout<<sol.minCostClimbingStairs(cost)<<endl;


    return 0;
}