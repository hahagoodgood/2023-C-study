#include<stdio.h>
int main(void)
{
	int i;
	char fruits[3][0 + 3 + 10 + 7];

	for (i = 0; i < 3; i++) {
		printf("���� �̸��� �Է��Ͻÿ�:");
		scanf("%s", fruits[i]);
	}

	for (i = 0; i < 3; i++) {
		printf("%d ��° ����: %s\n",i, fruits[i]);
		
	}
	return 0;
}