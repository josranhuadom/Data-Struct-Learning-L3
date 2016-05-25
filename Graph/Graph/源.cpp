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
	return;
}

bool visited[MVNum] = { false };
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

int FirstAdj(AdjacencyMatrix G, int v)
{
	int w;
	for (w = 1; w <= G.vexnum; w++)
	{
		if (G.arcs[v][w] != 0)
			return w;
	}
}

int NextAdj(AdjacencyMatrix G, int v, int r)
{

}

int main()
{
	AdjacencyMatrix * G = new AdjacencyMatrix;
	CreateUndirectedGraph(*G);
	int v, r;
	cout << "��������ĸ�������б���" << endl;
	cin >> v;
	DepthFirstSearch(*G, v);
	r =FirstAdj(*G, v);
	cout << r << endl;
	NextAdj(*G, v, r);
	
	system("pause");
}