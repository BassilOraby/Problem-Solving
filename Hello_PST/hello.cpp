#include <stdio.h>
#include <cstring>
#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	deque <int> dq;
	int s = 0, T, n;
	char str[51];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", &str);
		n = strlen(str);
		for (size_t i = 0; i < n; i++)
			s += str[i] - '0';
		dq.push_back(s);
		s = 0;
	}
	for (size_t i = 0; i < dq.size(); i++)
		printf("%d\n", dq[i]);
	return 0;
}
