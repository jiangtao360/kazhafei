//Bellman-Ford模板 参见poj3259

#include <iostream>
#include <vector>

using namespace std;

struct edge //起点为u，终点为v，权为w的边
{
	int u, v, w;
};

int d[500]; //存放源点到其他结点的最短路径估计

const int MAX = 0x7ffffff; //这个值不能是最大值，否则会越界

edge e;
vector<edge> ve;

bool Bellman_Ford(int n, int s);

int main()
{
	int t, n, m, w;
	int i, x, y, l;

	scanf("%d",&t);
	while(t--)
	{
		ve.clear();
		scanf("%d%d%d",&n,&m,&w);
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d",&x,&y,&l);
			e.u = x, e.v = y, e.w = l;
			ve.push_back(e);
			e.u = y, e.v = x, e.w = l;
			ve.push_back(e);
		}
		for(i=0; i<w; i++)
		{
			scanf("%d%d%d",&x,&y,&l);
			e.u = x, e.v = y, e.w = -l;
			ve.push_back(e);
		}
		if(Bellman_Ford(n,0))
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}

bool Bellman_Ford(int n, int s) //图共有n个结点，计算从源点s到其他结点的最短路径，若有从源点可达的负权回路则返回false,否则返回true
{
	int i, j;

	for(i=0; i<n; i++)  //初始化估计值
		if(i != s)
			d[i] = MAX;
	d[s] = 0;

	for(i=0; i<n-1; i++) //对每条边进行松弛，一共进行n-1次
	{
		for(j=0; j<ve.size(); j++)
		{
			if(d[ve[j].u]+ve[j].w < d[ve[j].v])
				d[ve[j].v] = d[ve[j].u]+ve[j].w;
		}
	}

	for(i=0; i<ve.size(); i++) //最后还是发现有边可以松弛，则表明图中有从源点可达的负权回路
	{
		if(d[ve[i].v] > d[ve[i].u]+ve[i].w)
			return false;
	}

	return true;
}