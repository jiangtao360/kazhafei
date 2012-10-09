#include<iostream>

using namespace std;

const int MAX = 100;

void CountSort(int *array, int *assistant, int n);

int main()
{
	int n, i;
	cin >> n;

	int *array = new int[n];
	int *assistant = new int[n];
	for(i=0; i<n; i++)
	{
		cin >> array[i];
	}
	CountSort(array,assistant,n);
	for(i=0; i<n; i++)
	{
		cout << assistant[i] <<" ";
	}
	cout << endl;
	return 0;
}

void CountSort(int *array, int *assistant, int n)
{
	int *count = new int[MAX+1];
	int i;

	for(i=0; i<=MAX; i++)
	{
		count[i] = 0;
	}
	for(i=0; i<n; i++)
	{
		count[array[i]]++;
	}
	for(i=1; i<=MAX; i++)
	{
		count[i] = count[i]+count[i-1];
	}
	for(i=n-1; i>=0; i--)
	{
		assistant[count[array[i]]-1] = array[i];
		count[array[i]]--;
	}
}
