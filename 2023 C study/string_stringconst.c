#include <stdio.h>

int main(void)
{
	char* p = "hahahoho";
	p = "gagagogo";
	printf("%s\n", p);
	printf("%d\n", p); 
	printf("%d\n", &p);


	return 0;
}