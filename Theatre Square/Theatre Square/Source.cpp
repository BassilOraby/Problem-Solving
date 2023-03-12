#include <stdio.h>
#include <iostream>
using namespace std;

long long ceilValue(long long a, long long b) {
	long long ret = a / b;
	if (a%b) ++ret;
	return ret;
}

int main() {
	int n, m, a;
	scanf_s("%d %d %d", &n, &m, &a);
	printf("%d\n", (int)(ceil(n/(double)a)*ceil(m/(double)a)));
	system("pause");
	return 0;
}


