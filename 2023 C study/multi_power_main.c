#include<stdio.h>
#include "multi_power.h"

int main(void) {
	int x, y;

	printf("x�� ���� �Է��Ͻÿ�: ");
	scanf("%d", &x);
	printf("y�� ���� �Է��Ͻÿ�: ");
	scanf("%d", &y);
	printf("%d�� %d �������� %f\n", x, y, power(x, y));
}