#include<iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
using namespace std;
typedef struct ArcNode
{//边结点
	int data;
	struct ArcNode *nextarc; //链域：指向下一条边的指针
}ArcNode;
typedef struct VNode
{//顶点信息
	int data;
	ArcNode *firstarc;  //链域：指向第一条依附该顶点的边的指针
}VNode,AdjList[MAXSIZE];    //AdjList表示邻接表类型
typedef struct
{//邻接表
	AdjList vertices;
	int vexnum,arcnum;    //图的当前顶点数和边数
}ALGraph;
typedef struct
{//顺序栈
	int *base;          //栈底指针
	int *top;           //栈顶指针
	int stacksize;      //栈可用的最大容量
}SqStack;
void InitStack(SqStack &S)
{//顺序栈的初始化
    S.base = new int[MAXSIZE];
    S.top = S.base;
    S.stacksize = MAXSIZE;
}
void Push(SqStack &S,int e)
{//入栈操作
    if(S.top-S.base>=S.stacksize) return;
    *S.top = e;
    S.top++;
}
void Pop(SqStack &S,int &e)
{//出栈操作
    if(S.top == S.base) return;
    S.top--;
    e = *S.top;
}

bool StackEmpty(SqStack S)
{//判空操作
    return S.top == S.base;
}
bool visited[MAXSIZE];    //访问标志数组，初始为false
int CreateUDG(ALGraph &G,int vexnum,int arcnum)
{//采用邻接表表示法，创建无向图G
    G.vexnum = vexnum;
    G.arcnum = arcnum;
    for(int i = 0; i < G.vexnum; i++){//初始化顶点信息
        G.vertices[i + 1].data = i + 1;
        G.vertices[i + 1].firstarc = NULL;
    }
    ArcNode *p1, *p2;
    for(int i = 0; i < G.arcnum; i++){
        int v1, v2;
        cin >> v1 >> v2;
        p1 = new ArcNode;
        p1->data = v2;
        p1->nextarc = G.vertices[v1].firstarc;
        G.vertices[v1].firstarc = p1;

        p2 = new ArcNode;
        p2->data = v1;
        p2->nextarc = G.vertices[v2].firstarc;
        G.vertices[v2].firstarc = p2;
    }

    return OK;
}
void DFS(ALGraph G, int v, SqStack S)
{//从第v个顶点出发非递归实现深度优先遍历图G
    //visited数组全部置为false
    for(int i = 0; i < MAXSIZE; i++) visited[i] = false;
    InitStack(S);
    visited[v] = true;
    //cout << v << " ";
    Push(S, v);
    while(!StackEmpty(S))
    {
        int u;
        Pop(S, u);
        ArcNode *p = G.vertices[u].firstarc;
        while(p)
        {
            int w = p->data;
            if(!visited[w])
            {
                visited[w] = true;
                //cout << w << " ";
                Push(S,w);
            }
            p = p->nextarc;
        }
        if(!StackEmpty(S))
            cout << u << " ";
        else
            cout << u;
    }
    cout << endl;
}

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0&&m==0) break;
		ALGraph G;
		SqStack S;
		CreateUDG(G,n,m);   //创建无向图G
		int d;             //从d开始遍历
		cin>>d;
		DFS(G,d,S);    //基于邻接表的深度优先遍历
	}
	return 0;
}
