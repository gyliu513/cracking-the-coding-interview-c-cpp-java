#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
char *compressStr(char *str); // O(n) time, O(1) space
 
int main()
{
	char *toBeCompressed = "aaaaaaaaaaaaabccccccccccccccccccccccccc";
	char *compressed = compressStr(toBeCompressed);
	printf("Before compression:\t%s\n",toBeCompressed);
	printf("After compression:\t%s\n",compressed);
	free(compressed);
	compressed = NULL;
	return 0;
}
 
char *compressStr(char *str)
{
	char tmpChar;
	int i, j, len=strlen(str);
	int compressedLen=0, countChar;
	int size;
 
	//get the length of the compressed string
	for(i=0; i<len; i++)
	{
		compressedLen ++;
		countChar = 1;
		while((i<len-1)&&(str[i]==str[i+1]))
		{
			i++;
			countChar++;
		}
		for(size=1; countChar/=10;size++)
			;
		compressedLen += size;
	}
 
	if(compressedLen >= len)
		return str;
	else
	{
		char *result = malloc(sizeof(char)*compressedLen);
 
		for(i=0, j=0; i<len; i++)
		{
			countChar = 0;
			countChar ++;
			result[j++] = str[i];
			while((i<len-1)&&(str[i]==str[i+1]))
			{
				i++;
				countChar ++;
			}
 
			int tmp = countChar;
			for(size=1; tmp/=10; size++)
				;
			char buf[size];
			//cast the integer to string
			sprintf(buf, "%d", countChar);
			int k, bufLen=strlen(buf);
			for(k=0; k<bufLen; k++)
				result[j++] = buf[k];
			result[j] = '\0';
		}
 
		return result;
	}
}
