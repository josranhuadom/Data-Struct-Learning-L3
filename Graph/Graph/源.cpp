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
	int i, j, k, v1, v2;     //i,j,k���ڼ�����v1,v2���ڴ�������һ���������Ķ���
	cout << "�������ܶ�����" << endl;
	cin >> G.vexnum;
	cout << "�������ܱ���" << endl;
	cin >> G.arcnum;
	cout << "�����붥����Ϣ" << endl;
	for (i = 0; i < G.vexnum; ++i)
		cin >> G.vexs[i];
	//��ʼ���ڽӾ���
	for (i = 1; i <= G.vexnum; ++i)
		for (j = 1; j <= G.vexnum; ++j)
			G.arcs[i][j] = MaxInt;
	for (k = 0; k < G.arcnum; ++k)
	{
		cout << "����һ������������������" << endl;
		cout << "��һ��" << endl;
		cin >> v1;
		cout << "�ڶ���" << endl;
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
		cout << "��������ĸ�������б���" << endl;
		cin >> v;
		cout << "�������Ϊ��" ;
		DepthFirstSearch(*G, v);
		InitVisited();
		w = FirstAdj(*G, v);
		cout << endl;
		cout << v << "�ĵ�һ���ڽӶ���Ϊ��";
		cout << w << endl;
		cout << "����" << w << "����һ���ڽӶ���Ϊ��";
		cout << NextAdj(*G, v, w);
		cout << endl;
	}
	system("pause");
}