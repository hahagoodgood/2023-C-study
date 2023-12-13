#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

static int n[4];
double func(double x)
{
	return n[0] * x * x * x + n[1] * x * x + n[2] * x + n[3];
}

void bisection(double (*fp)(double), double a, double b)
{
	if (fp(a) * fp(b) >= 0)
	{
		printf("적절한 a와 b가 아님\n");
		return 0;
	}

	double c;
	while ((b - a) >= EPSILON)
	{
		c = (a + b) / 2;
		if (fp(c) * fp(a) < 0) {
			b = c;
		}
		else
			a = c;
	}
	printf(" %dX^3+%dX^2+%dX+%d의 최종 근 = %lf\n", n[0], n[1], n[2], n[3], c);
}

int main(void)
{
	double a = -200, b = 200;
	printf("3차방정식의 각각의 계수를 순서대로 입력하시오:");
	scanf("%d %d %d %d", &n[0], &n[1], &n[2], &n[3]);
	bisection(func, a, b);
	return 0;
}