//spfaģ��,�ڽӾ���ʵ�֣��μ�poj2387

#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <memory.h>

using namespace std;

const int MAXN = 1010; 
const int MAX = 10000000;

bool flag[MAXN]; //���ͼ�еĶ����Ƿ�����ɳڶ��У�true��ʾ�ѽ������
int d[MAXN]; //Դ�㵽ͼ�и���������·������
int a[MAXN][MAXN]; //ͼ���ڽӾ���

int spfa(int beg, int end, int n); //����n�������ͼ�У���Դ��beg��Ŀ��end�����·������


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
	queue<int> qu; //�ɳڶ��У�����ö��еĶ�����ڽӵ㽫���ɳ�
	qu.push(beg); //��Դ������ɳڶ���

	//��ʼ��
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