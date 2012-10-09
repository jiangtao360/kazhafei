//朴素的Dijkstra，O(n^2)，参见poj2387

#include <iostream>

using namespace std;

const int MAX = 0x7fffffff;

int a[1000][1000]; //图的邻接矩阵
int d[1000];  //从源点到图中每个顶点的最短路径估计
bool flag[1000]; //用于标记图中的顶点的最短路径是否已经确定，若确定则为true

int Dijkstra(int s, int t, int n); //在有n个顶点的图上，顶点s到顶点t的最短路径的长度

int main()
{
	int n, m, i, j, p, q, c;

	scanf("%d%d",&m,&n);
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			a[i][j] = -1;

	for(i=0; i<m; i++)
	{
		scanf("%d%d%d",&p,&q,&c);
		if(a[p-1][q-1] == -1)
			a[p-1][q-1] = a[q-1][p-1] = c;
		else
		{
			if(a[p-1][q-1] > c)
				a[p-1][q-1] = a[q-1][p-1] = c;
		}
	}
	printf("%d\n",Dijkstra(0,n-1,n));

	return 0;
}

int Dijkstra(int s, int t, int n)
{
	int min, pos, i;

	//初始化
	for(i=0; i<n; i++)
	{
		d[i] = MAX, flag[i] = false;
	}
	d[s] = 0;

	while(true)
	{

		//从所有顶点的最短路径估计里面找到一个最短的加进确定集合
		min = MAX;
		for(i=0; i<n; i++)
		{
			if(!flag[i] && d[i] < min)
			{
				min = d[i], pos = i;
			}
		}
		
		//目的顶点已确定最短路径，立即返回
		if(pos == t)
		{
			return d[t];
		}

		flag[pos] = true;

		//对本次迭代加入的点的所有邻接点进行松弛操作
		for(i=0; i<n; i++)
		{
			if(!flag[i] && a[pos][i]!=-1 && d[pos]+a[pos][i] < d[i])
				d[i] = d[pos]+a[pos][i];
		}
	}
}

