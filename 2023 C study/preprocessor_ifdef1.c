#include <stdio.h>
//#define DELUXE

int main(void) {
#ifdef DELUXE
	printf("디럭스 버전 입니다.\n");
#endif
	return 0;
}