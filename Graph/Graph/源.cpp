#include<iostream>
#include <string>
using namespace std;
#define MVNum 100
#define MaxInt 0
#define Int 1

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
	for (i = 0; i < G.vexnum; ++i)
		for (j = 0; j < G.vexnum; ++j)
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
	return;
}

bool visited[MVNum] = { false };
void DepthFirstSearch(AdjacencyMatrix G, int v)
{
	int w;
	cout << v;
	visited[v] = true;
	for (w = 0; w < G.vexnum; w++)
	{
		if ((G.arcs[v][w] != 0) && (!visited[w]))
			DepthFirstSearch(G, w);
	}
}

int main()
{
	AdjacencyMatrix * G = new AdjacencyMatrix;
	CreateUndirectedGraph(*G);
	int v;
	cout << "请问想从哪个顶点进行遍历" << endl;
	cin >> v;
	DepthFirstSearch(*G, v);

	system("pause");
}