#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
const int N = 1e5 + 5;

int main() {
	string s;
	int l, r, m, count = 0, pre[N] = {};
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == s[i + 1])
			pre[i + 1] = pre[i] + 1;
		else
			pre[i + 1] = pre[i];
	}
	scanf_s("%d", &m);
	while (m--)
	{
		scanf_s("%d %d", &l, &r);
		l -= 1;
		r -= 1;
		printf("%d\n", pre[r] - pre[l]);
	}
	return 0;
}