//≤Â»Î≈≈–Ú£¨Œ»∂®

#include<iostream>

using namespace std;

void InsertionSort(int *array, int n);

int main()
{
	int n, i;
	cin >> n;
	int *array = new int[n];

	for(i=0; i<n; i++)
	{
		cin >> array[i];
	}
	InsertionSort(array,n);
	for(i=0; i<n; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	return 0;
}

void InsertionSort(int *array, int length)
{
	int i, j;
	int temp;

	for(i=1; i<length; i++)
	{
		temp = array[i];
		j = i-1;
		while(j >= 0 && temp < array[j])
		{
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = temp;
	}
}