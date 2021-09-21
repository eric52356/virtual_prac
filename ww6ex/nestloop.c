#include <stdio.h>
int main()
{
    int row=0;
    int column=0;
    int number;
    int sum=0;
    printf("Enter a number: ");
    scanf("%d",&number);
    for(column=0;column<number;column++)
    {
        for(row=0;row<number;row++)
        {
            printf("%5d",row*column);
            sum+=row*column;
        }
        printf("|%5d\n",sum);
    }
    while(row>0)
    {
        printf("-----");
        row--;
    }
    printf("\n");
    for(int row=0;row<number;row++)
    {
        int sum=0;
        for(int column=0;column<number;column++)
        {
            sum+=row*column;
        }
        printf("%5d",sum);
    }
    printf("\n");
    return 0;
}