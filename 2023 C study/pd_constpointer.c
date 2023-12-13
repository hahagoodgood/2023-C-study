#include <stdio.h>
int main(void)
{
	char s[] = "Barking dogs seldom bite.";
	char t[] = "a bad workman blames his tools";
	const char* p = s;
	char* const q = s;

	//p[3] ='a'; code E0137: 식이 수정할 수 있는 ㅣvalude여야 합니다.
	p = t;

	q[3] = 'a';
	//q = t; code E0137: 식이 수정할 수 있는 ㅣvalude여야 합니다.

	return 0;
}