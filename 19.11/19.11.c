#include <stdio.h>
#include <stdlib.h>

int sort(int a[], int n) {
	int i, j;
	for (i=0; i<n-1; i++) {
		for (j=i+1; j<n; j++)
			if (a[i]>a[j]) {
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
	}
	for (i=0; i<n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int getPair(int a[], int n, int sum) {
	int low = 0;
	int high = n-1;
	while(low < high) {
		if (a[low] + a[high] > sum) {
			--high;
		} else if (a[low] + a[high] < sum) {
			++low;
		} else {
			printf("%d <===> %d\n", a[low], a[high]);
			++low;
			--high;
		}
	}
}

int main()
{
	int a[] = {6, 5, 4, 3, 2, 1};
	int n = sizeof(a)/sizeof(a[0]);
	int i, j;
	int pair;
	int sum = 7;
	for (i=0; i<n; i++) {
		pair = sum - a[i];
		for (j=i+1; j<n; j++) {
			if (a[j] == pair) {
				printf("pair1 %d<==>%d\n", a[i], pair);
				break;
			}
		}
	}
	sort(a, 6);
	getPair(a, 6, 7);
}
