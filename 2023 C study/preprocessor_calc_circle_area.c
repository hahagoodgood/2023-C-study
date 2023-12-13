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
	printf("area(%f)가 호출되었음 \n", radius);
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
		printf("죄송합니다! \n프로그램ver: %d에서는 원의 넓이를 구할 수 없습니다.\n최신버전으로 업그래이드 해주십시오!\n날짜:%s, 줄:%d\n", VERSION, __DATE__, __LINE__);
		return 1;
	}
	printf("원의 반지름을 입력하시오 : ");
#endif

	scanf("%lf", &radius);
#ifdef USA
	printf("area of the circle is %f \n", area(radius));
#else
	printf("원의 면적은 %f 입니다.\n", area(radius));
#endif

	return 0;
}
