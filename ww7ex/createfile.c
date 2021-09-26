#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
    FILE *text;
    int a=atoi(argv[1]);
    int b=atoi(argv[2]);
    text=fopen("a.txt","a");
    if(text==NULL)
    {
        printf("error\n");
    }
    else
    {
        for(a;a<=b;a++)
        {
            fprintf(text,"%d\n",a);
        }
    }
    fclose(text);
}