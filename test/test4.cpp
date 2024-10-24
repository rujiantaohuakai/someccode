#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m = 4 , n = 5;
    vector<vector<int>> map(m,vector<int>(n, 100));
    vector<int> dist(m, 100);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}