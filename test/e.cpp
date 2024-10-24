#include <bits/stdc++.h>
using namespace std;

string multiply(const string& num1, const string& num2) {
    if (num1 == "0" || num2 == "0") return "0";

    vector<int> result(num1.size() + num2.size(), 0);

    for (int i = num1.size() - 1; i >= 0; --i) {
        for (int j = num2.size() - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    string resultStr;
    for (int num : result) {
        if (!(resultStr.empty() && num == 0)) {
            resultStr.push_back(num + '0');
        }
    }

    return resultStr.empty() ? "0" : resultStr;
}

string multiplyVector(const vector<int>& nums) {
    string product = "1"; // 初始化为1，因为乘法的单位元是1
    for (int num : nums) {
        if (num == 0) return "0"; // 如果其中包含0，结果就是0
        product = multiply(product, to_string(num));
    }
    return product;
}

int main() {
    int n;
    cin >> n;
    int x = 2;
    vector<int> nums;

    long long sum = 0;

    while (n >= sum) {
        nums.push_back(x);
        sum += x;
        x++;
    }
    
    if (sum != n) {
        if (sum - n == 1) {
            nums.erase(nums.begin(), nums.begin() + 1);
            *(nums.end() - 1) += 1;
        } else {
            int k = sum - n;
            // 删除nums中等于k的元素,等于删除下标为k-2的元素
            nums.erase(nums.begin() + k - 2, nums.begin() + k - 1);
        }
    }

    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;

    // 高精度将nums中的元素相乘
    string result = multiplyVector(nums);
    cout << result << endl;

    return 0;
}
