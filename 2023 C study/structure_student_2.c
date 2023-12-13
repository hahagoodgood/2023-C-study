#include <stdio.h>
#include <string.h>

struct student //구조체의 정의
{
	int number;
	char name[100];
	double grade;
};

int main(void)
{
	int i;
	//char name[10];
	struct student s;

	printf("Please enter your shool number: ");
	scanf("%d", &s.number);
	getchar();

	printf("Please enter your name: ");
	gets_s(s.name, sizeof(s.name));
	//scanf("%s", &s.name);
	//getchar();

	printf("Please enster your grade: ");
	scanf("%lf", &s.grade);

	printf("학번: %d\n", s.number);
	printf("이름: %s\n", s.name);
	printf("학점: %f\n", s.grade);

	return 0;
}