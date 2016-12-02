#include <stdio.h>


typedef char VertexType;  //顶点类型
typedef int EdgeType;  //边上的权值类型
#define MAXVEX 100  //最大顶点数
#define INFINITY 65535  //65535代表不存在


/*************************************图的邻接矩阵存储方式（Adjacency Matrix）**********************************/
typedef struct  
{
    VertexType vexs[MAXVEX];  //一维数组表示顶点表
    EdgeType arc[MAXVEX][MAXVEX];  //二维数组表示邻接矩阵（边或弧表）
    int numVertexes, numEdges;  //顶点数和边数
}MGraph;


void CreateMGraph(MGraph *G)  //邻接矩阵建立无向网图
{
    int i, j, k, w;
    printf("输入顶点数和边数：\n");
    scanf("%d, %d", &G->numVertexes, &G->numEdges);  //输入顶点数和边数
    for(i = 0;i <G->numVertexes;i++)
        scanf(&G->vexs[i]);
    for(i = 0 ;i <G->numVertexes;i++)
        for(j = 0;j <G->numVertexes;j++)
            G->arc[i][j]=INFINITY;  //邻接矩阵初始化
    for(k = 0;k <G->numEdges;k++)  //读入邻接矩阵边数，建立邻接矩阵
    {
        printf("输入边(vi,vj)上的下标i，下标j和权w：\n");
        scanf("%d, %d, %d", &i, &j, &w);  //输入边和对应的权值
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];  //因为是无向图，矩阵对称
    }
}


/**********************************************图的邻接表存储方式（Adjacency List）********************************/
typedef struct EdgeNode  //边表结点
{
    int adjvex;  //邻接点域
    EdgeType weight;  //存储权值，非网图可以省略
    struct EdgeNode *next;  
}EdgeNode;


typedef struct VertexNode  //顶点表结点
{
    VertexType data;  //顶点域，存储定点信息
    EdgeNode *firstedge;  //边表头指针
}VertexNode, AdjList[MAXVEX];


typedef struct 
{
    AdjList adjList;
    int numVertexes, numEdges;  //图中的当前顶点数和边数
}GraphAdjList;


void CreateALGraph(GraphAdjList *G)  //邻接表存储方式建立无向图
{
    int i, j, k;
    EdgeNode *e;
    printf("请输入顶点数和边数：\n");
    scanf("%d, %d", &G->numVertexes, &G->numEdges);
    for (i = 0;i <G->numVertexes;i++)  //读取顶点信息，建立顶点表
    {
        printf("输入第%d个顶点存储数据data：\n");
        scanf(&G->adjList[i].data);  //输入顶点信息
        G->adjList[i].firstedge = NULL;  //将边表置为空表
    }
    for (k = 0;k <numEdges;k++)  //读取顶点序号，建立边表
    {
        printf("输入边(vi,vj)上的顶点序号：\n");
        scanf("%d, %d", &i, &j);

        //单链表创建中的头插法
        e = (EdgeNode *)malloc(sizeof(EdgeNode));  //向内存申请空间，声称边表结点
        e->adjvex = j;  //顶点i的邻接序号为j
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;

        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
    }
}
