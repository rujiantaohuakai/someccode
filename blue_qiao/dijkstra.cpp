#include<bits/stdc++.h>
using namespace std;
const int INF = 1e5;

vector<int> dijkstra(vector<vector<int>> &G, int source){
    int n = G.size(); // number of vertices
    vector<int> dis(n, INF);    //源点到其他点的最短距离
    vector<bool> vis(n, false); //表示某个顶点是否被被访问过
    //源点到源点的距离为0
    dis[source] = 0;

    for(int i = 0; i < n-1; i++){
        int node = -1;
        for(int j = 0; j < n; j++){
            if(!vis[j] && (node == -1 || dis[j] < dis[node]))
                node = j;
        }

        for(int j = 0; j < n; j++){
            dis[j] = min(dis[j], dis[node] + G[node][j]);
        }

        vis[node] = true;
    }

    return dis;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n, vector<int>(n, INF));
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        G[a - 1][b - 1] = c;
    }

    int source = 0;
    vector<int> dis = dijkstra(G, source);

    if(dis[n-1] == INF) cout << -1 << endl;
    else cout << dis[n-1] << endl;

    return 0;
}