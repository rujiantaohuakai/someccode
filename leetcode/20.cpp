#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        stack<char> c;
        c.push(s[0]);
        for(int i = 1; i < len; i++){
            char now = s[i];
            if(c.empty()) {c.push(now); continue;};
            char topelem = c.top();
            if((topelem == '(' && now == ')')||(topelem == '[' && now == ']')||(topelem == '{' && now == '}')) c.pop();
            else c.push(now);
        }
        if(c.empty()) return true;
        else return false;
    }
};

int main(){
    Solution sol;
    string s = "()()[]{{}]}";
    if(sol.isValid(s)) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}