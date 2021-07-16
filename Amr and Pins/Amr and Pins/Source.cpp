#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	long long x1, y1, x2, y2, r;
	scanf_s("%lld %lld %lld %lld %lld", &r, &x1, &y1, &x2, &y2);
	printf("%lld\n", (long long)ceil(sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)) / (2 * r)));
	system("pause");
	return 0;
}