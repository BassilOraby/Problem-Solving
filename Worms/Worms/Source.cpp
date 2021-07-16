#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long cs[1000001], p[100001];

int main() {
	long long n, m, q;
	scanf_s("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf_s("%lld", p + i);
		cs[i] = cs[i - 1] + p[i];
	}
	scanf_s("%lld", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf_s("%lld", &q);
		printf("%lld\n", (long long)(binary_search(cs, cs+n, q) ? (upper_bound(cs, cs + n, q) - cs)-1:(upper_bound(cs, cs+n, q) - cs)));
	}
	return 0;
}