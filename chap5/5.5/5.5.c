#include <stdio.h>

int bit_count(int a, int b)
{
	int count = 0;
	int c = 0;
	for ( c = a ^ b; c != 0; c >>= 1 )
		count += c & 1;
	return c;
}
