#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct person {
	char name[SIZE];
	char address[SIZE];
	char mobilephone[SIZE];
	char desc[SIZE];
} PERSON;

void menu();
PERSON get_record(); //학생 정보 얻기
void print_record(PERSON data); //학생정보 1명 출력
void add_record(FILE* fp); //학생정보 추가
void search_record(FILE* fp); //데이터 탐색
void update_record(FILE* fp); //데이터 업데이트

int main(void)
{
	FILE* fp;
	int select;
	if ((fp = fopen("address.dat", "a+")) == NULL)
	{
		fprintf(stderr, "입력을 위한 파일을 열 수 없습니다.");
		exit(1);
	}
	while (1) {
		menu();
		printf("정수값을 입력하시오: ");
		scanf("%d", &select);
		switch (select) {
		case 1: add_record(fp); break;
		case 2: update_record(fp); break;
		case 3: search_record(fp); break;
		case 4: return 0;
		}
	}
	fclose(fp);
	return 0;
}

PERSON get_record() {
	PERSON data;

	getchar();
	printf("이름: ");
	gets_s(data.name, SIZE);
	printf("주소: ");
	gets_s(data.address, SIZE);
	printf("휴대폰: ");
	gets_s(data.mobilephone, SIZE);
	printf("특징: ");
	gets_s(data.desc, SIZE);
	return data;
}

void print_record(PERSON data)
{
	printf("이름: %s\n", data.name);
	printf("주소: %s\n", data.address);
	printf("휴대폰: %s\n", data.mobilephone);
	printf("특징: %s\n", data.desc);
}

void menu() {
	printf("=====================\n");
	printf(" 1. 추가\n 2. 수정\n 3. 검색\n 4. 종료\n");
	printf("=====================\n");
}

void add_record(FILE* fp) { //학생추가
	PERSON data;
	data = get_record();
	fseek(fp, 0, SEEK_END);
	fwrite(&data, sizeof(data), 1, fp);
}

void search_record(FILE* fp) {
	char name[SIZE];
	PERSON data;
	int find = 0;

	fseek(fp, 0, SEEK_SET);
	getchar();
	printf("탐색하고자 하는 사람의 이름: ");
	gets_s(name, SIZE);
	while (!feof(fp)) {
		fread(&data, sizeof(data), 1, fp);
		if (strcmp(data.name, name) == 0) {
			find++;
			print_record(data);
			//break;
		}
	}
	// 도전 1
	if (find == 0)
		fprintf(stderr, "%s의 정보가 없습니다.\n", name);
}

//도전 2
void update_record(FILE* fp) {
	char name[SIZE];
	PERSON data;
	int find = 0;
	FILE* tfp; //tmpe
	if ((tfp =fopen("address_temp.dat", "w+")) == NULL)
	{
		fprintf(stderr, "복사를 위한 파일을 열 수 없습니다.");
		exit(1);
	}

	fseek(fp, 0, SEEK_SET);
	fseek(tfp, 0, SEEK_SET);
	getchar();
	printf("수정하고자 하는 사람의 이름: ");
	gets_s(name, SIZE);
	while (!feof(fp)) {
		fread(&data, sizeof(data), 1, fp);
		if (strcmp(data.name, name) == 0){
			find++;
			data = get_record();
		}
		fwrite(&data, sizeof(data), 1, tfp);//복사
	}
	fclose(fp);
	if (find == 0) {
		printf("%s을 찾을 수 없습니다.\n", name);
		return 0;
	}
	fp = fopen("address.dat", "w");
	fseek(tfp, 0, SEEK_SET);
	while (!feof(tfp)) {
		fread(&data, sizeof(data), 1, tfp);
		fwrite(&data, sizeof(data), 1, fp);
	}
	fclose(fp);
	fclose(tfp);
	fp = fopen("address.dat", "a+");
}