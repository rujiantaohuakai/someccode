#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x = 2;
    vector<int> nums;

    long long sum = 0;

    while(n >= sum){
        nums.push_back(x);
        sum += x;
        x++;
    }

    // for(auto i : nums){
    //     cout << i << " ";
    // }

    if(sum != n){
        if(sum - n == 1){
            nums.erase(nums.begin(), nums.begin()+1);
            *(nums.end() - 1) += 1;
        }
        else{
            int k = sum - n;
            //删除nums中等于k的元素,等于删除下标为k-2的元素     2 3 4 5 6 ... k ...
            nums.erase(nums.begin()+k-2, nums.begin()+k-1);
        }
    }
    


    for(auto i : nums){
        cout << i << " ";
    }

    //高精度将nums中的元素相乘
    








    return 0;
}