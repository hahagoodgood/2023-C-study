#include <string.h>
#include <stdio.h>

char s[] = "Man is immortal, because he has a soul";
char seps[] = " ,\t\n";
char* token;

int main(void)
{
	token = strtok(s, seps);

	while (token != NULL)
	{
		printf("��ū: %s\n", token);
		printf("���ڿ�: %s\n", s);
		token = strtok(NULL, seps);
	}
	return 0;
}