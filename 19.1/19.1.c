#include<stdio.h>

void swap(int *p,int *q)
{
	int t;
	t = *p;
	*p = *q;
	*q = t;
}

main()
{
	int a = 2, b = 3, *p, *q;
	p = &a;
	q = &b;
	swap(p, q);
	printf("a = %d b = %d\n", a, b);
	printf("a = %d b = %d\n", *p, *q);
}
