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
		printf("1.암호화 \n2.복호화\n1이나 2중 선택해 주세요: ");
		scanf("%d", &option);
		printf("%d\n", option);

		if ((option != 1) && (option !=2))
			printf("잘못 입력하셨습니다.\n");
	} while (option != 1 && option != 2);

	printf("문자열을 입력하시오: ");
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
	printf("암호화된 문자열:%s \n", cipher);
}