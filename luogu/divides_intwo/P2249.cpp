#include<iostream>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int nums[100009] = {0};
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    while(k--){
        int search_num;
        cin >> search_num;
        int left = 0;
        int right = n;
        while(left < right){
            int mid = (left + right)/2;
            if(nums[mid] == search_num && nums[mid-1] != search_num){cout << mid+1 << " ";break;}
            else if(nums[mid] < search_num) left = mid + 1;
            else right = mid; 
        }
        if(left >= right) cout << -1 << " ";

    }
    return 0;
}