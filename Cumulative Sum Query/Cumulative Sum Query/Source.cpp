#include <iostream>
#include <stdio.h>

using namespace std;

const int N = 1e5 + 5, M = 2e4, OO = 0x3f3f3f3f;

int n, A[N], pre[N];

int main() {
	cout << log(-2) << endl;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf_s("%d", A + i);
		pre[i] = pre[i - 1] + A[i];
	}
	int q;
	scanf_s("%d", &q);
	// while(q--){
	//     int p/*, sum = 0*/;
	//     scanf("%d", &p);
	//     // for(int i = 1 ; i <= p ; ++i)   sum += A[i];
	//     printf("%d\n", pre[p]);
	// }
	int l, r;
	while (q--) {
		scanf_s("%d %d", &l, &r);
		printf("%d\n", pre[r] - pre[l - 1]);
	}
	return 0;
}