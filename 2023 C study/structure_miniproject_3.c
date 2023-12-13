#include <stdio.h>

struct account {
	const int account_num;
	char name[20];
	int pawd;
	int money;
};

struct account list[] = {
	{11111111, "�ѵ���", 1010, 100000},
	{22222222, "��̳�", 2020, 200000},
	{33333333, "���б�", 3030, -500},
	{44444444, "������", 4040, -599999},
	{55555555, "�ܳ���", 5050, 3000000}
};

struct account* find_account(int num)
{
	int low, mid, high;
	//struct account* low, * mid, * high;
	int size = 0;
	high = sizeof(list) / sizeof(list[0])-1;
	low = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (num == list[mid].account_num)
			return &list[mid];
		else if (num > list[mid].account_num)
			low = mid+1;
		else
			high = mid-1;
	}
	return NULL;
}

void deal(struct account* account, int op);

int main(void) {
	int op, act_num, i;
	struct account* cli = NULL;
	while (1) {
		printf("\n=====================================\n");
		printf("1.�Ա�\n2.���\n����:0\n");
		printf("����Ͻ� �޴��� �Է����ּ���: ");
		scanf("%d", &op);
		if (op == 0)
			break;
		else if (op > 0 && op < 3)
		{
			printf("���¹�ȣ�� �Է����ּ���: ");
			scanf("%d", &act_num);
			cli = find_account(act_num);
			if (cli == NULL)
			{
				printf("�Է��Ͻ� ���¹�ȣ�� �������� �ʽ��ϴ�.\n\n");
				continue;
			}
			deal(cli, op);
			continue;
		}
		else
		{
			printf("�߸� �Է��ϼ̽��ϴ�.\n\n");
			continue;
		}
	}
	printf("\n���α׷��� �����ذڽ��ϴ�.\n�̿��� �ּż� �����մϴ�.\n");
	return 0;
}

void deal(struct account* account, int op)
{
	int add;
	int ps;
	int i;

	if (op == 1)//�Ա�
	{
		printf("�Ա��Ͻ� �ݾ��� �־��ּ���: ");
		scanf("%d", &add);
		account->money += add;

		printf("�� %d���� �ԱݵǾ����ϴ�.\n �ܾ�:%d\n\n", add, account->money);
		return 0;
	}
	else if (op == 2)//���
	{
		for (i = 0; i < 5; i++)
		{
			printf("��й�ȣ 4�ڸ��� �Է����ּ���: ");
			scanf("%d", &ps);
			if (ps == account->pawd)
			{
				printf("����Ͻ� �ݾ��� �Է����ֽʽÿ�: ");
				scanf("%d", &add);
				account->money -= add;

				printf("�� %d���� ��ݵǾ����ϴ�.\n �ܾ�:%d\n\n", add, account->money);
				return 0;
			}
			else
				printf("��й�ȣ�� �ٸ��ϴ�.\n ����Ƚ�� %d\n", 5-i);
		}
		printf("��й�ȣ �Է�Ƚ�� �ʰ��� �ʱ�ȭ������ ���ư��ϴ�.\n\n");
		return 0;
	}
	else
		printf("Error\n");
}