//#include<stdio.h>
#include <stdlib.h>

struct Student
{
	int age, grade;
	char name[20];
};
int comparator(const void* p, const void* q)
{
	int l = ((struct Student*)p)->grade;
	int r = ((struct Student*)q)->grade;
	return (l - r);
}