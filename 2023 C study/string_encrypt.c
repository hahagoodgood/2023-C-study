#include<stdio.h>
void encrypt(char cipher[], int shift, int option);
//void dencrypt(char cipher[], int shift);

int main(void)
{
	char cipher[50];
	int shift = 3;
	int option=0;

	/*printf("%d, %d", 'A', 'z');
	return 0;*/
	do {
		printf("1.��ȣȭ \n2.��ȣȭ\n1�̳� 2�� ������ �ּ���: ");
		scanf("%d", &option);
		printf("%d\n", option);

		if ((option != 1) && (option !=2))
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
	} while (option != 1 && option != 2);

	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets_s(cipher, 50);
	gets_s(cipher, 50);
	encrypt(cipher, shift,option);
	//dencrypt(cipher, shift);
	return 0;
}

void encrypt(char cipher[], int shift, int option)
{
	int i = 0;
	if (option == 2)
		shift *= (-1);
	while (cipher[i])
	{
		if (cipher[i] >= 'A' && cipher[i] <= 'z')
		{
			cipher[i] += shift;
			if (cipher[i] > 'z')
				cipher[i] -= 58;
			else if (cipher[i] < 'A')
				cipher[i] += 58;
		}
		i++;
	}
	printf("��ȣȭ�� ���ڿ�:%s \n", cipher);
}