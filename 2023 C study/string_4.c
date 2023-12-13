#include<stdio.h>

int main(void)
{
	char str[30] = "C languge is easy!";
	int i = 0;

	while (str[i] != 0)
		i++;
	printf("문자열\"%s\"의 길이는 %d입니다.", str, i);
	
	return 0;
}