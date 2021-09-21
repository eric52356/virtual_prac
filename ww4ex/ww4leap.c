#include <stdio.h>
int year(int a)
{
	if(a%4==0)
		return 1;
	else
		return 0;
}
int main()
{
	printf("Enter year:");	
	int a,b;
	scanf("%d",&a);	
	printf("%d\n",a);	
	if(year(a))
	{	
		printf("%d is a leap year\n",a);
	}	
	else
		printf("%d is not a leap year\n",a);
	return 0;
}
