#include <stdio.h>
int main()
{
    char i[4096];
    //int tag=1;    
    printf("Enter a string: ");
    if(fgets(i,4096,stdin)!=NULL)
    {
        int tag=1;
        int count=0;
        int a=0;
        while(i[count]!='\n')
        {
            count++;
        }
        count--;
        //printf("%d\n",count);
        while(a<=count)
        {
            if(i[a]!=i[count-a])
            {
                tag=0;
            }
            a++;
        }
        if(tag)
            printf("String is a palindrome\n");
        else
            printf("String is not a palindrome\n");    
    }
    /*if(tag)
        printf("String is a palindrome\n");
    else
        printf("String is not a palindrome\n");*/

    return 0;
}