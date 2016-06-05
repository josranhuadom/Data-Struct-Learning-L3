#include<iostream>
#include <string>
using namespace std;

//ͼ���ڽӾ���洢��ʾ
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

//ʹ���ڽӾ����ʾ����������ͼ
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
	//��ʼ���ڽӾ��󣬱ߵ�Ȩֵ���ֵΪMaxInt����Ϊ0
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
		G.arcs[i][j] = Int;             //��<v1,v2>��Ȩֵ��0��ΪInt����Ϊ1
		G.arcs[j][i] = G.arcs[i][j];  //<v1,v2>�ĶԳƱ�<v2,v1>��ȨֵҲ����Ϊ1
	}
}

//���������������Ȼ������FirstAdj() �� NextAdj()��������ѡ�񲻵�������������
void DepthFirstSearch(AdjacencyMatrix G, int v)
{
	int w;
	cout << v;                  //���ʵ�v������
	visited[v] = true;       //���÷��ʱ�־������Ӧ����ֵΪtrue
	for (w = 1; w <= G.vexnum; w++)   
	{
		if ((G.arcs[v][w] != 0) && (!visited[w]))
			DepthFirstSearch(G, w);
		//G.arcs[v][w] != 0 ��ʾ w �� v ���ڽӵ㣬��� w δ���ʣ���ݹ���ô˺���
	}
}

//���ڽӱ����еķ��ʱ�־������Ӧ����ֵ��Ϊfalse�� �Ա������ʵ�� FirstAdj() �� NextAdj() ����
void InitVisited()
{
	for (int i = 0; i < MVNum; i++)
		visited[i] = false;
}

//���ʶ���v�ĵ�һ���ڽӶ���
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
		//�����붥�� v ��ص� ����w��������ڣ�����֮ǰû�б���������������ֵΪfalse������return��ֵ�����������ֵΪ true
	}
	return -1;    //���û�п��� return ��ֵ���� return -1
}

int NextAdj(AdjacencyMatrix G, int v, int w)
{
	int r;
	for (r = w; r <= G.vexnum; r++)     //r Ϊ���� return ��ֵ������еĻ������� r ֱ�Ӵ� w ��ʼ������
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
		cout << endl << endl;
	}
	system("pause");
}