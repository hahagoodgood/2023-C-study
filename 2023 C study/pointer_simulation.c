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
	printf("왼쪽 센서와 장애물과의 거리: %lf\n", sensorData[0]);
	printf("오른쪽 센서와 장애물과의 거리: %lf\n", sensorData[1]);
	printf("오른쪽 센서와 장애물과의 거리: %lf\n", sensorData[2]);

	return 0;
}