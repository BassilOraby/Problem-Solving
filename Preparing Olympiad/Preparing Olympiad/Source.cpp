#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int n, A[17], count=0;
	long long l, r, x,sum=0, hi = 0, lo = ULONG_MAX;
	scanf_s("%d %lld %lld %lld", &n, &l, &r, &x);
	for (int i = 0; i < n; i++)
		scanf_s("%lld", A + i);
	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < n; j++) {
			if (i & 1 << j) {
				sum += A[j];
				if (A[j] > hi) hi = A[j];
				if (A[j] < lo) lo = A[j];
			}
		}
		if (sum >= l && sum <= r && hi - lo >= x)
			count++;
		sum = 0;
		hi = 0;
		lo = ULONG_MAX;
	}
	printf("%d\n", count);
	return 0;
}