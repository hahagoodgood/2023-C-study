#include <stdio.h>

struct account {
	const int account_num;
	char name[20];
	int pawd;
	int money;
};

struct account list[] = {
	{11111111, "한동숙", 1010, 100000},
	{22222222, "김미녀", 2020, 200000},
	{33333333, "박학규", 3030, -500},
	{44444444, "백정주", 4040, -599999},
	{55555555, "잔나나", 5050, 3000000}
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
		printf("1.입금\n2.출금\n종료:0\n");
		printf("사용하실 메뉴를 입력해주세요: ");
		scanf("%d", &op);
		if (op == 0)
			break;
		else if (op > 0 && op < 3)
		{
			printf("계좌번호를 입력해주세요: ");
			scanf("%d", &act_num);
			cli = find_account(act_num);
			if (cli == NULL)
			{
				printf("입력하신 계좌번호가 존재하지 않습니다.\n\n");
				continue;
			}
			deal(cli, op);
			continue;
		}
		else
		{
			printf("잘못 입력하셨습니다.\n\n");
			continue;
		}
	}
	printf("\n프로그램을 종료해겠습니다.\n이용해 주셔서 감사합니다.\n");
	return 0;
}

void deal(struct account* account, int op)
{
	int add;
	int ps;
	int i;

	if (op == 1)//입금
	{
		printf("입금하실 금액을 넣어주세요: ");
		scanf("%d", &add);
		account->money += add;

		printf("총 %d원이 입금되었습니다.\n 잔액:%d\n\n", add, account->money);
		return 0;
	}
	else if (op == 2)//출금
	{
		for (i = 0; i < 5; i++)
		{
			printf("비밀번호 4자리를 입력해주세요: ");
			scanf("%d", &ps);
			if (ps == account->pawd)
			{
				printf("출금하실 금액을 입력해주십시오: ");
				scanf("%d", &add);
				account->money -= add;

				printf("총 %d원이 출금되었습니다.\n 잔액:%d\n\n", add, account->money);
				return 0;
			}
			else
				printf("비밀번호가 다릅니다.\n 남은횟수 %d\n", 5-i);
		}
		printf("비밀번호 입력횟수 초과로 초기화면으로 돌아갑니다.\n\n");
		return 0;
	}
	else
		printf("Error\n");
}