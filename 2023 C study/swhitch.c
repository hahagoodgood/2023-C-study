#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
	srand(time(NULL));
	int random = rand() % 6 + 1;
	printf("%d\n", random);
	switch (random) {
	case 1:	
		printf("1");
	case 2:
		printf("2");
	case 3:
		printf("3");
	case 4:
		printf("4");
	case 5:
		printf("5");
	case 6:
		printf("6");
	}
	return 0;
}