#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	long long x;
	scanf_s("%lld", &x);
	(x & 1) && (x != 1) ? printf("%d\n", 2) : printf("%d\n", 1);
	return 0;
}