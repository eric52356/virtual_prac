//sum_digits
#include <stdio.h>
int main()
{
    int letter=getchar();
    int sum=0;
    int digit=0;
    while(letter!=EOF)
    {
        if(letter>='0'&&letter<='9')
        {
            sum+=(letter-'0');
            digit++;
        }
        letter=getchar();
    }
    printf("Input contained %d digits which summed to %d\n",digit,sum);
    return 0;
}
