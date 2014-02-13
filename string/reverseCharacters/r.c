#include <stdio.h>
#include <stdlib.h>
void Reverse(char* pBegin,char* pEnd){
	char tmp;
	if(pBegin==NULL || pEnd==NULL)
		return;
	while(pBegin <pEnd){
		tmp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = tmp;
		pBegin++;
		pEnd--;
	}
}

char* ReverseSentence(char *pData){
	if(pData==NULL)
		return NULL;
	char* pBegin = pData;
	char* pEnd = pData;
	while(*pEnd!='\0'){
		pEnd++;
	}
	pEnd--;
	Reverse(pBegin,pEnd);
        printf("%s\n", pBegin);

	pBegin = pEnd = pData;
	while(*pBegin != '\0'){
		if(*pBegin == ' '){
			pBegin++;
			pEnd++;
			continue;
		}
		else if(*pEnd==' '||*pEnd=='\0'){
			Reverse(pBegin,--pEnd);
			pBegin=++pEnd;
                        printf("%s\n", pBegin);
		}
		else{
			pEnd++;
		}
	}
	return pData;
}

void main(){
	char* pData;
	pData=(char *)malloc(sizeof(char));
	gets(pData);
	pData = ReverseSentence(pData);
	printf("%s",pData);
}
