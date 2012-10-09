//Floyd-Warshall模板 参见poj 1125

#include <iostream>

using namespace std;

int a[100][100]; //定义图的邻接矩阵

const int MAX = 10000; //此处不能定义最大值，不然会越界

void Floyd_Warshall (int n);

int main()
{
	int n, i, j, m, k, l, ans, t, in;
	bool flag;

	while(scanf("%d",&n), n != 0)
	{
		//初始化邻接矩阵，除了自己到自己为0，到其它点都为最大值
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				a[i][j] = MAX;
		for(i=0; i<n; i++)
			a[i][i] = 0;

		for(i=0; i<n; i++)
		{
			scanf("%d",&m);
			for(j=0; j<m; j++)
			{
				scanf("%d%d",&k,&l);
				a[i][k-1] = l;
			}
		}

		Floyd_Warshall(n);

		ans = MAX;
		for(i=0; i<n; i++)
		{
			t = -1, flag = 0;
			for(j=0; j<n; j++)
			{
				if(i != j)
				{
					if(a[i][j] == MAX)
					{
						flag = 1; 
						break;
					}
					else
						t = t > a[i][j] ? t : a[i][j];
				}
			}
			if(flag)
				continue;
			if(t < ans)
				ans = t, in = i;
		}

		if(ans == MAX)
			printf("disjoint\n");
		else
			printf("%d %d\n",in+1,ans);
	}

	return 0;
}

void Floyd_Warshall (int n) //输入图的邻接矩阵，返回图中每对顶点之间的最短路径
{
	int i, j, k;

	for(k=0; k<n; k++) //三重循环自底向上地计算最短路径权值，DP
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				a[i][j] = a[i][j] < (a[i][k]+a[k][j]) ? a[i][j] : (a[i][k]+a[k][j]);

}