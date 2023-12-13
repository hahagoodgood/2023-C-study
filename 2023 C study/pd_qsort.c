#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int values [5] ;

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main(void)
{
	int n;
	srand(time(NULL));
	for (n = 0; n < 5; n++)
		values[n] = rand();

	qsort(values, 5, sizeof(int), compare);

	printf("������ �� �迭: ");
	for (n = 0; n < 5; n++)
		printf("%d ", values[n]);
	printf("\n");

	return 0;
}