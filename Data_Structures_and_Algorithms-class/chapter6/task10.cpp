#include<iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MVNum 100     //最大顶点数
using namespace std;
typedef struct
{//图的邻接矩阵存储表示
	int vexs[MVNum];    //顶点表
	int arcs[MVNum][MVNum];    //邻接矩阵
	int vexnum,arcnum;     //图的当前点数和边数
}AMGragh;
int CreateUDN(AMGragh &G,int vexnum,int arcnum)
{//采用邻接矩阵表示法，创建无向网G
    G.vexnum = vexnum;
    G.arcnum = arcnum;
    //初始化顶点和矩阵
    for(int i = 0; i < MVNum; i++){
        G.vexs[i] = -1;
    }
    for(int i = 0; i < MVNum; i++){
        for(int j = 0; j < MVNum; j++){
            G.arcs[i][j] = 0;
        }
    }
    //读入顶点信息
    for(int i = 0; i <= G.vexnum; i++){
        G.vexs[i] = i;
    }
    //读入边信息
    for(int i = 0; i < G.arcnum; i++){
        int vi, vj;
        cin >> vi >> vj;
        G.arcs[vi][vj] = 1;
        G.arcs[vj][vi] = 1;
    }

    return OK;
}
int DeleteArc(AMGragh &G)
{//在以邻接矩阵形式存储的无向图G上删除边
    int vi, vj;
    cin >> vi >> vj;
    G.arcs[vi][vj] = 0;
    G.arcs[vj][vi] = 0;
    return OK;
}
int OutputUDN(AMGragh G)
{//输出图G
    for(int i = 0; i <= G.vexnum; i++){
        if(i == G.vexnum)
            cout << G.vexs[i] << endl;
        else
            cout << G.vexs[i] << " ";
    }
    for(int i = 1; i <= G.vexnum; i++){
        cout << i << " ";
        for(int j = 1; j <= G.vexnum; j++){
            if(j == G.vexnum)
                cout << G.arcs[i][j] << endl;
            else
                cout << G.arcs[i][j] << " ";
        }
    }

    return OK;
}

int main()
{
	int n,m;                  //n个顶点和m条边
	while(cin>>n>>m)
	{
		if(n==0&&m==0) break;     //输入结束标志
		AMGragh G;
      	CreateUDN(G,n,m);    //采用邻接矩阵表示法，创建无向网G
      	DeleteArc(G);        //在以邻接矩阵形式存储的无向图G上删除边
      	OutputUDN(G);       //输出图G
	}
	return 0;
}