#include <stdio.h>
 
#define N 4 
char m[3][4]= {
    {'a', 'b', 'c', 'd'},
    {'e', 'f', 'g', 'h'},
    {'i', 'j', 'k', 'l'},
};
 
int main(){
    int i, j;
    for(i=0; i<3; ++i){
        for(j=0; j<4; ++j)
            printf("%c ", m[i][j]);
        printf("\n");
    }
    printf("==========reverse clock 90=========\n");
    for(i=0; i<=3; ++i){
        for(j=0; j<N; ++j)
            printf("%c ", m[j][N-1-i]);
        printf("\n");
    }
    printf("===========clock 90========\n");
    for(i=3; i>=0; --i){
        for(j=N-1; j>=0; --j)
            printf("%c ", m[j][N-1-i]);
        printf("\n");
    }
    return 0;
}
