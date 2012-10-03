#include <cstdio>

//test update

int main(void)
{
	int n = 256;
	for(int i=0; i<7; i++)
	{
		printf("%d\n", n);
		n = (n*256) % 16777199;
	}

	return 0;
}