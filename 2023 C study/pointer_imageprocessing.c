#include <stdio.h>
#define SIZE 5

void print_image(int image[SIZE][SIZE])
{
	int r, c;
	for (r = 0; r < SIZE; r++) {
		for (c = 0; c < SIZE; c++) {
			printf("%03d ", image[r][c]);
		}
		printf("\n");
	}
	printf("\n");
}

void brighten_image(int image[SIZE][SIZE])
{
	int r, c;
	int* p;
	p = &image[0][0];
	for (r = 0; r < SIZE; r++) {
		for (c = 0; c < SIZE; c++) {
			//*p += 10;
			//p++;
			image[r][c] += 10;
		}
	}
}

int main(void)
{
	int image[SIZE][SIZE] = {
		{10,20,30,40,50},
		{10,20,30,40,50},
		{10,20,30,40,50},
		{10,20,30,40,50},
		{10,20,30,40,50}
	};

	print_image(image);
	brighten_image(image);
	print_image(image);

	return 0;
}