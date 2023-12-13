#include <string.h>
#include <stdio.h>

int main(void)
{
	char s1[80];
	char s2[80];
	int result;

	printf("Enter the First word: ");
	scanf("%s", s1);
	printf("Enter  the Second word: ");
	scanf("%s", s2);

	result = strcmp(s1, s2);
	if (result < 0)
		printf("%s is located in front of %s", s1, s2);
	else if (result == 0)
		printf("%s is same %s.", s1, s2);
	else
		printf("%s is located back of %s", s1, s2);
	return 0;
}