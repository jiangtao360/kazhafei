//Prim模板 o(n2)的算法 参见poj1251

#include <iostream>

using namespace std;

const int MAXN = 30; //图中点的个数的最大值
const int MAX = 0x7fffffff;

int a[MAXN][MAXN]; //图的邻接矩阵
int c[MAXN];  //本次迭代中生成树中的点到其它节点最短边权值估计
bool flag[MAXN]; //用于标记加入生成树中的点，为true时表明该点已经被加入到生成树中，而false则为生成树外的点

int Prim(int n); //给定图的邻接矩阵，图的点的个数，求出该图的最小生成树，并返回最小生成树所有边的权值总和

int main()
{
	int n, m, t, i, j, k;
	char str[10];

	while(scanf("%d",&n), n!=0)
	{
		memset(a,0,sizeof(a));
		for(i=0; i<n-1; i++)
		{
			scanf("%s%d",str,&m);
			k = str[0]-'A';
			for(j=0; j<m; j++)
			{
				scanf("%s%d",str,&t);
				a[k][str[0]-'A'] = a[str[0]-'A'][k] = t;
			}
		}

		printf("%d\n",Prim(n));
	}

	return 0;
}

int Prim(int n)
{
	int i; 
	int min; //用于记录本次迭代中已经在生成树中的所有点到还没添加的所有点之间边的权值的最小值
	int pos; //用于记录本次迭代中添加到生成树中节点的下标值
	int sum = 0; //用于存储最小生成树各边权值的总和

	//初始化，将第0个点加入到生成树中
	memset(flag,0,sizeof(flag)); 
	flag[0] = true;

	//初始化，设置第0个节点到其它节点边的权值
	for(i=1; i<n; i++)
	{
		c[i] = a[0][i] == 0 ? MAX : a[0][i];
	}
	
	//共进行n-1次迭代，在每次迭代中在还没有加入生成树中的点中找出一个与生成树中的点距离最短的点，并将其加入生成树中，并修改生成树中的点到其它节点的最短边权值的估计
	while(true)
	{
		min = MAX, pos = -1;

		//在所有还没加入生成树中的点中找到一个与生成树中的点边权值最短的点
		for(i=0; i<n; i++)
		{
			if(!flag[i] && c[i] < min)
			{
				pos = i, min = c[i];
			}
		}

		if(pos == -1) //没有找到这个点，表明图中所有点已经加入到生成树中了，退出循环
		{
			break;
		}

		sum += min; //累加生成树所有边的总权值
		flag[pos] = true; //将本次迭代找到点加入到生成树中


		//由于有新的节点加入到了生成树中，所以要修改生成树中的点到其它点的最短边权值估计
		for(i=0; i<n; i++)
		{
			if(!flag[i] && a[pos][i]!=0 && a[pos][i] < c[i])
			{
				c[i] = a[pos][i];
			}
		}
	}

	return sum;
}