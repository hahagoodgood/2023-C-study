#include <stdio.h>

char* my_strtok(char* str, const char* delimiters)// str: 분할 할 문자열, delimiters: 구분자;
{
	static char* pCurrent;// str을 저장할 정적 변수(함수가 끝나도 메모리에 남아있다.
	char* pDelimit;
	if (str != NULL)pCurrent = str;
	else str = pCurrent; //strtok 첫번째 매게변수에 NULL을 입력하였을 때 이전 작업하였던 문자 입력;

	if (*pCurrent == NULL) return NULL;

	while (*pCurrent)
	{
		pDelimit = (char*)delimiters;
	printf("%s에서 %s를 기준으로 구분할 수 있는지 확인\n", pCurrent, pDelimit);

		while (*pDelimit) {
			if (*pCurrent == *pDelimit) {//문자열의 문자와 구분자가 같을때 
				*pCurrent = NULL; //문자열의 해당 문자 null로 표기;
				++pCurrent;
				return str;
			}
			++pDelimit;
		}
		++pCurrent;
	}
	// 더이상 자를 수 없어요;
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
		printf("토큰: %s\n", token);
		printf("문자열: %s\n", s);
		token = my_strtok(NULL, seps);
	}
	return 0;
}