#include <stdio.h>;

struct point
{
	int x, y;
};

struct rect
{
	struct point p1, p2;
};

int main(void)
{
	struct rect r;
	int w, h, area, peri;

	printf("Please enter the coordinates at the top left: ");
	scanf("%d %d", &r.p1.x, &r.p1.y);

	printf("please enter the coordinates at the bottom right: ");
	scanf("%d %d", &r.p2.x, &r.p2.y);

	w = r.p2.x - r.p1.x;
	h = r.p2.y - r.p1.y;

	area = w * h;

	peri = 2 * w + 2 * h;
	printf("Area is %d and Perimaeter is %d", area, peri);

	return 0;
}