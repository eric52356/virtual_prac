#include <stdio.h>
int main()
{
    char i[4096];
    printf("Enter a string: ");
    while(fgets(i,4096,stdin)!=NULL)
    {
        int count=0;
        while(i[count]!='\n')
        {
            printf("%c\n",i[count]);
            count++;
        }
    }
    return 0;
}