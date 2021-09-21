//Devowelling Text
#include <stdio.h>
int IS_VOWEL(int letter);
int main()
{
    int letter=getchar();
    while(letter!=EOF)
    {
        putchar(IS_VOWEL(letter));
        //printf("\n");
        //printf("you entered the character: '%c' which has ASCII code %d\n", letter, letter);
        letter=getchar();
    }
}
int IS_VOWEL(int letter)
{
    if(letter=='a'||letter=='e'||letter=='i'||letter=='o'||letter=='u')
        return 0;
    else
        return letter;
}
/*./ww6de -> type letter 
  ctrl + d-> stop  */
/*./ww6de <input.txt -> read input text*/  