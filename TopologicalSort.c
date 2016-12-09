#include <stdlib.h>
#include <stdio.h>
#define MAXVEX 14
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


/*对邻接表GL实现拓扑排序，若GL无回路，则输出拓扑排序序列并返回OK，若有回路则返回ERROR*/
Status TopologicalSort (GraphAdjList GL)
{
    EdgeNode *e;
    int i, k, gettop;
    int top=0;
    int count=0;    //用于统计输出顶点个数
    int *stack; //用于存储入度为0的顶点
    stack = (int *)malloc(GL->numVertexes * sizeof(int));
    for (i = 0; i < GL->numVertexes; i++)
        if (GL->adjList[i].in == 0)  //将入度为0的顶点入栈      
        {
            top++;
            stack[top] = i;
        }

    while (top != 0)
    {
        gettop = stack[top];
        top--;
        printf("v%d -> ", GL->adjList[gettop].data);
        count++;
        for (e = GL->adjList[gettop].firstedge;e;e=e->next)  //对顶点边表进行遍历
        {
            k = e->adjvex;
            if((--GL->adjList[k].in) == 0)  //将k顶点的邻接点入度减1，若为0则将该邻接点入栈
            {
                top++;
                stack[top] = k;
            }
        }
    }   
    if (count < GL->numVertexes)  //如果count小于顶点数，说明存在环
        return ERROR;
    else
        return OK;
}
