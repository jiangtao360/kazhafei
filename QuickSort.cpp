//快速排序,不稳定

#include<iostream>
#include<time.h>

using namespace std;

void QuickSort(int *array, int p, int r);

int main()
{
	int n, i;

	srand((unsigned)time(NULL));
	cin >> n;
	int *array = new int[n];

	for(i=0; i<n; i++)
	{
		cin >> array[i];
	}
	QuickSort(array,0,n-1);
	for(i=0; i<n; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	return 0;
}

void QuickSort(int *array, int p, int r)
{
    int i, j;
    int temp;

    if(p < r)
    {
        i = rand()%(r-p+1)+p;
        temp = array[i];
        array[i] = array[p];
        array[p] = temp;

        i = p;
        for(j=p+1; j<=r; j++)
        {
            if(array[j] < array[p])
            {
                i++;
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        temp = array[i];
        array[i] = array[p];
        array[p] = temp;
        QuickSort(array,p,i-1);
        QuickSort(array,i+1,r);
    }
}