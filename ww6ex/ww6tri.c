//letter_triangle
#include <stdio.h>
int main()
{
    int height;
    int column=0;
    int letter='A';
    printf("Enter height: ");
    scanf("%d",&height); 
    int b=height;   
    while(column<height)
    {
        int count=0;
        int space=0;
        while(space<b)
        {
            printf(" ");
            space++;
        }
        b--;
        while(count<2*column+1)
        {
            if(space+count>height)
            {
                //printf("'%c'",letter);
                int a=1;
                while(a<=2*column+1-count)
                {
                    a++;
                    if(letter-a<'A')
                        printf("%c",letter-a+26);
                    else
                        printf("%c",letter-a);
                }
                count=2*column+1;
                //printf("%d",count);
            }
            else
            {
                printf("%c",letter);
                letter++;
                if(letter>'Z')
                {
                    letter='A';
                }
            }
            count++;
        }
        printf("\n");
        column++;
    }
    
    return 0;
}
/*int main()
{
    int height;
    int count='A';//1->A;
    printf("Enter height: ");
    scanf("%d",&height);
    int copy=height;
    for(int a=0;a<height;a++)
    {
        int space=1;
        while(space<copy)
        {
            printf(" ");
            space++;
        }
        space--;
        copy--;
        int b=0;
        while(b<height-space)
        {
            printf("%c",count);
            count++;
            b++;
        }
        printf("\n");

    }
}*/