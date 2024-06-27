#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int factor1(int n){
	int i, j;
	long sum1, sum2 = 0;
	for (i = 1;i <= n;i++)
	{
		sum1 = 1;
		for (j = 1;j <= i;j++)
			sum1= sum1*j;
		sum2 = sum1 + sum2;
	}
	printf("%d\n", sum2);
	return 0;
}

int factor2(int n) {
	int x ;
	long sum3 = 1, sum4 = 0;
	for (x = 1;x <= n;x++)
	{
		sum3 = sum3 * x;
		sum4 = sum3 + sum4;

	}
	return 0;

}
int main()
{
	int n;
	int b, e;
	printf("ÊäÈën:");
	scanf_s("%d", &n);
	b = clock();
	factor1(n);
	e = clock();
	printf("%dms\n", e - b);

	b = clock();
	factor2(n);
	e = clock();
	printf("%dms\n", e - b);
	return 0;
}
