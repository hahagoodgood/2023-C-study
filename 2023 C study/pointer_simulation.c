#include <stdio.h>
#include <stdlib.h>

void getSensorData(double* p)
{
	*p = (double)(rand()%100);
		* (p + 1) = (double)(rand() % 100);
		*(p + 2) = (double)(rand() % 100);
	
	return 0;
}

int main(void)
{
	double sensorData[3];
	getSensorData(sensorData);
	printf("���� ������ ��ֹ����� �Ÿ�: %lf\n", sensorData[0]);
	printf("������ ������ ��ֹ����� �Ÿ�: %lf\n", sensorData[1]);
	printf("������ ������ ��ֹ����� �Ÿ�: %lf\n", sensorData[2]);

	return 0;
}