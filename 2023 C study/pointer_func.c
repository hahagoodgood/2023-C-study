#include <stdio.h>

void sub(int b[], int size);

int main(void)
{
	int a[3] = { 1,2,3 };

	printf("%d %d %d\n", a[0], a[1], a[2]);
	sub(a, 3);
	printf("%d %d %d\n", a[0], a[1], a[2]);

	return 0;
}

void sub(int b[], int size)
{
	b[0] = 4;
	b[1] = 5;
	b[2] = 6;
}