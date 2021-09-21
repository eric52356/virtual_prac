//Working Out the Letter Frequencies of Text
#include <stdio.h>
int calculate(int count[26],int letter);
int main()
{
    int sum=0;
    int letter = getchar();
    int count[26]={0};
    while(letter!=EOF)
    {
        if(letter>='A'&&letter<='Z')
        {
            letter=letter+32;
        }
        calculate(count,letter);
        letter=getchar();
        sum++;
    }
    sum--;
    int i=0;
    int a=97;
    while(i<26)
    {
        float percent=(float)count[i]/sum;
        printf("'%c' %f %d\n",a,percent,count[i]);
        i++;
        a++;
    }
}
int calculate(int count[26],int letter)
{
    int i=letter-'a';
    count[i]++;
    return 0;
}

//'a'-'a'=0 -> count[0]
//'A'-> count