#include <string.h>
#include <stdio.h>;

int main(void)
{
	char s[] = "A joy that's shared is a joy is a joy made double";
	char sub[] = "that";
	char* p;
	int loc;

	p = strstr(s, sub);

	loc = (int)(p - s);
	printf("p=%d\ns=%d\n",(int)p, (int)s);
	if (loc != NULL)
		printf("%s에서 첫번째 %s가 %d에서 발견되었음\n", s, sub, loc);
	else
		printf("%s가 발견되지 않았음\n", sub);
	return 0;
}