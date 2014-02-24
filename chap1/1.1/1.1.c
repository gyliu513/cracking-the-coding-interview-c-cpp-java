#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 256 
int main()
{
    char *str = "abcda";
    int len = strlen(str);
    int *flag = (int*)calloc(MAXLEN, sizeof(int));
 
    int i;
    for (i=0; i<len; i++) {
        flag[str[i]]++;
        if (flag[str[i]] > 1) {
            printf("fuck %c\n", str[i]);
        }
    }
}
