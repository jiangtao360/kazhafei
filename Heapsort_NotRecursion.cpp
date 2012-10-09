//∂—≈≈–Ú£¨≤ªŒ»∂®

#include<iostream> 

using namespace std;

void HeapSort(int *array, int length);

int main()
{
	int n;
	int i;

	cin >> n;
	int *array = new int[n];
	for(i=0; i<n; i++)
	{
		cin >> array[i];
	}
	HeapSort(array,n);
	for(i=0; i<n; i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;

	return 0;
}

void HeapSort(int *array, int length)
{
	void MaxHeapify(int *array, int i, int heapsize);
	void BuildMaxHeap(int *array, int heapsize);

	int heapsize;
	int temp;
	int i;

	BuildMaxHeap(array,length);
	heapsize = length;
	for(i=length-1; i>0; i--)
	{
		heapsize--;
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		MaxHeapify(array,0,heapsize);
	}
}

void MaxHeapify(int *array, int i, int heapsize)
{
	int largest;
	int left;
	int right;
	int temp;

	while(1)
	{
		left = i*2+1;
		right = i*2+2;
		if(left < heapsize && array[left] > array[i])
		{
			largest = left;
		}
		else
		{
			largest = i;
		}
		if(right < heapsize && array[right] > array[largest])
		{
			largest = right;
		}
		if(i != largest)
		{
			temp = array[i];
			array[i] = array[largest];
			array[largest] = temp;
			i = largest;
		}
		else
		{
			break;
		}
	}
}

void BuildMaxHeap(int *array, int heapsize)
{
	int i = heapsize/2-1;

	for(; i>=0; i--)
	{
		MaxHeapify(array,i,heapsize);
	}
}
