//Bellman-Fordģ�� �μ�poj3259

#include <iostream>
#include <vector>

using namespace std;

struct edge //���Ϊu���յ�Ϊv��ȨΪw�ı�
{
	int u, v, w;
};

int d[500]; //���Դ�㵽�����������·������

const int MAX = 0x7ffffff; //���ֵ���������ֵ�������Խ��

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

bool Bellman_Ford(int n, int s) //ͼ����n����㣬�����Դ��s�������������·�������д�Դ��ɴ�ĸ�Ȩ��·�򷵻�false,���򷵻�true
{
	int i, j;

	for(i=0; i<n; i++)  //��ʼ������ֵ
		if(i != s)
			d[i] = MAX;
	d[s] = 0;

	for(i=0; i<n-1; i++) //��ÿ���߽����ɳڣ�һ������n-1��
	{
		for(j=0; j<ve.size(); j++)
		{
			if(d[ve[j].u]+ve[j].w < d[ve[j].v])
				d[ve[j].v] = d[ve[j].u]+ve[j].w;
		}
	}

	for(i=0; i<ve.size(); i++) //����Ƿ����б߿����ɳڣ������ͼ���д�Դ��ɴ�ĸ�Ȩ��·
	{
		if(d[ve[i].v] > d[ve[i].u]+ve[i].w)
			return false;
	}

	return true;
}