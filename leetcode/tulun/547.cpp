#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int i, vector<bool>& visited){
        visited[i] = true;
        for(int j = 0; j < isConnected.size(); j++){
            if(isConnected[i][j] == 1 &&!visited[j]){
                dfs(isConnected, j, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int len = isConnected.size();
        vector<bool> visited(len, false);
        for(int i = 0; i < len; i++){
            if(!visited[i]){
                count++;
                dfs(isConnected, i, visited);
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << s.findCircleNum(isConnected) << endl;
    return 0;
}


