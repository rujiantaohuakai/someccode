#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        /*
        now表示当前下标，每一次now变化，step++
        检查now后面nums[now]个元素，贪心地选择下一次跳跃最大跳跃长度maxjump，取得maxjump的下标为i
        如果可取得最大下一次跳跃长度的位置+maxjump返回step + 2;否则跳跃到nums[i],step++。重复直到返回step
        */
        int now = 0, step = 0;
        int len = nums.size();
        if(len == 1) return 0;
        if(nums[now] >= len - 1) return 1;
        while(now < len - 1){
            int maxtwojump = 0;
            int maxjump = nums[now];
            int j = nums[now];
            if(now + j >= len - 1) return step + 1;
            int index = -1;
            for(int i = 1; i <= j; i++){
                int temp = maxtwojump;
                maxtwojump = max(maxtwojump, nums[now+i]+i);     //num[now+i]+i-1 表示从now跳跃距离加上下一次跳跃最大距离的总长度
                //上面的maxjump是从now跳跃距离加上下一次跳跃距离的总长度
                if(now + maxtwojump >= len - 1){//如果从下一次跳跃位置开始，已经可以跳到n-1，则返回step + 2;
                    return step + 2;
                }
                if(maxtwojump != temp){//如果最大跳跃距离变化了，记录下一次最大跳跃距离，和下一次跳跃时候所在的下标
                    maxjump = nums[now+i];
                    index = now + i;
                }
            }//for,结束后找到下一次跳跃的起点，或者已经返回结果
            if(index != -1){
                now = index;
                step++;
            }        
        }
        return step;
    }
};


int main(){
    vector<int> nums = {3,4,3,1,0,7,0,3,0,2,0,3};
    Solution sol;
    cout<<sol.jump(nums)<<endl;
    return 0;
}