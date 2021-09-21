//Encrypting Text with a Caesar Cipher
#include <stdio.h>
#include <stdlib.h>
int encrypt(int letter,int shift);
int main(int argc, char *argv[]) {
    int shift=atoi(argv[1]);
    shift=shift%26;
    int letter=getchar();
    while(letter!=EOF)
    {
        putchar(encrypt(letter,shift));
        letter=getchar();
    }
    return 0;
}
int encrypt(int letter,int shift)
{
    if(letter>='A'&&letter<='Z')
    {
        if(letter+shift<'A')
            return letter+shift+26;
        if(letter+shift>'Z')
            return letter+shift-26;
        else 
            return letter+shift;
    }
    if(letter>='a'&&letter<='z')
    {
        if(letter+shift<'a')
            return letter+shift+26;
        if(letter+shift>'z')
            return letter+shift-26;
        else
            return letter+shift;
    }
    else
        return letter;
}