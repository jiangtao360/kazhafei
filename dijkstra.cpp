//dijkstra模板 最小堆实现 o(mlogn)的算法 参见poj3159

#include <iostream>

using namespace std;

#define left(x) ((x)<<1) //用于在堆中找出x节点的左孩子
#define right(x) (((x)<<1)+1) //用于在堆中找出x节点的右孩子
#define parent(x) ((x)>>1) //用于在堆中找出x节点的父节点

const int MAX = 0x7fffffff;
const int N = 30010; //图中节点的最大个数
const int M = 150010; //图中边的最大个数

struct node //图中的一个节点，边用邻接表表示
{
	int in; //该节点的下标
	int w; //邻接表中源节点到该节点边的权值
	node *next; //指向邻接表中的下一个节点
};
node a[N]; //用于存储图中每个顶点邻接表的第一项
node mem[M]; //预先定义所有边，防止超时

int heap[3*N]; //用于存储堆中每个节点代表的图中节点的下标
int d[N]; //图中源节点到每个节点的最短路径估计
int map[N]; //图中节点下标到堆中存储该节点的元素下标的映射
int heapsize; //堆中节点的个数
int mem_size; //图中边的条数

node* new_node(int id, int w) //在邻接表中新建一条边，该边目的结点下标为id，权为w
{
	 mem[mem_size].in = id;
	 mem[mem_size].w = w;
	 mem[mem_size++].next = NULL;
     return mem+mem_size-1;
}

int n, m;

void heap_down(int i) //在堆中以i为根结点的子树不符合堆的性质，要用i与其子结点交换，维持堆的性质
{
	int l, r, b, temp;
	
	temp = heap[i]; //先将i中的结点取出来
	while(true) //以i为根结点向下遍历直到i到达其儿子结点都大于或等于它的位置或者到达叶结点
	{
		b = i;
		l = left(i), r = right(i);
		if(l <= heapsize) 
			b = l;
		if(r <= heapsize && d[heap[r]] < d[heap[l]])
			b = r;
		if(b!=i && d[heap[b]] < d[temp]) //若其儿子结点有比它小的，则将其和儿子结点交换，此处实际上没进行交换，只是将儿子结点的值赋给它，最后才将i结点的值赋回
		{
			heap[i] = heap[b];
			map[heap[b]] = i;
			i = b;
		}
		else
			break;
	}
	heap[i] = temp; //最后将i结点赋给最终到达的位置
	map[temp] = i;
}

void heap_up(int i) //当i结点比它父亲结点的值还小时，破坏了堆的性质，所以必须将i结点上移以维持堆的性质
{
	int temp, p;

	temp = heap[i]; //先将i结点的值赋给临时变量
	while(true) //从i结点向上遍历，一直找到其父亲结点比它值小时或到达根结点
	{
		p = parent(i);
		if(p >=1 && d[temp] < d[heap[p]]) //若其父亲结点的值比它大，则将i结点上移
		{
			heap[i] = heap[p];
			map[heap[p]] = i;
			i = p;
		}
		else
			break;
	}
	heap[i] = temp; //将i结点的值赋回其最终到达的位置
	map[temp] = i;
}

int heap_pop() //弹出堆的根结点，即堆中最小的元素
{
	int min = heap[1]; //将根结点的值赋出来
	heap[1] = heap[heapsize--]; //减少堆的个数，并且用堆的最后一个元素覆盖第一个元素
	map[heap[1]] = 1; //重新设置映射
	heap_down(1); //由于现在根结点改变了，堆的性质有可能被破坏，所以要维护堆的性质
	return min;
}

int Dijkstra(int s, int t) //输入图的邻接表，源结点s，目的结点t，输出s到t的最短距离，同时可以求出s到图中其它结点的最短路径
{
	int i, u;
	node *p;

	for(i=1; i<=n; i++) //初始化
	{
		d[i] = MAX;
		heap[i] = i;
		map[i] = i;
	}
	heapsize = n;
    swap(heap[1],heap[s]); //将s作为堆的根结点
    swap(map[1],map[s]);
    d[s] = 0; 

	for(i=0; i<n; i++) //总共进行n次迭代，每次从堆中找出一个从s到所有还没有确定最短路径的结点中最短路径估计最小的值，这样就可确定找到的这个点已经确定了s到其的最短路径，对其到还没有确定的点的所有边进行松弛操作
	{
		u = heap_pop(); //从所有还没有确定的点中找出最短的路径估计
		if(u == t) //若该点为t则可确定已经找到了s到t的最短路径，终止循环
			break;
		for(p=a[u].next; p!=NULL; p=p->next) //对找到的u点到其邻接并且还未确定的所有点的边进行松弛操作，而后还要维护堆的性质
		{
			if(d[u]+p->w < d[p->in])
			{
				d[p->in] = d[u]+p->w; //松弛操作
				heap_up(map[p->in]); //堆中的元素改变了，需要维护其性质
			}
		}
	}

	return d[t]; //返回s到t的最短路径的权值
}

int main()
{
	int p, q, c, i;
	node *temp;

	scanf("%d%d",&n,&m);
	for(i=0; i<m; i++)
	{
		scanf("%d%d%d",&p,&q,&c);
	
		//以p为顶点的邻接表中添加一条边
		temp = a[p].next;
		a[p].next =new_node(q,c);
		a[p].next->next = temp;
		
	}
	printf("%d\n",Dijkstra(1,n));

	return 0;
}

