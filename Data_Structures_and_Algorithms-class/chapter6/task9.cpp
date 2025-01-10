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
	G.vexnum = vexnum;
    G.arcnum = arcnum;
    //初始化顶点信息
    for(int i = 0; i < MVNum; i++){
        G.vertices[i].data = 0;
        G.vertices[i].firstarc = NULL;
    }
    //创建顶点
    for(int i = 1; i <= G.vexnum; i++){
        G.vertices[i].data = i;
    }
    //创建边
    for(int i = 0; i < G.arcnum; i++){
        int vi, vj;
        cin >> vi >> vj;
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
int DeleteArc(ALGragh &G)
{//在以邻接表形式存储的无向图G上删除边
    int vi, vj;
    cin >> vi >> vj;
    ArcNode *p = G.vertices[vi].firstarc;   //找vj并删除vi->vj的边
    ArcNode *q = NULL;//记录前驱节点
    while(p != NULL){
        if(p->adjvex == vj){
            if(q == NULL)
                G.vertices[vi].firstarc = p->nextarc;
            else
                q->nextarc = p->nextarc;
        }
        q = p;
        p = p->nextarc;
    }

    p = G.vertices[vj].firstarc;    //找vi并删除vj->vi的边
    q = NULL;
    while(p != NULL){
        if(p->adjvex == vi){
            if(q == NULL)
                G.vertices[vj].firstarc = p->nextarc;
            else
                q->nextarc = p->nextarc;
        }
        q = p;
        p = p->nextarc;
    }

    G.arcnum--;
    return OK;
}
int PrintGraph(ALGragh G)
{//输出图G
    for(int i = 1; i <= G.vexnum; i++){
        if(G.vertices[i].firstarc != NULL)
            cout << i << " ";
        else cout << i << endl;
        ArcNode *p = G.vertices[i].firstarc;
        while(p != NULL){
            if(p->nextarc != NULL){
                cout << p->adjvex << " ";
                p = p->nextarc;
            }
            else{
                cout << p->adjvex << endl;
                p = NULL;
            }
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
     	DeleteArc(G);        //在图G中删除边
	   	PrintGraph(G);      //输出图G
	}
	return 0;
}