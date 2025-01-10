#include<iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MVNum 100     //最大顶点数
using namespace std;
typedef struct ArcNode
{//边结点
	int adjvex;                //邻接点域：该边所指向的顶点的位置
	int data;                  //数据域：存储和边相关的信息
	struct ArcNode* nextarc;   //链域：指向下一条边的指针
}ArcNode;
typedef struct VNode
{//顶点信息
	int data;              //顶点结点的数据域
	ArcNode *firstarc;     //链域：指向第一条依附该顶点的边的指针
}VNode,AdjList[MVNum];     //AdjList表示邻接表类型
typedef struct
{//邻接表
	AdjList vertices;
	int vexnum,arcnum;    //图的当前顶点数和边数
}ALGragh;
int CreateUDG(ALGragh &G,int vexnum,int arcnum)
{//采用邻接表表示法，创建无向图G
    G.vexnum = vexnum;  //初始化图的顶点数
    G.arcnum = arcnum;  //初始化图的边数

    for(int i = 1; i < MVNum; i++){
        G.vertices[i].data = -1;  //初始化顶点结点的数据域
        G.vertices[i].firstarc = NULL;  //初始化顶点结点的边链表为空
    }

    for(int i = 1; i <= G.vexnum; i++){
        G.vertices[i].data = i;  //初始化顶点结点的数据域
    }

    for(int i = 0; i < G.arcnum; i++){
        int edge1, edge2;
        cin >> edge1 >> edge2;  //输入边的两个顶点位置
        //头插法建立边
        ArcNode *p1 = new ArcNode;  //创建新的边结点
        p1->adjvex = edge1;
        p1->data = 0;
        p1->nextarc = G.vertices[edge2].firstarc;
        G.vertices[edge2].firstarc = p1;  //将边结点链接到相应的顶点的边链表上

        ArcNode *p2 = new ArcNode;
        p2->adjvex = edge2;
        p2->data = 0;
        p2->nextarc = G.vertices[edge1].firstarc;
        G.vertices[edge1].firstarc = p2;  //将边结点链接到相应的顶点的边链表上
    }
    return OK;
}
int InsertVex(ALGragh &G)
{//在以邻接表形式存储的无向图G上插入顶点v
    int v;
    cin >> v;
    G.vexnum++;  //增加顶点数
    G.vertices[v].data = v;  //初始化新顶点结点的数据域
    return OK;
}
int PrintGraph(ALGragh G)
{//输出图G

    for(int i = 1; i < MVNum; i++){
        if(G.vertices[i].data != -1){
            if(G.vertices[i].firstarc != NULL)
                cout << G.vertices[i].data <<" ";
            else
                cout << G.vertices[i].data;
            ArcNode *p = G.vertices[i].firstarc;
            while(p != NULL){
                if(p->nextarc != NULL)
                    cout << p->adjvex << " ";
                else
                    cout << p->adjvex;
                p = p->nextarc;
            }
            cout << endl;
        }
    }
    return OK;
}

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
      	if(n==0&&m==0) break;     //输入结束标志
      	ALGragh G;
       	CreateUDG(G,n,m);      //采用邻接表表示法，创建无向图G
     	InsertVex(G);        //在图G中增添新顶点
	   	PrintGraph(G);      //输出图G
	}
	return 0;
}
