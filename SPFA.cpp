//spfa模板,邻接矩阵实现，参见poj2387

#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <memory.h>

using namespace std;

const int MAXN = 1010; 
const int MAX = 10000000;

bool flag[MAXN]; //标记图中的顶点是否进入松弛队列，true表示已进入队列
int d[MAXN]; //源点到图中各顶点的最短路径估计
int a[MAXN][MAXN]; //图的邻接矩阵

int spfa(int beg, int end, int n); //在有n个顶点的图中，从源点beg到目的end的最短路径长度


int main()
{
	int m, n, p, q, c;
	int i, j;


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
	memset(flag,0,sizeof(flag));
	printf("%d\n",spfa(0,n-1,n));


	

	return 0;
}

int spfa(int beg, int end, int n)
{
	queue<int> qu; //松弛队列，进入该队列的顶点的邻接点将被松弛
	qu.push(beg); //将源点放入松弛队列

	//初始化
	int i;
	for(i=0; i<n; ++i)
		d[i] = MAX;
	d[beg] = 0;
	flag[beg] = true;

	while(!qu.empty())
	{
		int v = qu.front();
		qu.pop();
		flag[v] = false;

		for(i=0; i<n; ++i)
		{
			if(a[v][i] != -1 && d[v] +a[v][i] < d[i])
			{
				d[i] = d[v] + a[v][i];
				if(!flag[i])
				{
					qu.push(i);
					flag[i] = true;
				}
			}
		}
	}

	return d[end];
}