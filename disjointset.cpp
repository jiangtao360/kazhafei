//并查集模板 参见poj2524

#include <iostream>

using namespace std;

int p[50001]; //用于存储集合森林中每个节点的父节点
int rank[50001];  //用于存储集合森林中每个节点的秩
bool flag[50001];

int FindSet(int x) //查找节点x所在树的根节点，带路径压缩，执行该函数后查找路径上的节点都将直接指向树的根节点
{
	if(x != p[x]) //若还没到达根节点则继续递归调用
	{
		p[x] = FindSet(p[x]);
	}

	return p[x]; //到达根节点后返回根节点
}

void Link(int x, int y) //合并分别以节点x和节点y为根的两棵树
{
	if(rank[x] > rank[y]) //若x节点的秩大于y，则x为y的父节点，否则y为x的父节点
	{
		p[y] = x;
	}
	else
	{
		p[x] = y;
		if(rank[x] == rank[y]) //若x和y的秩相同，则总的秩加1,否则保持原来的秩不变
		{
			rank[y]++;
		}
	}
}

int main()
{
	int n, m, t, x, y, i,tx, ty, ans;

	t = 1;
	while(true)
	{
		scanf("%d%d",&n,&m);
		if(n == 0 && m == 0)
		{
			break;
		}

		for(i=1; i<=n; i++)
		{
			p[i] = i;
		}
		memset(rank,0,sizeof(rank));
		
		for(i=0; i<m; i++)
		{
			scanf("%d%d",&x,&y);
			tx = FindSet(x), ty = FindSet(y);
			if(tx != ty)
			{
				Link(tx,ty);
			}
		}

		ans = 0;
		memset(flag,0,sizeof(flag));
		for(i=1; i<=n; i++)
		{
			tx = FindSet(i);
			if(!flag[tx])
			{
				ans++;
				flag[tx] = true;
			}
		}
		printf("Case %d: %d\n",t,ans);
		t++;
	}

	return 0;
}
