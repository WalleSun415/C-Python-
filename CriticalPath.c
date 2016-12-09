#include <stdlib.h>
#include <stdio.h>
#define MAXVEX 10
#define OK 1
#define ERROR 0

typedef int Status;

typedef struct EdgeNode
{
    int adjvex;
    int weight;
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode
{
    int in;
    int data;
    EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numVertexes, numEdges;
}graphAdjList, *GraphAdjList;

int *etv, *ltv;
int *stack2;
int top2;


Status TopologicalSort (GraphAdjList GL)
{
    EdgeNode *e;
    int i, k, gettop;
    int top = 0;
    int count = 0;
    int *stack;
    stack = (int *)malloc(GL->numVertexes * sizeof(int));
    for (i = 0; i < GL->numVertexes; i++)
        if (GL->adjList[i].in == 0)
            stack[++top]=i;
    top = 2;
    etv = (int *)malloc(GL->numVertexes * sizeof(int));
    for (i = 0; i < GL->numVertexes; i++)
        etv[i] = 0;
    stack2 = (int *)malloc(GL->numVertexes * sizeof(int));
    while (top != 0)
    {
        gettop=stack[top--];
        count++;
        stack2[++top2] = gettop;
        for (e = GL->adjList[gettop].firstedge; e; e=e->next)
        {
            k=e->adjvex;
            if ((--GL->adjList[k].in) == 0)
                stack[++top]=k;
            if ((etv[gettop]+e->weight)>etv[k])  //求各顶点的最早发生时间，比较etv[]+weight
                etv[k] = etv[gettop] +e->weight;
        }
    }
    if (count < GL->numVertexes)
        return ERROR;
    else 
        return OK;
}


void CriticalPath (GraphAdjList GL)
{
    EdgeNode *e;
    int i, gettop, k, j;
    int ete, lte;
    TopologicalSort(GL);
    ltv = (int *)malloc(GL->numVertexes * sizeof(int));
    for (i = 0; i < GL->numVertexes; i++)
    {
        ltv[i] = etv[GL->numVertexes-1];  //初始化ltv
    }
    while (top2 != 0)
    {
        gettop = stack2[top2--];
        for (e = GL->adjList[gettop].firstedge; e; e = e->next)  //求各顶点事件的最迟发生时间ltv值
        {
            k = e->adjvex;
            if (ltv[k] - e->weight < ltv[gettop])
                ltv[gettop] = ltv[k] - e->weight;
        }
    }
    for (j = 0; j < GL->numVertexes; j++)  //求ete，lte和关键路径
    {
        for (e = GL->adjList[j].firstedge; e; e = e->next)
        {
            k = e->adjvex;
            ete = etv[j];  //表示活动<vk, vj>最早发生时间,但只有弧尾顶点vk事件发生了，它才可以开始，所以ete=etv[k]
            lte = ltv[j] - e->weight;  //表示活动<vk, vj>的最晚开工时间，但此活动最晚也要在vj事件发生前提前len<vk, vj>开工
            if (ete == lte)  //判断关键路径的条件
            {
                printf("(v%d, v%d) weight: %d, ", k, j, e->weight);
            }
        }
    }
}

