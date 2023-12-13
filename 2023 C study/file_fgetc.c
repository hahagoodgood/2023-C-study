#include <stdio.h>
int main(void)
{
	FILE* fp = NULL;
	int c;

	fp = fopen("sample.txt", "r");
	if (fp == NULL)
		printf("파일 읽기 실패\n");
	else
		printf("파일 일기 성공\n");
	while ((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}
	fclose(fp);
	putchar("\n");
	return 0;
}