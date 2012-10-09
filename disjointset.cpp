//���鼯ģ�� �μ�poj2524

#include <iostream>

using namespace std;

int p[50001]; //���ڴ洢����ɭ����ÿ���ڵ�ĸ��ڵ�
int rank[50001];  //���ڴ洢����ɭ����ÿ���ڵ����
bool flag[50001];

int FindSet(int x) //���ҽڵ�x�������ĸ��ڵ㣬��·��ѹ����ִ�иú��������·���ϵĽڵ㶼��ֱ��ָ�����ĸ��ڵ�
{
	if(x != p[x]) //����û������ڵ�������ݹ����
	{
		p[x] = FindSet(p[x]);
	}

	return p[x]; //������ڵ�󷵻ظ��ڵ�
}

void Link(int x, int y) //�ϲ��ֱ��Խڵ�x�ͽڵ�yΪ����������
{
	if(rank[x] > rank[y]) //��x�ڵ���ȴ���y����xΪy�ĸ��ڵ㣬����yΪx�ĸ��ڵ�
	{
		p[y] = x;
	}
	else
	{
		p[x] = y;
		if(rank[x] == rank[y]) //��x��y������ͬ�����ܵ��ȼ�1,���򱣳�ԭ�����Ȳ���
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
