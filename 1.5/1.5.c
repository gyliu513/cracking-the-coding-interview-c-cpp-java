#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define FREEUP(p) do {if (p) {free(p); p = NULL}} while(0)
 
        static char*
replaceStr(char *str)
{
        int i;
        int len = strlen(str);
        if (len == 0) {
                return NULL;
        }
 
        int spaceCounter = 0;
        for (i=0; i<len; i++) {
                if (str[i] == ' ') {
                        spaceCounter++;
                }
        }
        if (spaceCounter == 0) {
                return strdup(str);
        }
 
        char *replacedStr = (char*)malloc(sizeof(char)*len + spaceCounter*2);
        if (replacedStr  == NULL) {
                printf("alloc error");
        }
        int j = 0;
        for (i=0; i<len; i++) {
                if (str[i] != ' ') {
                        replacedStr [j] = str[i];
                        j++;
                } else {
                        replacedStr[j++] = '%';
                        replacedStr[j++] = '2';
                        replacedStr[j++] = '0';
                }
        }
        return replacedStr;
}
 
int main()
{
        char *str = "Guangya Liu";
        char *replacedStr = replaceStr(str);
        if (replacedStr == NULL) {
                printf("No string<<");
                return 0;
        }
        printf("After replace, str is %s\n", replacedStr );
        return 0;
}
