#include <stdio.h>

struct student {
	int number;
	char name[20];
	double grade;
};

struct student list[100];

struct student* get_max_stu(const struct student* stu, int size);

int main(void)
{
	struct student* super_stu;
	int i, size, stu_num;

	printf("학생의 총인원을 입력해 주세요: ");
	scanf("%d", &size);

	if (size > 0)
	{
		printf("차례대로 입력해주십시오\n");
		for (i = 0; i < size; i++)
		{
			printf("%d번 학생\n", i+1);
			printf("학번: ");
			scanf("%d", &list[i].number);
			printf("이름: ");
			scanf("%s", &list[i].name);
			printf("학점: ");
			scanf("%lf", &list[i].grade);
		}
	}

	super_stu = get_max_stu(&list, size);


	/*super_stu = list[0];
	for (i = 1; i < size; i++) {
		if (list[i].grade > super_stu.grade)
			super_stu = list[i];
	}*/
	printf("평점이 가장 높은 학샐은 (이름:%s, 학번:%d, 평점:%f) 입니다.\n", super_stu->name, super_stu->number, super_stu->grade);

	return 0;
}

struct student* get_max_stu(struct student* list, int size)
{
	struct student* max;
	int i;

	max = list;
	for (i = 0; i < size; i++)
	{
		if ((list + i)->grade > max->grade)
			max = list + i;
	}

	return max;
}