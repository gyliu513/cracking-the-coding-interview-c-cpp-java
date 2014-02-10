
#include <stdio.h>
#include <stdlib.h>

int search(int d[][5], int m, int x){
	int r = 0, c = 4;
	while(r<m && c>=0){
		if(d[r][c] == x) return (r * 5 + c);
		else if(d[r][c] < x) ++r;
		else --c;
	}
	return -1;
}
int main(){
	int d[5][5];
	int m=5, n=5;
	int i, j;
	for(i=0; i<m; ++i)
		for(j=0; j<n; ++j)
			d[i][j]= i*n+j+1;

	for(i=0; i<m; ++i){
		for(j=0; j<n; ++j)
			printf(" %d", d[i][j]);
		printf("\n");
	}
        printf("\n");
	int k = search(d, m, 13);
	if(k == -1) printf("Not found\n");
	else printf("row %d col %d\n", k/n, k%n);
	return 0;
}
