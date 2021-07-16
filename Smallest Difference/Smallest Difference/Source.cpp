#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 1e4 + 5;

int main() {
	int t, a, n, arr[N] = {}, mx;
	scanf_s("%d", &t);
	while (t--)
	{
		scanf_s("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf_s("%d", &a);
			arr[a]++;
		}
		mx = 0;
		for (int i = 0; i < 10001; i++)
			if (arr[i] + arr[i + 1] > mx)
				mx = arr[i] + arr[i + 1];
			printf("%d\n", mx);
		fill(arr, arr + N, 0);
	}
	return 0;
}