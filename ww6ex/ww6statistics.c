//input_statistics
#include <stdio.h>
int main()
{
    int letter=getchar();
    int blank=0;
    int word=0;
    int sum=0;
    int a;
    int shortest=100;
    int longest=0;
    while(letter!=EOF)
    {
        if(letter==' '||letter=='\n')
        {
            if(word!=0)
            {
                sum++;
                if(word>longest)
                {
                    longest=word;
                }
                else
                    a=word;
                if(a<shortest)
                {
                    shortest=a;
                }//shortest
            }
            blank++;
            word=0;
        }
        else
            word++;
        letter=getchar();
    }
    printf("Input contains %d blanks, tabs and new lines\n",blank);
    printf("Number of words: %d\n",sum);
    printf("Length of shortest word: %d\n",shortest);
    printf("Length of longest word: %d\n",longest);
    return 0;    
}
//Number of words (sum)
//longest, shortest word (longest,shortest)