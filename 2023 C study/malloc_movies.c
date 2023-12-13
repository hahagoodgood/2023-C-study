#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

typedef struct movie {
	char title[100]; //영화제목
	double rating;     //평점
} MOVIE;

void add_record(FILE* mfp, MOVIE* movies, int size);
void print_record(FILE* mfp);

int main(void) {
	FILE* mfp;
	MOVIE* movies; // 영화 포인터
	int size, i;
	int a;

	mfp = fopen("movies.txt", "a+");

	print_record(mfp);

	printf("몇 편이나 저장하시겠습니까?");
	scanf("%d", &size);
	getchar(); //엔터 제거

	movies = (MOVIE*)malloc(sizeof(MOVIE) * size);
	if (movies == NULL) {
		printf("동적 메모리 할당 오류");
		exit(1);
	}

	for (i = 0; i < size; i++) {
		printf("영화 제목:");
		gets_s(movies[i].title, 100);
		printf("영화 평점:");
		scanf("%lf", &(movies[i].rating));
		getchar();// 엔터 제거
	}

	add_record(mfp, movies, size);

	printf("메모리 데이터\n");
	printf("================================================\n");
	printf("제목  평점\n");
	printf("================================================\n");

	for (i = 0; i < size; i++)
		printf("%s \t %f\n", movies[i].title, movies[i].rating);
	printf("\n================================================\n");
	free(movies); //해결 잘못된 데이터형식으로 입력시 오류
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

	printf("파일 데이터\n");
	printf("================================================\n");
	printf("제목  평점\n");
	printf("================================================\n");

	while (!feof(mfp)) {
		if (fread(&buffer, sizeof(MOVIE), 1, mfp) == 0)
			break;
		printf("%s\t%f\n", buffer.title, buffer.rating);
	}
	printf("================================================\n");
}