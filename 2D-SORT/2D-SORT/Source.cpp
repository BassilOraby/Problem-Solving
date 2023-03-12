#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5 + 5;
pair<int, int> A[N];

int main() {
	int t, n, x;
	scanf_s("%d", &t);
	while (t--)
	{
		scanf_s("%d", &n);
		x = n;
		while (x--)
		{
			scanf_s("%d %d", &A[x].first, &A[x].second);
			A[x].second *= -1;
		}
		sort(A, A + n);
		for (size_t i = 0; i < n; i++)
		{
			printf_s("%d %d\n", A[i].first, -1*(A[i].second));
		}
	}
	return 0;
}