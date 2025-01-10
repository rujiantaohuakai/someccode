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
	ArcNode* firstarc;     //链域：指向第一条依附该顶点的边的指针
}VNode,AdjList[MVNum];     //AdjList表示邻接表类型
typedef struct
{//邻接表
	AdjList vertices;
	int vexnum,arcnum;    //图的当前顶点数和边数
}ALGragh;
int CreateUDG(ALGragh &G,int vexnum,int arcnum)
{//采用邻接表表示法，创建无向图G
    //顶点初始化
    for(int i = 0; i < MVNum; i++){
        G.vertices[i].data = 0;
        G.vertices[i].firstarc = NULL;
    }

    G.vexnum = vexnum;
    G.arcnum = arcnum;
    //初始化顶点信息
    for(int i = 0; i < G.vexnum; i++){
        G.vertices[i + 1].data = i + 1;
    }
    //创建边
    for(int i = 0; i < G.arcnum; i++){
        int vi, vj;
        cin >> vi >> vj;
        //头插法建立边
        ArcNode *p = new ArcNode;
        p->adjvex = vj;
        p->data = vj;
        p->nextarc = G.vertices[vi].firstarc;
        G.vertices[vi].firstarc = p;

        p = new ArcNode;
        p->adjvex = vi;
        p->data = vi;
        p->nextarc = G.vertices[vj].firstarc;
        G.vertices[vj].firstarc = p;
    }
    return OK;
}
void DeleteAdjList(VNode &List)
{//删除指定顶点链表上的边结点
    ArcNode *p = List.firstarc;
    List.data = 0;
    List.firstarc = NULL;
    while(p != NULL){
        ArcNode *q = p->nextarc;
        delete p;
        p = q;
    }
}
int DeleteVex(ALGragh &G)
{//删除G中顶点f及其相关的弧
    int f;
    cin >> f;
    DeleteAdjList(G.vertices[f]);
    return OK;
}
int PrintGraph(ALGragh G)
{//输出图G
    for(int i = 1; i <= G.vexnum; i++){
        if(G.vertices[i].data != 0){
            cout << G.vertices[i].data << " ";
            ArcNode *p = G.vertices[i].firstarc;
            while(p != NULL){
                if(G.vertices[p->adjvex].data != 0){
                    if(p->nextarc != NULL && G.vertices[p->nextarc->adjvex].data != 0)
                        cout << p->adjvex << " ";
                    else
                        cout << p->adjvex;
                }
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
     	DeleteVex(G);        //删除G中顶点f及其相关的弧
	   	PrintGraph(G);      //输出图G
	}
	return 0;
}