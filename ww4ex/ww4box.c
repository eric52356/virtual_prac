#include <stdio.h>
int main()
{
	int box;	
	printf("how many boxes:");
	scanf("%d",&box);
	int edge=(box-1)*2*2+3;
	for(int r=1;r<=edge;r++)
	{
		for(int c=1;c<=edge;c++)
		{
			if(r%2||c==1||c==edge)
			{
				printf("#");
			}
			else			
				printf(" ");
		}
		printf("\n");
	}
}
