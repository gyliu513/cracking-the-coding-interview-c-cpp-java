#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
    char *str = "abcda";
    int len = strlen(str);
    int *flag = (int*)calloc(len, sizeof(int));
 
    int i;
    for (i=0; i<len; i++) {
        flag[str[i]]++;
        if (flag[str[i]] > 1) {
            printf("fuck %c\n", str[i]);
        }
    }
}
