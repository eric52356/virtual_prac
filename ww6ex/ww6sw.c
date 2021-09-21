//Its a Case of Swapping
#include <stdio.h>
int swap(int letter);
int main()
{
    int letter=getchar();
    while(letter!=EOF)
    {
        //printf("you entered the character: '%c' which has ASCII code %d\n", letter, letter);
        putchar(swap(letter));
        letter=getchar();
    }
}
int swap(int letter)
{
    if(letter>='a'&&letter<='z')
    {
        int new = letter - 'a';
        return new + 'A';
    }
    if(letter>='A'&&letter<='Z')
    {
        int new = letter - 'A';
        return new + 'a';
    }
    else
        return letter;
}