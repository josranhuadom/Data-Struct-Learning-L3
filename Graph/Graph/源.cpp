#include<iostream>
#include <string>
using namespace std;

//图的邻接矩阵存储表示
#define MVNum 100
#define MaxInt 0
#define Int 1
bool visited[MVNum];

struct AdjacencyMatrix
{
	string vexs[MVNum];
	int arcs[MVNum][MVNum];
	int vexnum, arcnum;
};

//使用邻接矩阵表示法创建无向图
void CreateUndirectedGraph(AdjacencyMatrix &G)
{
	int i, j, k, v1, v2;     //i,j,k用于计数，v1,v2用于储存输入一条边依附的顶点
	cout << "请输入总顶点数" << endl;
	cin >> G.vexnum;
	cout << "请输入总边数" << endl;
	cin >> G.arcnum;
	cout << "请输入顶点信息" << endl;
	for (i = 0; i < G.vexnum; ++i)     
		cin >> G.vexs[i];
	//初始化邻接矩阵，边的权值最大值为MaxInt，即为0
	for (i = 1; i <= G.vexnum; ++i)
		for (j = 1; j <= G.vexnum; ++j)
			G.arcs[i][j] = MaxInt;
	for (k = 0; k < G.arcnum; ++k)
	{
		cout << "输入一条边依附的两个顶点" << endl;
		cout << "第一个" << endl;
		cin >> v1;
		cout << "第二个" << endl;
		cin >> v2;
		i = v1; j = v2;
		G.arcs[i][j] = Int;             //边<v1,v2>的权值从0置为Int，即为1
		G.arcs[j][i] = G.arcs[i][j];  //<v1,v2>的对称边<v2,v1>的权值也是置为1
	}
}

//深度优先搜索，虽然下面有FirstAdj() 和 NextAdj()，但是我选择不调用这两个函数
void DepthFirstSearch(AdjacencyMatrix G, int v)
{
	int w;
	cout << v;                  //访问第v个顶点
	visited[v] = true;       //并置访问标志数组相应分量值为true
	for (w = 1; w <= G.vexnum; w++)   
	{
		if ((G.arcs[v][w] != 0) && (!visited[w]))
			DepthFirstSearch(G, w);
		//G.arcs[v][w] != 0 表示 w 是 v 的邻接点，如果 w 未访问，则递归调用此函数
	}
}

//把邻接表所有的访问标志数组相应分量值置为false， 以便接下来实现 FirstAdj() 和 NextAdj() 函数
void InitVisited()
{
	for (int i = 0; i < MVNum; i++)
		visited[i] = false;
}

//访问顶点v的第一个邻接顶点
int FirstAdj(AdjacencyMatrix G, int v)
{
	int w;
	for (w = 1; w <= G.vexnum; w++)
	{
		if ((G.arcs[v][w] != 0) && (!visited[w]))
		{
			visited[w] = true;
			return w;
		}
		//遍历与顶点 v 相关的 顶点w，如果存在，而且之前没有被遍历过（即分量值为false），则return此值，并置其分量值为 true
	}
	return -1;    //如果没有可以 return 的值，则 return -1
}

int NextAdj(AdjacencyMatrix G, int v, int w)
{
	int r;
	for (r = w; r <= G.vexnum; r++)     //r 为即将 return 的值（如果有的话），让 r 直接从 w 开始，遍历
	{
		if ((G.arcs[v][r] != 0) && (!visited[r]))
		{
			visited[r] = true;
			return r;
		}
	}
	return -1;
}

int main()
{
	AdjacencyMatrix * G = new AdjacencyMatrix;
	CreateUndirectedGraph(*G);
	int v, w, c;
	for (c = 0; c <= 1; c++)
	{
		InitVisited();
		cout << "请问想从哪个顶点进行遍历" << endl;
		cin >> v;
		cout << "遍历结果为：" ;
		DepthFirstSearch(*G, v);
		InitVisited();
		w = FirstAdj(*G, v);
		cout << endl;
		cout << v << "的第一个邻接顶点为：";
		cout << w << endl;
		cout << "除了" << w << "，下一个邻接顶点为：";
		cout << NextAdj(*G, v, w);
		cout << endl << endl;
	}
	system("pause");
}