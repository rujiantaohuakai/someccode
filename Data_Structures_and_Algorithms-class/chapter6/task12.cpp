#include<iostream>
#include<cstring>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MVNum 100     //最大顶点数
#define MaxInt INT_MAX//最大整数值
using namespace std;
typedef struct
{//图的邻接矩阵存储表示
	int vexnum,arcnum;    //图的当前顶点数和边数
	int vexs[MVNum];        //顶点表
	int arcs[MVNum][MVNum];    //邻接矩阵
}AMGraph;
int CreateUDN(AMGraph &G,int vexnum,int arcnum)
{//采用邻接矩阵表示法，创建无向网G
    G.vexnum = vexnum;
    G.arcnum = arcnum;
    //邻接矩阵初始化
    for(int i = 0; i < MVNum; i++){
        for(int j = 0; j < MVNum; j++){
            if(i == j) G.arcs[i][j] = 0;
            else G.arcs[i][j] = 1000;
        }
    }

    for(int i = 0; i < vexnum; i++){
        G.vexs[i + 1] = i + 1; 
    }

    for(int i = 0; i < arcnum; i++){
        int u, v, w;
        cin >> u >> v >> w;
        G.arcs[u][v] = w;
        G.arcs[v][u] = w;
    }

    return OK;
}
void ShortPathMAX(AMGraph G,int v0)
{//用Dijkstra算法求图G中距离顶点v0的最短路径长度最大的一个顶点
    int dis[MVNum];//dis[i]表示从v0到i的最短路径长度
    bool vis[MVNum] = {false};
    for(int i = 1; i <= G.vexnum; i++) dis[i] = 10000;
    // memset(vis, false, sizeof(vis));
    dis[v0] = 0;
    for(int i = 1; i < G.vexnum; i++){
        int node = -1;
        for(int j = 1; j <= G.vexnum; j++){//找出未被访问的顶点中距离已经计算过的顶点最近的顶点
            if(!vis[j] && (node == -1 || dis[j] < dis[node])){
                node = j;
            }
        }
        
        vis[node] = true;
        for(int j = 1; j <= G.vexnum; j++){//更新距离
            dis[j] = min(dis[j], dis[node] + G.arcs[node][j]);
        }
    }
    int maxdisnode = 1, maxdis = dis[1];
    for(int i = 2; i <= G.vexnum; i++){
        if(dis[i] > maxdis){
            maxdis = dis[i];
            maxdisnode = i;
        }
    }
    cout << maxdisnode << endl;
    cout << maxdis << endl;
}

int main()
{
	int n,m;
	while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        AMGraph G;
        CreateUDN(G,n,m);    //创建无向网G
        int v;
        cin>>v;
        ShortPathMAX(G,v);   //最长的最短路径的求解
    }
	return 0;
}
