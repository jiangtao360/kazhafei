//—°‘Ò≈≈–Ú£¨≤ªŒ»∂®

#include <iostream>

using namespace std;

void SelectSort(int *p, int n)
{
	int i, j, k;
	int temp;

	for(i=0; i<n-1; i++)
	{
		k = i;
		for(j=i; j<n; j++)
		{
			if(p[j] < p[k])
				k = j;
		}
		if(k != i)
		{
			temp = p[i];
			p[i] = p[k];
			p[k] = temp;
		}
	}
}

int main()
{
	int *p = new int[100];
	int i, n;

	cin >> n;
	for(i=0; i<n; i++)
		cin >> p[i];

	SelectSort(p,n);

	for(i=0; i<n; i++)
		cout << p[i] << " ";
	cout << endl;

	return 0;
}

