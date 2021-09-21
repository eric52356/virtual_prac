#include <stdio.h>
int main()
{
	int a,b=1,sum=0;
	printf("Enter number:");
	scanf("%d",&a);
	while(b<=a)
	{
		if(a%b==0)
		{
			printf("%d\n",b);
			sum=sum+b;
		}
		b++;
	}
	printf("sum = %d\n",sum);
	if(sum/2==a)
		printf("%d is a perfect number",a);
	return 0;
}
