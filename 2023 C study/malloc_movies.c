#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

typedef struct movie {
	char title[100]; //��ȭ����
	double rating;     //����
} MOVIE;

void add_record(FILE* mfp, MOVIE* movies, int size);
void print_record(FILE* mfp);

int main(void) {
	FILE* mfp;
	MOVIE* movies; // ��ȭ ������
	int size, i;
	int a;

	mfp = fopen("movies.txt", "a+");

	print_record(mfp);

	printf("�� ���̳� �����Ͻðڽ��ϱ�?");
	scanf("%d", &size);
	getchar(); //���� ����

	movies = (MOVIE*)malloc(sizeof(MOVIE) * size);
	if (movies == NULL) {
		printf("���� �޸� �Ҵ� ����");
		exit(1);
	}

	for (i = 0; i < size; i++) {
		printf("��ȭ ����:");
		gets_s(movies[i].title, 100);
		printf("��ȭ ����:");
		scanf("%lf", &(movies[i].rating));
		getchar();// ���� ����
	}

	add_record(mfp, movies, size);

	printf("�޸� ������\n");
	printf("================================================\n");
	printf("����  ����\n");
	printf("================================================\n");

	for (i = 0; i < size; i++)
		printf("%s \t %f\n", movies[i].title, movies[i].rating);
	printf("\n================================================\n");
	free(movies); //�ذ� �߸��� �������������� �Է½� ����
	return 0;
}

void add_record(FILE* mfp, MOVIE* movies, int size) {
	fseek(mfp, 0, SEEK_END);
	for (int i = 0; i < size; i++) {
		fwrite(movies+i, sizeof(MOVIE), 1, mfp);
	}
}

void print_record(FILE* mfp) {
	MOVIE buffer;
	fseek(mfp, 0, SEEK_SET);

	printf("���� ������\n");
	printf("================================================\n");
	printf("����  ����\n");
	printf("================================================\n");

	while (!feof(mfp)) {
		if (fread(&buffer, sizeof(MOVIE), 1, mfp) == 0)
			break;
		printf("%s\t%f\n", buffer.title, buffer.rating);
	}
	printf("================================================\n");
}