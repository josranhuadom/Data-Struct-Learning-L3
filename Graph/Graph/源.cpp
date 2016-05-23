#include<iostream>
using namespace std;
#define MVNum 100
#define MaxInt 0

/*int VerTexType;
int ArcType;*/

struct GraphAM
{
	int vexs[MVNum];
	int arcs[MVNum];
	int vexnum, arcnum;
};

void CreateUDN(GraphAM &G)
{
	int i, j, k, v1, v2, w; //i,j,k用于计数，v1,v2用于储存输入一条边依附的顶点，w用于储存输入的全职
	cout << "请输入……" << endl;
	cin >> G.vexnum >> G.arcnum;
	for (i = 0; i < G.vexnum; ++i)
		cin >> G.vexs[i];
	for (i = 0; i < G.vexnum; ++i)
		for (j = 0; j < G.vexnum; ++j)
			G.arcs[i][j] = MaxInt;
	for (k = 0; k < G.arcnum; ++k)
	{
		cin >> v1 >> v2 >> w;

	}
}

int main()
{
	GraphAM * G;
}