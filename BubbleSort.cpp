//√∞≈›≈≈–Ú£¨Œ»∂®

#include<iostream>

using namespace std;

void BubbleSort(int *array, int length);

int main()
{
	int n, i;

	cin >> n;
	int *array = new int[n];
	for(i=0; i<n; i++)
	{
		cin >> array[i];
	}
	BubbleSort(array,n);
	for(i=0; i<n; i++)
	{
		cout << array[i] <<" ";
	}
	cout<<endl;

	return 0;
}

void BubbleSort(int *array, int length)
{
	int i, j;
	int temp;

	for(i=0; i<length; i++)
	{
		for(j=length-1; j>i; j--)
		{
			if(array[j-1] > array[j])
			{
				temp = array[j-1];
				array[j-1] = array[j];
				array[j] = temp;
			}
		}
	}
}