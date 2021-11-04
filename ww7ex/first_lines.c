#include <stdio.h>
#include <stdlib.h>
int main(int arc,char* argv[])
{
    char i[1024];
    int count=0;
    int a=atoi(argv[2]);
    //char b=atoi(argv[3]);
    FILE* text;
    text=fopen(argv[3],"r");
    while(fgets(i,1024,text)!=NULL)
    {
        if(count==a)
            break;
        printf("%s",i);
        count++;
    }
    fclose(text);
}