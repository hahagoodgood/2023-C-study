#include <stdio.h>

struct date
{
	int month;
	int day;
	int year;
};

struct student
{
	int number;
	char name[20];
	double grade;
	struct date* bob;
};

int main(void)
{
	struct date d = { 3,20,1990 };
	struct student s = { 20190001, "kim", 4.3 };
	
	s.bob = &d;

	printf("number: %d\n", s.number);
	printf("name: %s\n", s.name);
	printf("grade: %f\n", s.grade);
	printf("birthday: %d, %d, %d\n", s.bob->day, s.bob->month, s.bob->year);

	return 0;
}