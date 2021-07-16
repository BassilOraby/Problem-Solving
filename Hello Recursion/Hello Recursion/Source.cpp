#include <iostream>
#include <cstdio>
using namespace std;

int solve(int arr[], int sz) {
	if (sz == 0)
		return arr[sz];
	else
		return arr[sz] + solve(arr, sz - 1);
}

int main() {
	int T, N, a[2001] = {}, sum[101] = {}, count = 0,t;
	scanf_s("%d", &T);
	t = T;
	while (T--) {
		scanf_s("%d", &N);
		for (int i = 0; i < N; i++)
			cin >> a[i];
		sum[count] = solve(a, N);
		count++;
		for (int i = 0; i < N; i++)
			a[i] = 0;
	}
	for (int k = 1; k <= t; k++)
		printf("Case %d: %d\n", k, sum[k - 1]);
	system("pause");
	return 0;
}