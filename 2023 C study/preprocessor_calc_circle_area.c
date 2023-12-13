#include <stdio.h>

//#define USA
#define DEBUG
//#define VERSION 101
#define VERSION 99

#ifndef PI
#define PI 3.141592
#endif

#ifndef SQUARE
#define SQUARE(r) ((r)*(r))
#endif

double area(double radius) {
	double result = 0.0;
#ifdef DEBUG
#ifdef USA
	printf("area(%f) is called \n", radius);
#else
	printf("area(%f)�� ȣ��Ǿ��� \n", radius);
#endif
#endif
	result = PI * SQUARE(radius);
	return result;
}

main(void) {
	double radius;

#ifdef USA
	if (VERSION <= 100) {
		printf("Sorry! \nA program in version %d cannot calculate the area of the circle.\nPlease upgrade to the lastest version!\nDate:%s, Line:%d\n", VERSION, __DATE__, __LINE__);
		return 1;
	}
	printf("Please enter radius of a circle(inch) : ");
#else
	if (VERSION <= 100) {
		printf("�˼��մϴ�! \n���α׷�ver: %d������ ���� ���̸� ���� �� �����ϴ�.\n�ֽŹ������� ���׷��̵� ���ֽʽÿ�!\n��¥:%s, ��:%d\n", VERSION, __DATE__, __LINE__);
		return 1;
	}
	printf("���� �������� �Է��Ͻÿ� : ");
#endif

	scanf("%lf", &radius);
#ifdef USA
	printf("area of the circle is %f \n", area(radius));
#else
	printf("���� ������ %f �Դϴ�.\n", area(radius));
#endif

	return 0;
}
