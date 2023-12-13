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
PERSON get_record(); //�л� ���� ���
void print_record(PERSON data); //�л����� 1�� ���
void add_record(FILE* fp); //�л����� �߰�
void search_record(FILE* fp); //������ Ž��
void update_record(FILE* fp); //������ ������Ʈ

int main(void)
{
	FILE* fp;
	int select;
	if ((fp = fopen("address.dat", "a+")) == NULL)
	{
		fprintf(stderr, "�Է��� ���� ������ �� �� �����ϴ�.");
		exit(1);
	}
	while (1) {
		menu();
		printf("�������� �Է��Ͻÿ�: ");
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
	printf("�̸�: ");
	gets_s(data.name, SIZE);
	printf("�ּ�: ");
	gets_s(data.address, SIZE);
	printf("�޴���: ");
	gets_s(data.mobilephone, SIZE);
	printf("Ư¡: ");
	gets_s(data.desc, SIZE);
	return data;
}

void print_record(PERSON data)
{
	printf("�̸�: %s\n", data.name);
	printf("�ּ�: %s\n", data.address);
	printf("�޴���: %s\n", data.mobilephone);
	printf("Ư¡: %s\n", data.desc);
}

void menu() {
	printf("=====================\n");
	printf(" 1. �߰�\n 2. ����\n 3. �˻�\n 4. ����\n");
	printf("=====================\n");
}

void add_record(FILE* fp) { //�л��߰�
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
	printf("Ž���ϰ��� �ϴ� ����� �̸�: ");
	gets_s(name, SIZE);
	while (!feof(fp)) {
		fread(&data, sizeof(data), 1, fp);
		if (strcmp(data.name, name) == 0) {
			find++;
			print_record(data);
			//break;
		}
	}
	// ���� 1
	if (find == 0)
		fprintf(stderr, "%s�� ������ �����ϴ�.\n", name);
}

//���� 2
void update_record(FILE* fp) {
	char name[SIZE];
	PERSON data;
	int find = 0;
	FILE* tfp; //tmpe
	if ((tfp =fopen("address_temp.dat", "w+")) == NULL)
	{
		fprintf(stderr, "���縦 ���� ������ �� �� �����ϴ�.");
		exit(1);
	}

	fseek(fp, 0, SEEK_SET);
	fseek(tfp, 0, SEEK_SET);
	getchar();
	printf("�����ϰ��� �ϴ� ����� �̸�: ");
	gets_s(name, SIZE);
	while (!feof(fp)) {
		fread(&data, sizeof(data), 1, fp);
		if (strcmp(data.name, name) == 0){
			find++;
			data = get_record();
		}
		fwrite(&data, sizeof(data), 1, tfp);//����
	}
	fclose(fp);
	if (find == 0) {
		printf("%s�� ã�� �� �����ϴ�.\n", name);
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