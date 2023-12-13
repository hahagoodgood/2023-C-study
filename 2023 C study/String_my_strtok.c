#include <stdio.h>

char* my_strtok(char* str, const char* delimiters)// str: ���� �� ���ڿ�, delimiters: ������;
{
	static char* pCurrent;// str�� ������ ���� ����(�Լ��� ������ �޸𸮿� �����ִ�.
	char* pDelimit;
	if (str != NULL)pCurrent = str;
	else str = pCurrent; //strtok ù��° �ŰԺ����� NULL�� �Է��Ͽ��� �� ���� �۾��Ͽ��� ���� �Է�;

	if (*pCurrent == NULL) return NULL;

	while (*pCurrent)
	{
		pDelimit = (char*)delimiters;
	printf("%s���� %s�� �������� ������ �� �ִ��� Ȯ��\n", pCurrent, pDelimit);

		while (*pDelimit) {
			if (*pCurrent == *pDelimit) {//���ڿ��� ���ڿ� �����ڰ� ������ 
				*pCurrent = NULL; //���ڿ��� �ش� ���� null�� ǥ��;
				++pCurrent;
				return str;
			}
			++pDelimit;
		}
		++pCurrent;
	}
	// ���̻� �ڸ� �� �����;
	return str;
}

char s[] = "Man is immortal, because he has a soul";
char seps[] = " ,\t\n";
char* token;

int main(void)
{
	token = my_strtok(s, seps);

	while (token != NULL)
	{
		printf("��ū: %s\n", token);
		printf("���ڿ�: %s\n", s);
		token = my_strtok(NULL, seps);
	}
	return 0;
}