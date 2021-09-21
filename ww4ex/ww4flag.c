#include <stdio.h>
int main()
{
	int size;
    int wide,high;//3,2
	printf("Enter the flag size:");
	scanf("%d",&size);
	for(high=1;high<=size*2*2;high++)
    {
        for(wide=1;wide<=size*3*3;wide++)
        {
            if(wide==size*3||wide==(size*3)+1||high==size*2||high==(size*2)+1)
            	printf(" ");
			else
				printf("#");        
		}
    	printf("\n");
	}
}
