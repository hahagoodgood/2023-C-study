#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int check(char s[][100], char a[], char ch);
int main(void)
{

	char solution[4][100] = { "meet at midnight" ,"sex on the beach", "play now", "just do it!" };
	char answer[100] = "";
	char select;
	int i = 0, life = 6;
	static int num;

	srand(time(NULL));
	num = rand()%4;

	while (solution[num][i])
	{
		if (isalpha((int)solution[num][i]))
			answer[i] = '_';
		else
			answer[i] = solution[num][i];
		i++;
	}

	while (life > 0)
	{
		printf("���� ���:%d\n", life);
		printf("���ڿ��� ������ �����ϴ�: %s\n", answer);
		printf("���ڸ� �����Ͻÿ�: ");
		select = getchar();
		i = check( solution, answer, select,num);
		if (i == 0) {
			printf("�����Ͻ� ���ڰ� �信 ���� �ʽ��ϴ�.\n");
			life--;
		}
		else 
		{
			if (strcmp(solution[num], answer) == 0)
			{
				printf("win!\n%s\n", answer);
				return 0;
			}
		}
		getchar();
	}
	if (life <= 0)
	{
		printf("lose!\nsolution = %s\n answer = %s\n", solution, answer);
	}
	return 0;
}

int check(char s[][100], char a[], char ch, int num)
{
	int i=0;

	if (strchr(s[num], ch)) {
		while (s[num][i]) {
			if (s[num][i] == ch)
				a[i] = ch;
			++i;
		}
		return 1;
	}
	//�� ã������
	else
		return 0;
}