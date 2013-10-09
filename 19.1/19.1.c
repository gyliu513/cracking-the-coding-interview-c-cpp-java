#include<stdio.h>
 
void swap(int *p,int *q)
{
        int t;
        t = *p;
        *p = *q;
        *q = t;
}
 
int swap_opt(int *a, int *b) {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
        return 0;
}
 
main()
{
        int a = 2, b = 3, *p, *q;
        printf("a = %d b = %d\n", a, b);
        printf("-------------------\n");
        p = &a;
        q = &b;
        swap(p, q);
        printf("a = %d b = %d\n", a, b);
        printf("-------------------\n");
        swap_opt(&a, &b);
        printf("a = %d b = %d\n", a, b);
}
