#define MAXVEX 9  
#define INFINITY 65535
typedef int Patharc[MAXVEX];  //存储输入顶点最短路径下标的数组
typedef int ShortPathTable[MAXVEX];  //存储输入顶点到各点最短路径的权值和


/*求有向网G的顶点v0到其余各点最短路径的Dijkstra算法，P[v]的值为前驱顶点的下标，D[v]的值表示v0到v的最短路径长度和*/
void ShortestPath_Dijkstra (MGraph G, int v0, Patharc *P, ShortPathTable *D)
{
    int v, w, k, min;
    int final[MAXVEX];  //标记是否已经求得v0到某顶点的最短路径

    for (v = 0; v < G.numVertexes; v++)
    {
        final[v] = 0;  //全部初始化为未知最短路径状态
        (*D)[v] =G.arc[v0][v];  //初始化为v0顶点的权值
        (*P)[v] = 0;  //全部初始化为0
    }

    final[v0] = 1;  //v0至v0不需要求路径
    (*D)[v0] = 0;   //v0至v0路径为0

    for (v = 1; v < G.numVertexes; v++)
    {
        min = INFINITY;
        for (w = 0; w < G.numVertexes; w++)  //寻找离v0最近的顶点
        {
            if (!final[w] && (*D)[w] < min)
            {
                min = (*D)[w];
                k = w;
            }
        }

        final[k] = 1;  //将找到的最近顶点置1，说明已求得其和v0的最短路径
        
        for (w = 0; w < G.numVertexes; w++)  //修正当前最短路径和距离
        {
            /*v0到与k顶点相邻的顶点的路径比现在这条路径长度短时*/
            if (!final[w] && (min+G.arc[k][w] < (*D)[w]))  /*arc[k][w]表示对与k相邻的顶点进行计算，
                                                             若k与w不相邻，则arc[k][w]为INFINITY*/
            {
                (*D)[w] = min + G.arc[k][w];  //修改当前路径长度
                (*P)[w] = k;
            }
        }
    }
}


/**********************************Floyd算法，求网G的各顶点v到其余顶点w的最短路径P[v][w]及带权长度D[v][w]*****************************/
typedef int Pathmatrix[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];


void ShortestPath_Floyd(MGraph G, Pathmatrix *P, ShortPathTable *D)
{
    int v, w, k;
    for (v = 0; v < G.numVertexes; v++)
    {
        for (w = 0; w < G.numVertexes; w++)
        {
            (*D)[v][w] = G.arc[v][w];  //D[v][w]值初始化为邻接矩阵对应点间的权值
            (*P)[v][w] = w;
        }
    }

    //k代表中转顶点的下标，v代表起始顶点的下标，w代表结束顶点的下标
    for (k = 0; k < G.numVertexes; k++)
    {
        for (v = 0; v < G.numVertexes; v++)
        {
            for (w = 0; w < G.numVertexes; w++)
            {
                if ((*D)[v][k]+(*D)[k][w] < G.arc[v][w])
                {
                    //D与P矩阵均以上一集为基础，例如D-1是D0的基础，D0是D1的基础，D1是D2的基础...
                    G.arc[v][w] = (*D)[v][k] + (*D)[k][w];
                    (*P)[v][w] = (*P)[v][k];  //路径设置经过下标为k的顶点
                }
            }
        }
    }
}
