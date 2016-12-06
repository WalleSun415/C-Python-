#include "Graph.c"
#include <stdio.h>

#define MAXVEX 100
#define INFINITY 65535
/*****************************Prim算法生成最小生成树************************/
void MiniSpanTree_Prim (MGraph G)
{
    int min, i, j, k;
    int adjvex[MAXVEX];
    int lowcost[MAXVEX];

    //lowcost数组与adjvex数组对比，表示adjvex[i]为起点，i为终点的边，权值为lowcost[i]
    lowcost[0] = 0;  //初始化第一个权值为0，即v0加入生成树，lowcost中的值为0代表此下标顶点已加入生成树
    adjvex[0] = 0;  //初始化第一个顶点下标为0
    for (i = 1; i < G.numVertexes; i++)
    {
        lowcost[i] = G.arc[0][i];  //将与v0顶点邻接的顶点权值加入数组
        adjvex[i] = 0;  
    }
    for (i = 1; i < G.numVertexes; i++)
    {
        min = INFINITY;
        j = 1;k = 0;
        while (j < G.numVertexes)  //循环所有顶点，查找lowcost数组中的最小值赋给k
        {
            if (lowcost[j]!=0 && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
            j++;
        }
        printf("(%d,%d)", adjvex[k], k);  //打印当前顶点边中权值最小的边
        lowcost[k] = 0;  //将当前顶点权值置为0，代表此顶点已加入最小生成树

        //循环所有顶点，将当前最小权值顶点的邻接点与lowcost的对应值比较，若更小则修改lowcost值
        for (j = 1; j < G.numVertexes; j++)  
        {
            if (lowcost[j]!=0 && G.arc[k][j] < lowcost[j])
            {
                lowcost[j] = G.arc[k][j];
                adjvex[j] = k;  //将下标为k的顶点存入adjvex
            }
        }
    }
}
