#include <stdio.h>

struct student
{
	int number;
	char name[20];
	double grade;
};

int main(void)
{
	struct student s = { 20190001, "ȫ�浿", 4.3 };
	struct student* p;

	p = &s;

	printf("number = %d, name = %s, grade = %f\n", s.number, s.name, s.grade);
	printf("number = %d, name = %s, grade = %f\n", (*p).number, (*p).name, (*p).grade);
	printf("number = %d, name = %s, grade = %f\n", p->number, p->name, p->grade);

	return 0;
}