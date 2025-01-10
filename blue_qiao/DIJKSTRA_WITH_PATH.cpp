#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;

vector<int> dijkstra(vector<vector<int>>& G, vector<int>& Path, int source){//Path记录前驱结点
    int n = G.size(); //结点数
    vector<int> distence = vector<int>(n, INF); //初始化距离
    distence[source] = 0; //源点到源点的距离为0
    //Path[source] = -1; //源点的前驱结点为-1
    //初始化
    vector<bool> vis(n, false); //初始化访问标记
    int prevnode = -1;
    for(int i = 0; i < n - 1; i++){//循环n-1次，找到除source以外的其他点的最短路径
        int node = -1; //记录当前最小距离的结点
        for(int j = 0; j < n; j++){
            if(!vis[j] && (node == -1 || distence[j] < distence[node])){//没有访问过，并且距离小于当前最小距离
                node = j; //更新当前最小距离的结点
            }
        }
        if(node == -1){ //没有找到距离源点更近的点
            break; //结束循环
        }
        // Path[node] = prevnode;
        // prevnode = node;
        vis[node] = true;
        for(int j = 0; j < n; j++){
            int temp = distence[j];
            distence[j] = min(distence[j], distence[node] + G[node][j]); //更新距离
            //如果跟新了距离，记录前驱结点
            if(temp != distence[j]){
                Path[j] = node;
            }
        }

    }
    Path[source] = -1; //源点的前驱结点为-1
    return distence;
}

int main(){
    int n, m; //n个结点，m条边
    cin >> n >> m;
    int source = 2-1; //起点
    vector<vector<int>> G(n, vector<int>(n, INF)); //初始化邻接矩阵
    for(int i = 0; i < n; i++){
        G[i][i] = 0; //对角线元素为0
    }
    vector<int> Path(n, source);
    for(int i = 0; i < m; i++){
        int a, b, c;    //a到b的距离为c
        cin >> a >> b >> c;
        G[a - 1][b - 1] = c;
    }
    //source = 0; //起点为0
    vector<int> distence = dijkstra(G, Path, source); //求最短路径
    //输出所有路径和最小距离
    for(int i = 0; i < n; i++){
        cout << "min distance: " << distence[i] << endl;
        int node = i;
        cout << "path: ";
        vector<int> path;
        while(node != -1){
            // cout << node << " ";
            // node = Path[node];
            path.push_back(node);
            node = Path[node];
        }
        reverse(path.begin(), path.end());
        for(auto x : path){
            cout << x+1 << " ";
        }
        cout << endl;
    }
    
    return 0;
}