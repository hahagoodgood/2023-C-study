#include<stdlib.h>
#include<stdio.h>

int main(void)
{
	char s1[] = "100";
	char s2[] = "12.93";
	char buffer[100];

	int i;
	double d;
	double result;

	i = atoi(s1);
	d = atof(s2);

	result = i + d;

	sprintf(buffer, "%f", result);
	printf("연산 결과는 %s 입니다.\n", buffer);

	return 0;
}