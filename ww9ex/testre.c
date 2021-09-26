#include <stdio.h>
int c(int a)
{
    int x;
    if(a)
        return (scanf("%d\n",&x)!=EOF);
};
int main()
{
    int a;
    a=c(2);
    printf("%d\n",a);
    return 0;
}