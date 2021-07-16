#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int n,sum1=0,sum2=0,sum3=0,x1,x2,x3;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &x1);
		sum1 += x1;
	}
	for (size_t i = 0; i < n-1; i++)
	{
		scanf_s("%d", &x2);
		sum2 += x2;
	}
	for (size_t i = 0; i < n-2; i++)
	{
		scanf_s("%d", &x3);
		sum3 += x3;
	}
	printf("%d\n%d\n", sum1 - sum2, sum2 - sum3);
	return 0;
}