#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void removeduplicate(char *str)
{
        int checker = 0;
        int cnt = 0;
        int i;
        for(i = 0; i < strlen(str); i++)
        {
                int val = *(str + i) - (int)'a';
                if ((checker & (1 << val)) > 0) continue;
                else {
                        *(str + cnt) = *(str + i);
                        cnt++;
                }
                checker |= (1 << val);
        }
        *(str+cnt) = '\0';
}
 
static void removeduplicate2(char *str) {
        if (str == NULL) return;
        int len = strlen(str);
        if (len < 2) return;
 
        int tail = 1;
        int i;
        for (i = 1; i < len; ++i) {
                int j;
                for (j = 0; j < tail; ++j) {
                        if (str[i] == str[j]) break;
                }
                if (j == tail) {
                        str[tail] = str[i];
                        ++tail;
                }
                printf("%s\n", str);
        }
        str[tail] = 0;
}
 
int main(int argc, char* argv[])
{
        char *str = "abcdabcd";
        char *str2 = strdup(str);
        //char str[] = {'a', 'b', 'c', 'a'};
        removeduplicate2(str2);
        printf("%s\n", str2);
}
