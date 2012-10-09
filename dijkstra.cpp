//dijkstraģ�� ��С��ʵ�� o(mlogn)���㷨 �μ�poj3159

#include <iostream>

using namespace std;

#define left(x) ((x)<<1) //�����ڶ����ҳ�x�ڵ������
#define right(x) (((x)<<1)+1) //�����ڶ����ҳ�x�ڵ���Һ���
#define parent(x) ((x)>>1) //�����ڶ����ҳ�x�ڵ�ĸ��ڵ�

const int MAX = 0x7fffffff;
const int N = 30010; //ͼ�нڵ��������
const int M = 150010; //ͼ�бߵ�������

struct node //ͼ�е�һ���ڵ㣬�����ڽӱ��ʾ
{
	int in; //�ýڵ���±�
	int w; //�ڽӱ���Դ�ڵ㵽�ýڵ�ߵ�Ȩֵ
	node *next; //ָ���ڽӱ��е���һ���ڵ�
};
node a[N]; //���ڴ洢ͼ��ÿ�������ڽӱ�ĵ�һ��
node mem[M]; //Ԥ�ȶ������бߣ���ֹ��ʱ

int heap[3*N]; //���ڴ洢����ÿ���ڵ�����ͼ�нڵ���±�
int d[N]; //ͼ��Դ�ڵ㵽ÿ���ڵ�����·������
int map[N]; //ͼ�нڵ��±굽���д洢�ýڵ��Ԫ���±��ӳ��
int heapsize; //���нڵ�ĸ���
int mem_size; //ͼ�бߵ�����

node* new_node(int id, int w) //���ڽӱ����½�һ���ߣ��ñ�Ŀ�Ľ���±�Ϊid��ȨΪw
{
	 mem[mem_size].in = id;
	 mem[mem_size].w = w;
	 mem[mem_size++].next = NULL;
     return mem+mem_size-1;
}

int n, m;

void heap_down(int i) //�ڶ�����iΪ���������������϶ѵ����ʣ�Ҫ��i�����ӽ�㽻����ά�ֶѵ�����
{
	int l, r, b, temp;
	
	temp = heap[i]; //�Ƚ�i�еĽ��ȡ����
	while(true) //��iΪ��������±���ֱ��i��������ӽ�㶼���ڻ��������λ�û��ߵ���Ҷ���
	{
		b = i;
		l = left(i), r = right(i);
		if(l <= heapsize) 
			b = l;
		if(r <= heapsize && d[heap[r]] < d[heap[l]])
			b = r;
		if(b!=i && d[heap[b]] < d[temp]) //������ӽ���б���С�ģ�����Ͷ��ӽ�㽻�����˴�ʵ����û���н�����ֻ�ǽ����ӽ���ֵ�����������Ž�i����ֵ����
		{
			heap[i] = heap[b];
			map[heap[b]] = i;
			i = b;
		}
		else
			break;
	}
	heap[i] = temp; //���i��㸳�����յ����λ��
	map[temp] = i;
}

void heap_up(int i) //��i���������׽���ֵ��Сʱ���ƻ��˶ѵ����ʣ����Ա��뽫i���������ά�ֶѵ�����
{
	int temp, p;

	temp = heap[i]; //�Ƚ�i����ֵ������ʱ����
	while(true) //��i������ϱ�����һֱ�ҵ��丸�׽�����ֵСʱ�򵽴�����
	{
		p = parent(i);
		if(p >=1 && d[temp] < d[heap[p]]) //���丸�׽���ֵ��������i�������
		{
			heap[i] = heap[p];
			map[heap[p]] = i;
			i = p;
		}
		else
			break;
	}
	heap[i] = temp; //��i����ֵ���������յ����λ��
	map[temp] = i;
}

int heap_pop() //�����ѵĸ���㣬��������С��Ԫ��
{
	int min = heap[1]; //��������ֵ������
	heap[1] = heap[heapsize--]; //���ٶѵĸ����������öѵ����һ��Ԫ�ظ��ǵ�һ��Ԫ��
	map[heap[1]] = 1; //��������ӳ��
	heap_down(1); //�������ڸ����ı��ˣ��ѵ������п��ܱ��ƻ�������Ҫά���ѵ�����
	return min;
}

int Dijkstra(int s, int t) //����ͼ���ڽӱ�Դ���s��Ŀ�Ľ��t�����s��t����̾��룬ͬʱ�������s��ͼ�������������·��
{
	int i, u;
	node *p;

	for(i=1; i<=n; i++) //��ʼ��
	{
		d[i] = MAX;
		heap[i] = i;
		map[i] = i;
	}
	heapsize = n;
    swap(heap[1],heap[s]); //��s��Ϊ�ѵĸ����
    swap(map[1],map[s]);
    d[s] = 0; 

	for(i=0; i<n; i++) //�ܹ�����n�ε�����ÿ�δӶ����ҳ�һ����s�����л�û��ȷ�����·���Ľ�������·��������С��ֵ�������Ϳ�ȷ���ҵ���������Ѿ�ȷ����s��������·�������䵽��û��ȷ���ĵ�����б߽����ɳڲ���
	{
		u = heap_pop(); //�����л�û��ȷ���ĵ����ҳ���̵�·������
		if(u == t) //���õ�Ϊt���ȷ���Ѿ��ҵ���s��t�����·������ֹѭ��
			break;
		for(p=a[u].next; p!=NULL; p=p->next) //���ҵ���u�㵽���ڽӲ��һ�δȷ�������е�ı߽����ɳڲ���������Ҫά���ѵ�����
		{
			if(d[u]+p->w < d[p->in])
			{
				d[p->in] = d[u]+p->w; //�ɳڲ���
				heap_up(map[p->in]); //���е�Ԫ�ظı��ˣ���Ҫά��������
			}
		}
	}

	return d[t]; //����s��t�����·����Ȩֵ
}

int main()
{
	int p, q, c, i;
	node *temp;

	scanf("%d%d",&n,&m);
	for(i=0; i<m; i++)
	{
		scanf("%d%d%d",&p,&q,&c);
	
		//��pΪ������ڽӱ������һ����
		temp = a[p].next;
		a[p].next =new_node(q,c);
		a[p].next->next = temp;
		
	}
	printf("%d\n",Dijkstra(1,n));

	return 0;
}

