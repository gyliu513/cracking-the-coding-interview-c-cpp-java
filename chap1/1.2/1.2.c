#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
static int
reverseStr(char str[]) {
    int len = strlen(str);
    char tmp = '\0';
    int i;
    int range = len - 1;
    for (i=0; range>0; i++) {
       tmp = str[i];
       str[i] = str[len-1-i];
       str[len-1-i] = tmp;
       range = range -2;
    }
    return 0;
}
 
int main()
{
    char str[] = "1234abcd";
    printf("original str %s\n", str);
    reverseStr(str);
    printf("reversed str %s\n", str);
}
