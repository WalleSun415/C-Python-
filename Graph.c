#include <stdio.h>


typedef char VertexType;  //顶点类型
typedef int EdgeType;  //边上的权值类型
#define MAXVEX 100  //最大顶点数
#define INFINITY 65535  //65535代表不存在
typedef struct
{
    VertexType vexs[MAXVEX];  //一维数组表示顶点表
    EdgeType arc[MAXVEX][MAXVEX];  //二维数组表示邻接矩阵（边或弧表）
    int numVertexes, numEdges;  //顶点数和边数
}MGraph;


void CreateMGraph(MGraph *G)  //无向网图的邻接矩阵建立
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
