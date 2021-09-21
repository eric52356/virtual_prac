#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    fp=fopen("file.txt","a");
    char i[4096];
    int sum=0;
    int count=0;
    if(fgets(i,4096,stdin)!=NULL)
    {
        while(i[count]!='\n')
        {
        fprintf(fp,"%c",i[count]);
            sum++;
            count++;
        }
    }
    printf("line %d characters long\n",sum);
    fprintf(fp,"\nline %d characters long\n",sum);
    fclose(fp);
    return 0;
}