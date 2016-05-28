#include<iostream>
#include <string>
using namespace std;
#define MVNum 100
#define MaxInt 0
#define Int 1
bool visited[MVNum];

/*int VerTexType;
int ArcType;*/

struct AdjacencyMatrix
{
	string vexs[MVNum];
	int arcs[MVNum][MVNum];
	int vexnum, arcnum;
};

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
	//初始化邻接矩阵
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
		G.arcs[i][j] = Int;
		G.arcs[j][i] = G.arcs[i][j];
	}
}

void DepthFirstSearch(AdjacencyMatrix G, int v)
{
	int w;
	cout << v;
	visited[v] = true;
	for (w = 1; w <= G.vexnum; w++)
	{
		if ((G.arcs[v][w] != 0) && (!visited[w]))
			DepthFirstSearch(G, w);
	}
}

void InitVisited()
{
	for (int i = 0; i < MVNum; i++)
		visited[i] = false;
}

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
	}
	return -1;
}

int NextAdj(AdjacencyMatrix G, int v, int w)
{
	int r;
	for (r = w; r <= G.vexnum; r++)
	{
		if ((G.arcs[v][r] != 0) && (!visited[r]))
		{
			visited[w] = true;
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
		cout << endl;
	}
	system("pause");
}