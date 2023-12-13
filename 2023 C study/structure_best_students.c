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

	printf("�л��� ���ο��� �Է��� �ּ���: ");
	scanf("%d", &size);

	if (size > 0)
	{
		printf("���ʴ�� �Է����ֽʽÿ�\n");
		for (i = 0; i < size; i++)
		{
			printf("%d�� �л�\n", i+1);
			printf("�й�: ");
			scanf("%d", &list[i].number);
			printf("�̸�: ");
			scanf("%s", &list[i].name);
			printf("����: ");
			scanf("%lf", &list[i].grade);
		}
	}

	super_stu = get_max_stu(&list, size);


	/*super_stu = list[0];
	for (i = 1; i < size; i++) {
		if (list[i].grade > super_stu.grade)
			super_stu = list[i];
	}*/
	printf("������ ���� ���� �л��� (�̸�:%s, �й�:%d, ����:%f) �Դϴ�.\n", super_stu->name, super_stu->number, super_stu->grade);

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