#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define M 8
#define N 10
#define FREEUP(p) do { if (p != NULL) { free(p); p=NULL;}} while(0);
 
void setZero(int mat[][10], const int m);
void displayImg(int image[][10], const int m);
 
int main()
{
        int img[M][N] = {       {0,2,3,4,5,6,7,8,9,10},
                {1,2,3,4,5,6,7,8,9,10},
                {1,2,3,4,5,6,7,8,9,10},
                {1,2,3,4,5,6,7,8,9,10},
                {1,2,3,4,5,6,7,8,9,10},
                {1,2,3,4,5,6,7,8,9,10},
                {1,2,3,4,5,6,7,8,9,10},
                {1,2,3,4,5,6,7,8,9,0}
        };
 
        displayImg(img, M);
        setZero(img, M);
        displayImg(img, M);
 
        return 0;
}
 
void setZero(int mat[][10], const int m)
{
        int i, j, countElement = 0;
        int *flagRow = (int*)calloc(m, sizeof(int));
        int flagCol[10] = {0};
 
        for(i=0; i<m; i++)
        {
                for(j=0; j<10; j++)
                {
                        if(mat[i][j] == 0)
                        {
                                flagRow[i] = 1;
                                flagCol[j] = 1;
                                countElement ++;
                        }
                }
        }
 
        int tmp = countElement;
 
        for(i=0; i<m && tmp>0; i++)
        {
                if(flagRow[i] == 1)
                {
                        for(j=0; j<10; j++)
                                mat[i][j] = 0;
                        tmp--;
                }
        }
        tmp = countElement;
        for(j=0; j<10 && tmp>0; j++)
        {
                if(flagCol[j] == 1)
                {
                        for(i=0; i<m; i++)
                                mat[i][j] = 0;
                        tmp--;
                }
        }
 
        FREEUP(flagRow); 
        return;
}
 
void displayImg(int image[][10], const int m)
{
        int i, j;
        for(i=0; i<m; i++)
        {
                for(j=0; j<10; j++)
                        printf("%3d", image[i][j]);
                printf("\n");
        }
        printf("\n");
 
        return;
}
