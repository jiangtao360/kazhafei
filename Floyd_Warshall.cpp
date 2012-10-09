//Floyd-Warshallģ�� �μ�poj 1125

#include <iostream>

using namespace std;

int a[100][100]; //����ͼ���ڽӾ���

const int MAX = 10000; //�˴����ܶ������ֵ����Ȼ��Խ��

void Floyd_Warshall (int n);

int main()
{
	int n, i, j, m, k, l, ans, t, in;
	bool flag;

	while(scanf("%d",&n), n != 0)
	{
		//��ʼ���ڽӾ��󣬳����Լ����Լ�Ϊ0���������㶼Ϊ���ֵ
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

void Floyd_Warshall (int n) //����ͼ���ڽӾ��󣬷���ͼ��ÿ�Զ���֮������·��
{
	int i, j, k;

	for(k=0; k<n; k++) //����ѭ���Ե����ϵؼ������·��Ȩֵ��DP
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				a[i][j] = a[i][j] < (a[i][k]+a[k][j]) ? a[i][j] : (a[i][k]+a[k][j]);

}