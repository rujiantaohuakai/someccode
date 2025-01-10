#include<iostream>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MaxInt 32767                        //表示极大值，即∞
#define MVNum 100 
using namespace std;
typedef struct
{
	char vexs[MVNum];                   //顶点表
	int arcs[MVNum][MVNum];               //邻接矩阵
	int vexnum;                           //图的总顶点数
	int arcnum;                        //图的总边数
} AMGraph;
int LocateVex(AMGraph G, char u)
{//存在则返回u在顶点表中的下标，否则返回ERROR
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vexs[i] == u)
			return i;
	}
	return ERROR;
}
char OrigialVex(AMGraph G, int u)
{//存在则返回顶点表中下标为u的元素
	if (u < G.vexnum&&u>=0)
		return G.vexs[u];
	return '\0';
}
int CreateDN(AMGraph& G, int spot, int edge)
{//采用邻接矩阵表示法，创建有向网G
	G.vexnum = spot;
	G.arcnum = edge;
	for (int i = 0; i < G.vexnum; i++)
		cin >> G.vexs[i];
	
	
	for (int i = 0; i < G.vexnum; i++)//初始化矩阵
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			if (i == j)
				G.arcs[i][j] = 0;
			else
				G.arcs[i][j] = MaxInt;
		}
	}

	for (int k = 0; k < G.arcnum; k++)
	{
		char v1, v2;
		int num;
		cin >> v1 >> v2 >> num;
		G.arcs[LocateVex(G, v1)][LocateVex(G, v2)] = num;
	}
	return OK;

}
void ShortestPath_DIJ(AMGraph G, char V, int* Path, int* D)
{//用Dijkstra算法求有向网G的v0顶点到其余顶点的最短路径
	bool S[MVNum];
	int v0 = LocateVex(G, V);

	for (int i = 0; i < G.vexnum; i++)
	{
		S[i] = false;
		D[i] = G.arcs[v0][i];
		if (D[i] < MaxInt) Path[i] = v0;
		else Path[i] = -1;

	}
	S[v0] = true;


	for (int i = 1; i < G.vexnum; i++)
	{
		int min = MaxInt;
		int v = 0;
		for (int j = 0; j < G.vexnum; j++)
		{
			if (!S[j] && D[j] < min)
			{
				v = j;
				min = D[j];
			}
		}

		S[v] = true;
		for (int k = 0; k < G.vexnum; k++)
		{
			if (!S[k] && (D[v] + G.arcs[v][k] < D[k]))
			{
				D[k] = D[v] + G.arcs[v][k];
				Path[k] = v;
			}
		}
	}



}
void Find(AMGraph G, int v, int* Path)
{//在Path数组中查找序号v
	if (Path[v] != -1) {
		Find(G, Path[v], Path);
		cout << " ";
	}
	cout << OrigialVex(G, Path[v]);
}
