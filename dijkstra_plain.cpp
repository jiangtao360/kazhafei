//���ص�Dijkstra��O(n^2)���μ�poj2387

#include <iostream>

using namespace std;

const int MAX = 0x7fffffff;

int a[1000][1000]; //ͼ���ڽӾ���
int d[1000];  //��Դ�㵽ͼ��ÿ����������·������
bool flag[1000]; //���ڱ��ͼ�еĶ�������·���Ƿ��Ѿ�ȷ������ȷ����Ϊtrue

int Dijkstra(int s, int t, int n); //����n�������ͼ�ϣ�����s������t�����·���ĳ���

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

	//��ʼ��
	for(i=0; i<n; i++)
	{
		d[i] = MAX, flag[i] = false;
	}
	d[s] = 0;

	while(true)
	{

		//�����ж�������·�����������ҵ�һ����̵ļӽ�ȷ������
		min = MAX;
		for(i=0; i<n; i++)
		{
			if(!flag[i] && d[i] < min)
			{
				min = d[i], pos = i;
			}
		}
		
		//Ŀ�Ķ�����ȷ�����·������������
		if(pos == t)
		{
			return d[t];
		}

		flag[pos] = true;

		//�Ա��ε�������ĵ�������ڽӵ�����ɳڲ���
		for(i=0; i<n; i++)
		{
			if(!flag[i] && a[pos][i]!=-1 && d[pos]+a[pos][i] < d[i])
				d[i] = d[pos]+a[pos][i];
		}
	}
}

