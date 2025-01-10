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
    //初始化顶点表
    for(int i = 0; i < MVNum; i++){
        G.vexs[i] = -1;
    }
    //初始化邻接矩阵
    for(int i = 0; i < MVNum; i++){
        for(int j = 0; j < MVNum; j++){
            G.arcs[i][j] = 0;
        }
    }
    //读入顶点表
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
int DeleteVex(AMGragh &G)
{//在以邻接矩阵形式存储的无向图G上删除顶点v
  	int v;
    cin >> v;
    G.vexs[v] = -1;
    for(int i = 0; i < G.vexnum; i++){
        G.arcs[v][i] = 0;
        G.arcs[i][v] = 0;
    }
    return OK;
}

int OutputUDN(AMGragh G)
{//输出图G
    int count = 0;
    for(int i = 0; i <= G.vexnum; i++){
        if(G.vexs[i] != -1){
            count++;
            if(count != G.vexnum)
                cout << G.vexs[i] << " ";
            else cout << G.vexs[i] << endl;
        }
    }
    for(int i = 1; i <= G.vexnum; i++){
        if(G.vexs[i] != -1){
            cout << i << " ";
            int count1 = 0;
            for(int j = 1; j <= G.vexnum; j++){
                if(G.vexs[j] != -1){
                    count1++;
                    if(count1 != G.vexnum - 1)
                        cout << G.arcs[i][j] << " ";
                    else cout << G.arcs[i][j] << endl;
                }
            }
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
      	DeleteVex(G);        //在以邻接矩阵形式存储的无向图G上删除顶点v
      	OutputUDN(G);       //输出图G
	}
	return 0;
}