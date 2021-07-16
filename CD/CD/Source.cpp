#include <iostream>
#include <stdio.h>
#include <deque>
using namespace std;

int main() {
	int N, t, len[22] = {}, sum,Final=0;
	deque <int> dq,dq1;
	scanf_s("%d", &N);
	scanf_s("%d", &t);
	for (int i = 0; i < t; i++)
		scanf_s("%d", len + i);
	for (int i = 0; i < (1<<t); i++)
	{
		sum = 0;
		for (int j = 0; j < t; j++)
			if (i & 1 << j) 
			{ sum += len[j]; 
			dq.push_back(len[j]);
			}
		if (sum > Final && sum <= N) {
			Final = sum;
			dq1 = dq;
		}
		dq.clear();
	}
	for (int k = 0; k < dq1.size(); k++)
		printf("%d ", dq1[k]);
	printf("sum:%d\n", Final);
	system("pause");
	return 0;
}