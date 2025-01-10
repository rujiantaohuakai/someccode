#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int max_reach=0;
        for(int i=0;i<n-1;i++){
            if(i>max_reach) return false;
            max_reach=max(max_reach,i+nums[i]);
            if(max_reach>=n-1) return true;
        }
        return false;
    }
};
int main(){
    vector<int> nums={2,3,1,1,4};
    Solution sol;
    if(sol.canJump(nums)) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}