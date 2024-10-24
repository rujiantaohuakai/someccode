#include<iostream>
#include<bits/stdc++.h>
#include<map>
#include<vector>
#include<string>
using namespace std;
int main()
{
    vector<int> v1;
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    v1.push_back(9);
    int len = v1.size();
    cout << "The length of the vector is: " << len << endl;
    auto it = unique(v1.begin(), v1.end());
    int norepeatlen = it - v1.begin();
    cout << "The length of the vector without repeat elements is: " << norepeatlen << endl;
    cout << *it << endl;
    cout << it - v1.begin() << endl;


    cout << endl;
    cout << endl;

    vector<int> nums = v1;
    nums.pop_back();
    int len2 = nums.size();
    cout << "The length of the vector is: " << len2 << endl;
    auto it2 = unique(nums.begin(), nums.end());
    int norepeatlen2 = it2 - nums.begin();
    cout << norepeatlen2 << endl;
    if(unique(nums.begin(), nums.end()) - nums.begin() == len2) cout << "True";
    //if(norepeatlen2 == len2) cout << "True";
    else cout << "False";


    return 0;
}