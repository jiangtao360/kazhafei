/*    soj4098.cpp
 *
 *    Code Name: 4098: kino
 *    Author: Zero
 *    Date: Wednesday, Mar 21, 2012
 *
 */

#include <cstdio>

int main(void)
{
	int n;

	while(scanf("%d", &n) == 1)
	{
		char seats[51];
		scanf("%s", seats);

		int flag = -1;
		int res = 0;

		for(int i = 0; i < n; i++)
		{
			if(flag == -1)
			{
				res++;
				if(seats[i] == 'L')
					flag = 0;
				else
					flag = -1;
			}
			else if(flag == 0)
			{
				res++;
				flag = 1;
			}
			else
			{
				if(seats[i] == 'L')
					flag = 0;
				else
				{
					flag = 1;
					res++;
				}
			}
		}

		printf("%d\n", res);
	}

	return 0;
}