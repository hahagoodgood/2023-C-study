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
		printf("%s에서 첫번째 %c가 %d에서 발견되었음\n", s, c, loc);
	else
		printf("%c가 발견되지 않았음\n", c);
	printf("s = %d\n",s);
	printf("s = %c\n", p);
	printf("&s = %d\n", &s);
	printf("&s = %s\n", &s);
	printf("*s = %d\n", *s);
	printf("*s = %s\n", *s);
	return 0;
}