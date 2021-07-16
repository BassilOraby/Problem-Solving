#include <iostream>
#include <algorithm>
using namespace std;
const int Q = 1e4 + 5;
int K, N, M, A[Q], B[Q],mem[Q][Q],op1,op2;

int WB(int i, int w) {
	if (i == M) return 0;
	if (mem[i][w] != -1) return mem[i][w];
	op1 = WB(i + 1, w);
	op2 = A[i] <= w ? B[i] + WB(i + 1, w - A[i]) : 0;
	return mem[i][w] = max(op1, op2);
}

int main() {
	scanf_s("%d", &N);
	while (N--)
	{
		scanf_s("%d %d", &K, &M);
		for (int i = 0; i < M; i++)
			scanf_s("%d %d", A + i, B + i);
		memset(mem, -1, sizeof mem);
		printf("Hey stupid robber, you can get %d.\n", WB(0, K));
	}
	system("pause");
	return 0;
}