#include<iostream>
#include<cstring>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MaxInt 32767                        //表示极大值，即∞
#define MVNum 100                           //最大顶点数
using namespace std;
typedef struct ArcNode
{//边结点
	int adjvex;                //邻接点域：该边所指向的顶点的位置
	char data;                  //数据域：存储和边相关的信息
	struct ArcNode* nextarc;   //链域：指向下一条边的指针
}ArcNode;
typedef struct VNode
{//顶点信息
	char data;              //顶点结点的数据域
	ArcNode *firstarc;     //链域：指向第一条依附该顶点的边的指针
}VNode,AdjList[MVNum];     //AdjList表示邻接表类型
typedef struct
{//邻接表
	AdjList vertices;
	int vexnum,arcnum;    //图的当前顶点数和边数
}ALGragh;
int Locate(char ch[],char h)
{//存在则返回h在数组中的下标，否则返回ERROR
	for(int i = 0; i < strlen(ch); i++)
        if(ch[i] == h) return i;
    return OVERFLOW;
}
bool visited[MVNum];  //访问标记数组，已访问顶点的值记为true,初始值为false
int CreateUDG(ALGragh &G,int vexnum,int arcnum,char ch[])
{//采用邻接表表示法，创建无向图G
	G.vexnum = vexnum;
    G.arcnum = arcnum;
    //初始化顶点信息
    for(int i = 0; i < G.vexnum; i++){
        G.vertices[i].data = ch[i];
        G.vertices[i].firstarc = NULL;
    }
    //初始化边信息
    for(int i = 0; i < G.arcnum; i++){
        char ch1, ch2;
        int vi, vj;
        cin >> ch1 >> ch2;
        vi = Locate(ch, ch1);
        vj = Locate(ch, ch2);
        if(vi == OVERFLOW || vj == OVERFLOW) return ERROR;
        // 从 vi 到 vj 存在有向边
        ArcNode *p = new ArcNode;
        p->adjvex = vj;
        p->data = ch2;
        p->nextarc = G.vertices[vi].firstarc;
        G.vertices[vi].firstarc = p;
    }
    return OK;
}

int PathDFS(ALGragh G,int i,int j,int  level)
{//基于深度优先搜索判断有向图G中顶点i到j是否有路径，是则返回1，否则返回0
     if(i == j) return 1;
     visited[i] = true;
     ArcNode *p = G.vertices[i].firstarc;
     while(p!= NULL){
         if(!visited[p->adjvex]){
             if(PathDFS(G,p->adjvex,j,level+1)) return 1;
         }
         p = p->nextarc;
     }
     return 0;
}

int main()
{
	int n,m;   //n个顶点，m条边和长度k
	while(cin>>n>>m)
	{
		if(n==0&&m==0) break;
		char ch[MVNum];
		cin>>ch;
		ALGragh G;
		CreateUDG(G,n,m,ch);    //创建无向图G
		char vi,vj;    //d和f代表需要判断的两个字符
		cin>>vi>>vj;
		int pi=Locate(ch,vi);
		int pj=Locate(ch,vj);
        if(PathDFS(G,pi,pj,1))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}