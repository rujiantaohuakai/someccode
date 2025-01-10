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
    for(int i = 0; i < MVNum; i++){
        G.vexs[i] = -1;
    }
    for(int i = 0; i < MVNum; i++){
        for(int j = 0; j < MVNum; j++){
            G.arcs[i][j] = 0;
        }
    }
    for(int i = 0; i <= G.vexnum; i++){
        G.vexs[i] = i;
    }
    for(int i = 1; i <= G.arcnum; i++){
        int spot1, spot2;
        cin >> spot1 >> spot2;
        G.arcs[spot1][spot2] = 1;
        G.arcs[spot2][spot1] = 1;
    }
    return OK;
}
int InsertVex(AMGragh &G)
{//在以邻接矩阵形式存储的无向图G上插入顶点
    int vex;
    cin >> vex;
    G.vexnum++;
    G.vexs[vex] = vex;
    return OK;
}
int OutputUDN(AMGragh G)
{//输出图G
    int times = 0;
    for(int i = 0; i < MVNum; i++){//输出第一行顶点信息
        if(G.vexs[i] != -1){
            if(times == G.vexnum)
                cout << G.vexs[i] << endl;
            else
                cout << G.vexs[i] << " ";
            times++;
        }
    }
    
    for(int i = 1; i < MVNum; i++){
        if(G.vexs[i] != -1)
            cout << G.vexs[i] << " ";
        int count = 0;
        for(int j = 1; j < MVNum; j++){
            if(G.vexs[i] != -1 && G.vexs[j] != -1){
                count++;
                if(count == G.vexnum)
                    cout << G.arcs[i][j];
                else
                    cout << G.arcs[i][j] << " ";
            }
        }
        if(G.vexs[i] != -1)
            cout << endl;
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
      	InsertVex(G);        //在以邻接矩阵形式存储的无向图G上插入顶点
      	OutputUDN(G);       //输出图G
	}
	return 0;
}