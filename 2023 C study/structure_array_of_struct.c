#include <stdio.h>
#define SIZE 3

struct student
{
	int number;
	char name[20];
	double grade;
};

int main(void)
{
	struct student list[SIZE];
	int i;
	char a[2];

	for (i = 0; i < SIZE; i++)
	{
		printf("Please enter your school number: ");
		scanf("%d", &list[i].number);
		printf("Please enter your name: ");
		getchar();
		gets_s(&list[i].name, 20/*sizeof(list[i].name)*/);
		//gets_s(a,2);
		printf("Please enter your grade: ");
		scanf("%lf", &list[i].grade);
	}

	for (i = 0; i < SIZE; i++)
		printf("name: %s, grade: %f\n", list[i].name, list[i].grade);
	return 0;
}