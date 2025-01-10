#include<iostream>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MaxInt 32767                        //表示极大值，即∞
#define MVNum 100 
using namespace std;
int D[MVNum];           //D[i]记录从源点v0到终点vi的当前最短路径长度
int Path[MVNum];        //Path[i]记录从源点v0到终点vi的当前最短路径上vi的直接前驱序号
typedef struct
{
    char vexs[MVNum];                   //顶点表
    int arcs[MVNum][MVNum];               //邻接矩阵, 下标和顶点表一一对应
    int vexnum;                           //图的总顶点数
    int arcnum;                        //图的总边数
} AMGraph;
int LocateVex(const AMGraph &G,char u)
{//存在则返回u在顶点表中的下标
    for(int i = 0; i < G.vexnum; i++){
        if(G.vexs[i] == u)
            return i;
    }
    return OVERFLOW;
}
char OrigialVex(AMGraph G,int u)
{//存在则返回顶点表中下标为u的元素
    if(u >= 0 && u < G.vexnum)
        return G.vexs[u];
    else return OVERFLOW;
}
int CreateDN(AMGraph &G,int spot,int edge)
{//采用邻接矩阵表示法，创建有向网G
    G.vexnum = spot;
    G.arcnum = edge;
    for(int i = 0; i < G.vexnum; i++){
        cin >> G.vexs[i];
    }
    for(int i = 0; i < G.vexnum; i++){
        for(int j = 0; j < G.vexnum; j++){
            // if(i == j) G.arcs[i][j] = 0;
            // else G.arcs[i][j] = MaxInt;
            G.arcs[i][j] = MaxInt;
        }
    }

    for(int i = 0; i < G.arcnum; i++){
        char a, b;
        int weight;
        cin >> a >> b >> weight;
        int aindex = LocateVex(G, a);
        int bindex = LocateVex(G, b);

        if(aindex == OVERFLOW || bindex == OVERFLOW)
            return OVERFLOW;

        G.arcs[aindex][bindex] = weight;
    }
    return OK;
}
void ShortestPath_DIJ(AMGraph G, char V,int * Path,int *D)
{//用Dijkstra算法求有向网G的v0顶点到其余顶点的最短路径
    bool vis[G.vexnum] = {false};
    int v0 = LocateVex(G, V);
    if(v0 == OVERFLOW) return;
    for(int i = 0; i < G.vexnum; i++){
        D[i] = MaxInt;
        Path[i] = -1;
    }
    D[v0] = 0;
    
    for(int i = 0; i < G.vexnum - 1; i++){//每次找出距离源点v0最近的顶点，并更新其邻接点的距离
        int index = -1;
        for(int j = 0; j < G.vexnum; j++){
            if(!vis[j] && (index == -1 || D[j] < D[index]))
                index = j;
        }
        if(index == -1) break;

        vis[index] = true;
        for(int j = 0; j < G.vexnum; j++){
            int temp = D[j];
            D[j] = min(D[j], D[index] + G.arcs[index][j]);
            if(temp != D[j])
                Path[j] = index;
        }
    }
    Path[v0] = -1;
}
void Find(AMGraph G,int v,int * Path)
{//在Path数组中查找序号v
    char path[MVNum];
    int i = Path[v];    //从v的直接前驱开始，反向寻找路径
    int count = 0;
    while(i != -1){
        path[count++] = OrigialVex(G, i);
        i = Path[i];
    }
    for(int i = count - 1; i >=0; i--){
        cout<< path[i] << " ";
    }
}


int main()
{
    char a,b;      //起点城市a和终点城市b
    int n,m;     //城市个数n和路径条数m
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        AMGraph G;
        CreateDN(G,n,m);          //创建有向网G
        cin>>a;                 //起点城市a
        ShortestPath_DIJ(G,a,Path,D);  //求有向网G的a顶点到其余顶点的最短路径
        cin>>b;            //终点城市b
        int v=LocateVex(G,b);//返回b在顶点表中的下标，赋值给变量v
        cout<<D[v]<<endl;      //输出从a点到b点的最短路径长度
        Find(G,v,Path);
        cout<<b<<endl;
    }
    return 0;
}