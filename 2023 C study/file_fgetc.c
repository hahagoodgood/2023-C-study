#include <stdio.h>
int main(void)
{
	FILE* fp = NULL;
	int c;

	fp = fopen("sample.txt", "r");
	if (fp == NULL)
		printf("���� �б� ����\n");
	else
		printf("���� �ϱ� ����\n");
	while ((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}
	fclose(fp);
	putchar("\n");
	return 0;
}