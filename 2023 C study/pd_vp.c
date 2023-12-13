#include <stdio.h>

void memzero(void* ptr, size_t len)
{
	for (; len > 0; len--)
		*(char*)ptr = 0;
}

int main(void)
{
	char a[10];
	printf("sizeof(a)=%u\n", sizeof(a));
	memzero(a, sizeof(a));

	int b[10];
	printf("sizeof(b)=%u\n", sizeof(b));
	memzero(b, sizeof(b));

	double c[10];
	printf("sizeof(c)=%u\n", sizeof(c));
	memzero(c, sizeof(c));

	return 0;
}