#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
//To decide if str1 is a permutation of str2
int isPermutation(char *str1, char *str2); // O(n^2) time, O(n) space
int isPermutation2(char *str1, char *str2); // O(n) time, O(1) space
 
int main()
{
        char *str1 = "abcdefg";
        char *str2 = "efgabcd";
        if(isPermutation2(str1, str2))
                printf("str1 is a permutation of str2.\n");
        else
                printf("str1 is not a permutation of str2.\n");
 
        return 0;
}
 
int isPermutation(char *str1, char *str2)
{
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        if(len1 != len2)
                return 0;
 
        int *flag = malloc(sizeof(int)*len1);
        memset(flag, 0, sizeof(int)*len1);
 
        int i, j, found;
        for(i = 0; i < len1; i++)
        {
                found = 0;
                for(j = 0; j < len1; j++)
                {
                        if((str1[i] == str2[j]) && (flag[j] == 0))
                        {
                                flag[j] = 1;
                                found = 1;
                                break;
                        }
                }
                if(found != 1)
                        return 0;
        }
 
        return 1;
}
 
#define charCount 256
int isPermutation2(char *str1, char *str2)
{
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        if(len1 != len2)
                return 0;
 
        int *flag = malloc(sizeof(int)*charCount);
        memset(flag, 0, sizeof(int)*charCount);
 
        int i;
        for(i = 0; i < len1; i++)
        {
                flag[str1[i]]++;
        }
        for(i = 0; i < len1; i++)
        {
                flag[str2[i]]--;
        }
        for(i = 0; i < charCount; i++)
        {
                if(flag[i] != 0)
                        return 0;
        }
 
        return 1;
}
