#include <stdio.h>
int main()
{
	int n;
	printf("Enter size:");
	scanf("%d",&n);
	for(int r=1;r<=n;r++)
	{
		for(int c=1;c<=n;c++)
		{
			if(c==r||c==(n-r+1))
				printf("*");
			else
				printf("-");
		}
		printf("\n");
	}
}
