#include <stdio.h>

int main(int argc, char* argv[])
{
	int i = 0;

	for (i = 0; i < argc; i++)
	{
		printf("���ɾ� �࿡�� %d��° ���ڿ� = %s\n", i, argv[i]);
	}

	return 0;
}