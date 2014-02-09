#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSubstring(char *s1, char *s2);
int isRotation(char *s1, char *s2);

int main()
{
	char *s1 = "string1";
	char *s2 = "1string";
	// len same or not???

	int result = isRotation(s1, s2);
	if(result)
		printf("YES\n");
	else
		printf("NO\n");
}

int isRotation(char *s1, char *s2)
{
	int len = strlen(s1);
	if(len != strlen(s2))
		return 0;

	char *s = (char*)malloc(sizeof(char)*2*len);
	strcpy(s, s1);
	strcat(s, s1);
	return isSubstring(s, s2);
}

int isSubstring(char *s1, char *s2)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if(len2 > len1 || len2 == 0)
		return 0;

	int i, j;
	for(i = 0; i < len1 - len2; i++)
	{
		if(s1[i] == s2[0])
		{
			int sub = 1;
			for(j = 1; j < len2; j++)
			{
				if(s1[i+j] != s2[j])
				{
					sub = 0;
					break;
				}
			}
			if(sub) return 1;
		}
	}
	return 0;
}
