//πÈ≤¢≈≈–Ú£¨Œ»∂®

#include<iostream>

using namespace std;

const MAX = 100000;
int temp[MAX];

void MergeSort(int *array, int p, int r);

int main()
{
	int n, i;

	cin >> n;
	int *array = new int[n];
	for(i=0; i<n; i++)
	{
		cin >> array[i];
	}
	MergeSort(array,0,n-1);
	for(i=0; i<n; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	return 0;
}

void MergeSort(int *array, int p, int r)
{

	void Merge(int *array, int p, int q, int r);

	int q;

	if(p < r)
	{
		q = (p+r)/2;
		MergeSort(array,p,q);
		MergeSort(array,q+1,r);
		Merge(array,p,q,r);
	}
}


void Merge(int *array, int p, int q, int r)
{
	int n = r-p+1;
	int i = p, j = q+1, k = 0;

	while(i <= q && j <= r)
	{
		if(array[i] <= array[j])
		{
			temp[k++] = array[i++];
		}
		else
		{
			temp[k++] = array[j++];
		}
	}
	while(i <= q)
	{
		temp[k++] = array[i++];
	}
	while(j <= r)
	{
		temp[k++] = array[j++];
	}
	for(k=0; k<n; k++)
	{
		array[p+k] = temp[k]; 
	}
}