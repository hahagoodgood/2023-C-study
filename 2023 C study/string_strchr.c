#include <string.h>
#include <stdio.h>

int main(void)
{
	char* s = "language";
	char c = 'g';
	char* p;
	int loc;

	p = strchr(s, c);
	loc = (int)p;
	if (p != NULL)
		printf("%s���� ù��° %c�� %d���� �߰ߵǾ���\n", s, c, loc);
	else
		printf("%c�� �߰ߵ��� �ʾ���\n", c);
	printf("s = %d\n",s);
	printf("s = %c\n", p);
	printf("&s = %d\n", &s);
	printf("&s = %s\n", &s);
	printf("*s = %d\n", *s);
	printf("*s = %s\n", *s);
	return 0;
}