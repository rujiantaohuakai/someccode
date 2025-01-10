#include<iostream>
#include<cstring>
#include<stack>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MVNum 100     //最大顶点数
using namespace std;
bool vis[MVNum] = {false};  //访问标记数组，已访问顶点的值记为true
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
{//存在则返回h在数组中的下标，否则返回
	char *p = ch;
    while(*p!='\0'){
        if(*p == h) return p - ch;
        p++;
    }
    return OVERFLOW;
}

bool PathLenK(ALGragh G,int pD,int pF,int k,bool visited [])
{//判断邻接表方式存储的无向图G的顶点pD到pF是否存在长度为k的简单路径
	if(k == 0)
	{
		if(pD == pF) return true;
		else return false;
	}

	vis[pD] = true;
	ArcNode *p = G.vertices[pD].firstarc;
	while(p != NULL){
		if(!visited[p->adjvex]){
			if(PathLenK(G,p->adjvex,pF,k-1,visited)) return true;
		}
		p = p->nextarc;
	}

	return false;
}
int CreateUDG(ALGragh &G,int vexnum,int arcnum,char ch[])
{//采用邻接表表示法，创建无向图G
    G.vexnum = vexnum;
    G.arcnum = arcnum;
    //初始化顶点信息
    for(int i = 0; i < G.vexnum; i++){
        G.vertices[i].data = ch[i];
        G.vertices[i].firstarc = NULL;
    }
    //输入边信息
    for(int i = 0; i < G.arcnum; i++){
        char v1, v2;
		int v1_index,v2_index;
		cin >> v1 >> v2;
		v1_index = Locate(ch,v1);
		v2_index = Locate(ch,v2);
		if(v1_index == OVERFLOW || v2_index == OVERFLOW) return ERROR;
		//尾插法建立边
		ArcNode *p = new ArcNode;
		p->adjvex = v2_index;
		p->data = v2;
		p->nextarc = G.vertices[v1_index].firstarc;
		G.vertices[v1_index].firstarc = p;

		p = new ArcNode;
		p->adjvex = v1_index;
		p->data = v1;
		p->nextarc = G.vertices[v2_index].firstarc;
		G.vertices[v2_index].firstarc = p;	
    }
	return OK;
}


int main()
{
	int n,m,k;   //n个顶点，m条边和长度k
	bool visited[MVNum];  //访问标记数组，已访问顶点的值记为true
	while(cin>>n>>m>>k)
	{
		if(n==0&&m==0&&k==0) break;
		char ch[MVNum];
		cin>>ch;
		ALGragh G;
		CreateUDG(G,n,m,ch);    //创建无向图G
		char d,f;    //d和f代表需要判断的两个字符
		cin>>d>>f;
		int pd=Locate(ch,d);
		int pf=Locate(ch,f);
        if(PathLenK(G,pd,pf,k,visited))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
