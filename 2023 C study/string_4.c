#include<stdio.h>

int main(void)
{
	char str[30] = "C languge is easy!";
	int i = 0;

	while (str[i] != 0)
		i++;
	printf("���ڿ�\"%s\"�� ���̴� %d�Դϴ�.", str, i);
	
	return 0;
}