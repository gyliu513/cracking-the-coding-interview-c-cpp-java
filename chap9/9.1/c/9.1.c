#include <stdio.h>
#include <stdlib.h>

static int
mergeArray(int a[], int b[], int aLen, int bLen) {
	int k = aLen + bLen -1;
	int i = aLen - 1;
	int j = bLen - 1;
	while (i >= 0 && j >= 0) {
		if (a[i] > b[j]) {
			a[k--] = a[i--];
		} else {
			a[k--] = b[j--];
		}
	}
	while (j >= 0) {
		a[k--] = b[j--];
	}
	return 0;
}

int main()
{
	int i;
	int a[15] = {
		1, 3, 7, 8, 9
	};
	int b[] = {
		2, 4, 5, 6, 10
	};
	int n = 5, m = 5;
	mergeArray(a, b, n, m);
	for (i=0; i<n+m; i++) {
		printf("a[%d]=%d ", i, a[i]);
	}
	printf("\n");
}
