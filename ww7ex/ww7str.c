#include <stdio.h>
#include <string.h>
int main ()
{
   ///strlen use
   char str[]= "This is gitbook.net";
   int len;
   len = strlen(str);
   printf("Length of |%s| is |%d|\n", str, len);
   

    ///strcpy use
   char a[20],c[]="Today is a goodday";
   strcpy(a,c);
   printf(" c=%s\n",c);
   printf(" a=%s\n",a);
   return(0);
}